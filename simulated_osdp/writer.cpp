#include <chrono>
#include <iostream>

#include "writer.hpp"

writer::writer(simulated_port* _sim_port)
{
    m_sim_port = _sim_port;
    m_thread = std::thread(&writer::write_loop, this);
}

writer::~writer()
{

}

void writer::join()
{
    m_thread.join();
}

void writer::write_loop()
{
    int sample_data[]
    {
        // Core components.
        0x53,   // Start of message (SoM).
        0x09,   // LSB byte of complete package length.
        0x00,   // MSB byte of complete package length.
        0x00,   // Device address, 0x00-0xfe, 0xff = configuration mode that all devices should act upon.

        // Optional encryption and commands go below.
        0x01,
        0x02,
        0x03,
        0x04,

        // CRC/checksum below - currently a sum of the previous data.
        0x65
    };

    int sample_data_longer[]
    {
        // Pre-message trash data
        0xEE,
        0xEF,
        0xED,

        // Core components.
        0x53,   // Start of message (SoM).
        0x10,   // LSB byte of complete package length.
        0x00,   // MSB byte of complete package length.
        0x00,   // Device address, 0x00-0xfe, 0xff = configuration mode that all devices should act upon.

        // Optional encryption and commands go below.
        0x01,
        0x02,
        0x03,
        0x04,
        0x05,
        0x06,
        0x07,
        0x08,
        0x09,
        0x0A,
        0x0B,

        // CRC/checksum below - currently a random value.
        0xDD,

        // Trash data
        0xFE,
        0xFF,
        0xFD
    };

    while (true)
    {
        for (auto data : sample_data)
        {
            m_sim_port->write_data(data);
        }

        for (auto data : sample_data_longer)
        {
            m_sim_port->write_data(data);
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}