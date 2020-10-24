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
    while (true)
    {
        int new_data = 0x00;
        if (m_sim_port->read_data(&new_data))
        {
            std::cout << __FUNCTION__ << " : read " << new_data << std::endl;
            m_input_deque.push_back(new_data);
        }

        std::this_thread::sleep_for( std::chrono::milliseconds(10));

        for (std::deque<int>::iterator data_iterator = m_input_deque.begin(); data_iterator != m_input_deque.end(); ++data_iterator)
        {
            std::cout << "|" << *data_iterator;
        }

        std::cout << std::endl;
    }
}