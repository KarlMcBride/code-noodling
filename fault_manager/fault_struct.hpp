#ifndef __FAULT_STRUCT_HPP
#define __FAULT_STRUCT_HPP

#include <string>

struct event_t
{
    std::string event_string;
    int time_stamp;

    event_t(int _time_stamp, std::string _event_string)
    {
        time_stamp = _time_stamp;
        event_string = _event_string;
    }

    void print(void)
    {
        std::cout << time_stamp << " : " << event_string << std::endl;
    }

    bool operator<(const event_t& rhs_struct) const
    {
       return (time_stamp < rhs_struct.time_stamp);
    }

    bool operator>(const event_t& rhs_struct) const
    {
       return (rhs_struct.time_stamp < time_stamp);
    }

    bool operator==(const event_t& rhs_struct) const
    {
       return (time_stamp == rhs_struct.time_stamp);
    }
};


#endif // __FAULT_STRUCT_HPP