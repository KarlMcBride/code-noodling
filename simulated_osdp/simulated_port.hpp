#ifndef __SIMULATED_PORT_HPP
#define __SIMULATED_PORT_HPP

#include <queue>
#include <string>

class simulated_port
{
    public:
        simulated_port();
        ~simulated_port();

        bool read_data(int* _new_data);
        void write_data(int _new_data);

    private:
        std::queue<int> m_read_write_queue;   // Shared queue that read and write processes use to transfer data.
};

#endif // __SIMULATED_PORT_HPP