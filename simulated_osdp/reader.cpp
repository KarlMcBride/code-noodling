#include <chrono>
#include <iostream>

#include "reader.hpp"

reader::reader(simulated_port* _sim_port)
{
    m_sim_port = _sim_port;
    m_thread = std::thread(&reader::read_loop, this);
}

reader::~reader()
{

}

void reader::join()
{
    m_thread.join();
}

void reader::read_loop()
{
    std::queue<int> inflight_data;

    bool sequence_start_found = false;
    bool lsb_packet_length_found = false;
    bool msb_packet_length_found = false;

    int calculated_packet_length = 0;
    int inflight_packet_length = 0;

    while (true)
    {
        int new_data = 0x00;

        while (m_sim_port->read_data(&new_data))
        {
            m_input_deque.push_back(new_data);
        }

        for (std::deque<int>::iterator data_iterator = m_input_deque.begin(); data_iterator != m_input_deque.end(); ++data_iterator)
        {
            int current_data = *data_iterator;

            //std::cout << "|" << *data_iterator;

            // Begin checking each data "byte" currently stored.
            // Once a start of message is found:
            //      - get LSB from next piece of data, add value to total length
            //      - get MSB from next piece of data, add value * 16 to total length
            //      - get device address from next piece of data
            //      - keep reading until we've processed enough "bytes", equal to LSB+MSB*16.

            // If we haven't found the start of message, discard anything that isn't 0x53.
            if (*data_iterator != 0x53 && !sequence_start_found)
            {
                //std::cout << "Discarding " << *data_iterator << std::endl;
                m_input_deque.pop_front();
            }
            // Check for start of message, and if we haven't already found one, begin processing.
            else if (*data_iterator == 0x53 && !sequence_start_found)
            {
                //std::cout << "Sequence started " << *data_iterator << std::endl;
                sequence_start_found = true;
                inflight_data.emplace(*data_iterator);
                m_input_deque.pop_front();
                ++inflight_packet_length;
            }
            else if (sequence_start_found)
            {
                if (!lsb_packet_length_found)
                {
                    lsb_packet_length_found = true;
                    calculated_packet_length = *data_iterator;
                    inflight_data.emplace(*data_iterator);
                    m_input_deque.pop_front();
                    ++inflight_packet_length;
                    //std::cout << "Got LSB: " << calculated_packet_length << std::endl;
                }
                else if (!msb_packet_length_found)
                {
                    msb_packet_length_found = true;
                    calculated_packet_length += *data_iterator * 16;
                    inflight_data.emplace(*data_iterator);
                    m_input_deque.pop_front();
                    ++inflight_packet_length;
                   // std::cout << "Got MSB (" << *data_iterator << "): " << calculated_packet_length << std::endl;
                }
                else if (inflight_packet_length < calculated_packet_length)
                {
                    inflight_data.emplace(*data_iterator);
                    m_input_deque.pop_front();
                    ++inflight_packet_length;
                    //std::cout << "Got data: " << *data_iterator << std::endl;
                }
                else
                {
                    //std::cout << "read full packet" << std::endl;

                    sequence_start_found = false;
                    lsb_packet_length_found = false;
                    msb_packet_length_found = false;

                    calculated_packet_length = 0;
                    inflight_packet_length = 0;

                    m_command_list.emplace(inflight_data);

                    while(!inflight_data.empty())
                    {
                        inflight_data.pop();
                    }
                    //std::cout << "Cleared inflight data";

                    break;
                }
            }
        }

        std::cout << std::endl;

        std::this_thread::sleep_for( std::chrono::milliseconds(1000));

        while(!m_command_list.empty())
        {
            std::cout << "command: ";
            auto command = m_command_list.front();
            m_command_list.pop();
            while (!command.empty())
            {
                auto data = command.front();
                std::cout << "|" << data;
                command.pop();
            }
            std::cout << "#" << std::endl;
        }
    }
}