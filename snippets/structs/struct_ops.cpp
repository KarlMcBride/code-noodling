#include <iostream>
#include <string>

using namespace std;

struct event_t
{
    int time_stamp;
    string event_string;

    event_t(int _time_stamp, string _event_string)
    {
        time_stamp = _time_stamp;
        event_string = _event_string;

        print();
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

int main()
{
    event_t event_1 = {1, "First event"};
    event_t event_2 = {2, "Second event"};
    event_t event_1a = {1, "Dupe first event"};


    cout << "event_1 < event_2: " << (event_1 < event_2) << std::endl;
    cout << "event_2 < event_1: " << (event_2 < event_1) << std::endl;

    cout << "event_1 > event_2: " << (event_1 > event_2) << std::endl;
    cout << "event_2 > event_1: " << (event_2 > event_1) << std::endl;

    cout << "event_1 == event_2: " << (event_1 == event_2) << std::endl;
    cout << "event_1 == event_1a: " << (event_1 == event_1a) << std::endl;
}
