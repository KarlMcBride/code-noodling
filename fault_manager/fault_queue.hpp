#ifndef __FAULT_STORE_HPP
#define __FAULT_STORE_HPP

#include <string>

class fault_queue
{
    public:
        fault_queue();
        //~fault_queue();

        void add_event(int _time_stamp, std::string _fault_message);
        void add_event(std::string _time_stamp, std::string _fault_message);
        int  get_queue_length();
        void print_buffer();
        void read_buffer();
        void write_buffer();

    private:
        bool new_events_to_save;
};


#endif // __FAULT_STORE_HPP