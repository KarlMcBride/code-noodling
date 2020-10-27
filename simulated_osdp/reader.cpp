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
    std::deque<int> inflight_data;

    bool sequence_start_found = false;
    bool address_found = false;
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
            std::cout << "    " << current_data << std::endl;

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
                std::cout << "Discarding " << current_data << std::endl;
            }
            // Check for start of message, and if we haven't already found one, begin processing.
            else if (current_data == 0x53 && !sequence_start_found)
            {
                std::cout << "  Got sequence start: " << current_data << std::endl;
                sequence_start_found = true;
                inflight_data.push_back(current_data);
                ++inflight_packet_length;
            }
            // Handle new data if a sequence is underway.
            else if (sequence_start_found)
            {
                // First byte after start of message is address.
                if (!address_found)
                {
                    address_found = true;
                    inflight_data.push_back(current_data);
                    ++inflight_packet_length;
                     std::cout << "  Got Add: " << current_data << std::endl;
                }
                // Second byte after start of message is LSB byte of packet length.
                // Add its value to the calculated data length, and set the lsb flag to true so
                // we don't iterpret another byte as an LSB length value.
                else if (!lsb_packet_length_found)
                {
                    lsb_packet_length_found = true;
                    calculated_packet_length = current_data;
                    inflight_data.push_back(current_data);
                    ++inflight_packet_length;
                    std::cout << "  Got LSB: " << calculated_packet_length << std::endl;
                }
                // Third byte after start of message is MSB byte of packet length.
                // Handle in the same way as with LSB, except multiply its value by 16,
                // as its the most significant byte.
                else if (!msb_packet_length_found)
                {
                    msb_packet_length_found = true;
                    calculated_packet_length += current_data * 16;
                    inflight_data.push_back(current_data);
                    ++inflight_packet_length;
                    std::cout << "  Got MSB: " << current_data << " updated to: " << calculated_packet_length << std::endl;
                }
                else if (inflight_packet_length < calculated_packet_length)
                {
                    inflight_data.push_back(current_data);
                    ++inflight_packet_length;
                    std::cout << "  Got data: " << current_data << std::endl;
                }
                else
                {
                    std::cout << "read full packet: ";

                    // Check if checksum/CRC matches. If so, process the valid message and pop those bytes off the input deque.
                    // If not, signal to find the next 0x53 and pop off the first sequence with 0x53.
                    // Replace hardcoded 0xAA and 0xEB with CRC generated values. These are pulled from
                    // "actual_osdp_poll_data_with_almost_acceptable_erroneous_data".
                    std::cout << "  data: ";
                    for (int index = 0; index < calculated_packet_length; index++)
                    {
                        std::cout << "|" << inflight_data[index];
                    }
                    std::cout << "|" << std::endl;

                    int lsb_crc = inflight_data[calculated_packet_length - 2];
                    int msb_crc = inflight_data[calculated_packet_length - 1];
                    int expected_lsb_crc = 0xAA;
                    int expected_msb_crc = 0xEB;
                    std::cout << "calculated_packet_length: " << calculated_packet_length << std::endl;
                    std::cout << "crcs: " << lsb_crc << "/" << expected_lsb_crc << " : " << msb_crc << "/" << expected_msb_crc << std::endl;

                    // TODO: replace with actual calculated CRC values
                    //if (lsb_crc == 170 && msb_crc == 235)
                    if (lsb_crc == 0xAA && msb_crc == 0xEB)
                    {
                        // Inflight data CRC matches that of the calculated checksum, so process it and take action.
                        // Discard retrieved packet data from deque.
                        for (int index = 0; index < inflight_packet_length; index++)
                        {
                            m_input_deque.pop_front();
                        }

                        m_command_list.emplace(inflight_data);
                    }
                    else
                    {
                        std::cout << "  CRC mismatch data: ";
                        for (int index = 0; index < calculated_packet_length; index++)
                        {
                            std::cout << "|" << inflight_data[index];
                        }
                        std::cout << "|" << std::endl;

                        // Inflight data CRC doesn't match that of the calculated checksum, so find the next 0x53 and
                        // discard data up to that point. Start at index 1 since 0 will contain 0x53 at this point.
                        int next_sequence_start = 0;
                        for (int index = 1; index < inflight_packet_length; index++)
                        {
                            if (inflight_data[index] == 0x53)
                            {
                                std::cout << "  next sequence start found @ index " << index << std::endl;
                                next_sequence_start = index;
                                break;
                            }
                        }

                        for (int index = 0; index < next_sequence_start; index++)
                        {
                            m_input_deque.pop_front();
                        }

                        std::this_thread::sleep_for( std::chrono::milliseconds(5000));
                    }

                    sequence_start_found = false;
                    address_found = false;
                    lsb_packet_length_found = false;
                    msb_packet_length_found = false;

                    calculated_packet_length = 0;
                    inflight_packet_length = 0;

                    // Since we've added the new complete inflight data packet to the command list,
                    // clear it down.
                    //while(!inflight_data.empty())
                    //{
                    //    inflight_data.pop();
                    //}
                    //std::cout << "Cleared inflight data";

                    break;
                }
            }

            if (!true)
            {
                std::cout << "  debug data EOL: ";
                for (int index = 0; index < calculated_packet_length; index++)
                {
                    std::cout << "|" << inflight_data[index];
                }
                std::cout << "|" << std::endl;
            }
        }

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

        std::this_thread::sleep_for( std::chrono::milliseconds(250));
    }
}