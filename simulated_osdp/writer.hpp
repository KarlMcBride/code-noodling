#ifndef __WRITER_HPP
#define __WRITER_HPP

#include <thread>

#include "simulated_port.hpp"

class writer
{
    public:
        writer(simulated_port* _sim_port);
        ~writer();
        void join();

    private:
        void write_loop();

        simulated_port* m_sim_port;
        std::thread     m_thread;
};

#endif // __WRITER_HPP