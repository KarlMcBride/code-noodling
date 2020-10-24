#include <iostream>

#include "simulated_port.hpp"

simulated_port::simulated_port()
{

}

simulated_port::~simulated_port()
{

}

// Attempts to read a single byte of data from the shared read-write queue.
// Returns true if enough data is available, otherwise false.
bool simulated_port::read_data(int* _new_data)
{
    if (m_read_write_queue.size() <= 1)
    {
        return false;
    }

    // Get the first/oldest data from the queue, and pop it off.
    *_new_data = m_read_write_queue.front();
    m_read_write_queue.pop();

    return true;
}

void simulated_port::write_data(int _new_data)
{
    m_read_write_queue.emplace(_new_data);
}
