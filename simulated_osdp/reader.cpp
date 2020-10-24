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

            //std::cout << "|" << current_data;

            // Begin checking each data "byte" currently stored.
            // If a message sequence isn't underway, discard data.
            // If a start of message is found:
            //      - get LSB from next piece of data, add value to total length
            //      - get MSB from next piece of data, add value * 16 to total length
            //      - get device address from next piece of data
            //      - keep reading until we've processed enough "bytes", equal to LSB+MSB*16.
            // Once inflight packet length matches calculated packet length, add inflight packet to
            // command list and inflight packet and all flags.

            // If we haven't found the start of message, discard anything that isn't 0x53.
            if (current_data != 0x53 && !sequence_start_found)
            {
                //std::cout << "Discarding " << current_data << std::endl;
                m_input_deque.pop_front();
            }
            // Check for start of message, and if we haven't already found one, begin processing.
            else if (current_data == 0x53 && !sequence_start_found)
            {
                //std::cout << "Sequence started " << current_data << std::endl;
                sequence_start_found = true;
                inflight_data.emplace(current_data);
                m_input_deque.pop_front();
                ++inflight_packet_length;
            }
            // Handle new data if a sequence is underway.
            else if (sequence_start_found)
            {
                // First byte after start of message is LSB byte of packet length.
                // Add its value to the calculated data length, and set the lsb flag to true so
                // we don't iterpret another byte as an LSB length value.
                if (!lsb_packet_length_found)
                {
                    lsb_packet_length_found = true;
                    calculated_packet_length = current_data;
                    inflight_data.emplace(current_data);
                    m_input_deque.pop_front();
                    ++inflight_packet_length;
                    //std::cout << "Got LSB: " << calculated_packet_length << std::endl;
                }
                // Second byte after start of message is MSB byte of packet length.
                // Handle in the same way as with LSB, except multiply its value by 16,
                // as its the most significant byte.
                else if (!msb_packet_length_found)
                {
                    msb_packet_length_found = true;
                    calculated_packet_length += current_data * 16;
                    inflight_data.emplace(current_data);
                    m_input_deque.pop_front();
                    ++inflight_packet_length;
                   // std::cout << "Got MSB (" << current_data << "): " << calculated_packet_length << std::endl;
                }
                else if (inflight_packet_length < calculated_packet_length)
                {
                    inflight_data.emplace(current_data);
                    m_input_deque.pop_front();
                    ++inflight_packet_length;
                    //std::cout << "Got data: " << current_data << std::endl;
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

                    // Since we've added the new complete inflight data packet to the command list,
                    // clear it down.
                    while(!inflight_data.empty())
                    {
                        inflight_data.pop();
                    }
                    //std::cout << "Cleared inflight data";

                    break;
                }
            }
        }

        std::this_thread::sleep_for( std::chrono::milliseconds(1));

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