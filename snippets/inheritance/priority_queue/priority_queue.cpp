#include <iostream>
#include <string>

#include <queue>
#include <iostream>

// Pass queue by value so that original queue isn't modified
template<typename T> void print_queue(T q)
{
    std::cout << "Queue size: " << q.size() << std::endl;
    while(!q.empty())
    {
        std::cout << q.top().time_stamp << " : " << q.top().event_string << std::endl;
        q.pop();
    }
    std::cout << '\n';
}

using namespace std;

struct inheritance_priority_queue_struct_t
{
    string event_string;
    int time_stamp;

    inheritance_priority_queue_struct_t(int _time_stamp, string _event_string)
    {
        time_stamp = _time_stamp;
        event_string = _event_string;
    }

    void print(void)
    {
        std::cout << time_stamp << " : " << event_string << std::endl;
    }

    bool operator<(const inheritance_priority_queue_struct_t& rhs_struct) const
    {
       return (time_stamp < rhs_struct.time_stamp);
    }

    bool operator>(const inheritance_priority_queue_struct_t& rhs_struct) const
    {
       return (rhs_struct.time_stamp < time_stamp);
    }

    bool operator==(const inheritance_priority_queue_struct_t& rhs_struct) const
    {
       return (time_stamp == rhs_struct.time_stamp);
    }
};

int main()
{
    auto sortRuleLambda = [] (inheritance_priority_queue_struct_t const& s1, inheritance_priority_queue_struct_t const& s2) -> bool
    {
       return s1.time_stamp > s2.time_stamp;
    };

    std::priority_queue<inheritance_priority_queue_struct_t, std::vector<inheritance_priority_queue_struct_t>, decltype(sortRuleLambda)> q1(sortRuleLambda);

    for(int n = 0; n < 3; n++)
    {
        int rand_num = rand() % 10000 + 1;
        string temp_string = "Event " + to_string(rand_num);
        inheritance_priority_queue_struct_t temp_struct = {rand_num, temp_string};
        q1.push(temp_struct);
    }
    print_queue(q1);
    q1.pop();
    print_queue(q1);
}