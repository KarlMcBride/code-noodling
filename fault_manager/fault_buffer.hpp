#ifndef __FAULT_STORE_HPP
#define __FAULT_STORE_HPP

#include <string>

class fault_buffer
{
    public:
        fault_buffer();
        ~fault_buffer();

        void add_event(int _time_stamp, std::string _fault_message);
        int get_queue_length();
        void print_buffer();
        void read_buffer();
        void write_buffer();
};


#endif // __FAULT_STORE_HPP