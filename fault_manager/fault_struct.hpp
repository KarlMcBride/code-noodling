#ifndef __FAULT_STRUCT_HPP
#define __FAULT_STRUCT_HPP

#include <string>

struct fault_event_t
{
    int time_stamp;
    std::string event_string;

    fault_event_t(int _time_stamp, std::string _event_string)
    {
        time_stamp = _time_stamp;
        event_string = _event_string;
    }

    void print(void)
    {
        std::cout << time_stamp << " : " << event_string << std::endl;
    }

    bool operator<(const fault_event_t& rhs_struct) const
    {
       return (time_stamp < rhs_struct.time_stamp);
    }

    bool operator>(const fault_event_t& rhs_struct) const
    {
       return (rhs_struct.time_stamp < time_stamp);
    }

    bool operator==(const fault_event_t& rhs_struct) const
    {
       return (time_stamp == rhs_struct.time_stamp);
    }
};


#endif // __FAULT_STRUCT_HPP