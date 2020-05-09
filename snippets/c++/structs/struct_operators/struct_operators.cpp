#include <iostream>
#include <string>

using namespace std;

struct struct_operators_t
{
    int time_stamp;
    string event_string;

    struct_operators_t(int _time_stamp, string _event_string)
    {
        time_stamp = _time_stamp;
        event_string = _event_string;

        print();
    }

    void print(void)
    {
        std::cout << time_stamp << " : " << event_string << std::endl;
    }

    bool operator<(const struct_operators_t& rhs_struct) const
    {
       return (time_stamp < rhs_struct.time_stamp);
    }

    bool operator>(const struct_operators_t& rhs_struct) const
    {
       return (rhs_struct.time_stamp < time_stamp);
    }

    bool operator==(const struct_operators_t& rhs_struct) const
    {
       return (time_stamp == rhs_struct.time_stamp);
    }
};

int main()
{
    struct_operators_t event_1 = {1, "First event"};
    struct_operators_t event_2 = {2, "Second event"};
    struct_operators_t event_1a = {1, "Dupe first event"};


    cout << "event_1 < event_2: " << (event_1 < event_2) << std::endl;
    cout << "event_2 < event_1: " << (event_2 < event_1) << std::endl;

    cout << "event_1 > event_2: " << (event_1 > event_2) << std::endl;
    cout << "event_2 > event_1: " << (event_2 > event_1) << std::endl;

    cout << "event_1 == event_2: " << (event_1 == event_2) << std::endl;
    cout << "event_1 == event_1a: " << (event_1 == event_1a) << std::endl;
}
