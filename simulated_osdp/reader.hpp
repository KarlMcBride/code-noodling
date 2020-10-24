#ifndef __READER_HPP
#define __READER_HPP

#include <thread>

#include "simulated_port.hpp"

class reader
{
    public:
        reader(simulated_port* _sim_port);
        ~reader();
        void join();

    private:
        void read_loop();

        simulated_port* m_sim_port;
        std::thread     m_thread;
};

#endif // __READER_HPP