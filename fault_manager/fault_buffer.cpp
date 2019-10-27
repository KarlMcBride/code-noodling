#include <iostream>
#include <fstream>
#include <queue>

#include "fault_buffer.hpp"
#include "fault_manager_constants.hpp"

//using namespace std;

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

// Sorting rule that is applied when inserting new items into the priority queue
auto sortRuleLambda = [] (event_t const& s1, event_t const& s2) -> bool
{
    return s1 > s2;
};

std::priority_queue<event_t, std::vector<event_t>, decltype(sortRuleLambda)> fault_queue(sortRuleLambda);

fault_buffer::fault_buffer()
{
    read_buffer();
}

fault_buffer::~fault_buffer()
{
    write_buffer();
}

void fault_buffer::add_event(int _time_stamp, std::string _fault_message)
{
    event_t new_event = {_time_stamp, _fault_message};
    fault_queue.push(new_event);

    while (get_queue_length() > FM_CONSTANTS::MAX_BUFFER_SIZE)
    {
        fault_queue.pop();
    }
}

int fault_buffer::get_queue_length()
{
    return fault_queue.size();
}

void fault_buffer::print_buffer()
{
    print_queue(fault_queue);
}

void fault_buffer::read_buffer()
{
    std::string line;
    std::ifstream fault_file(FM_CONSTANTS::DATA_STORAGE_FILE);
    if (fault_file.is_open())
    {
        while ( getline (fault_file, line) )
        {
            std::string delimiter = ":";

            size_t pos = 0;
            std::string token;
            while ((pos = line.find(delimiter)) != std::string::npos)
            {
                token = line.substr(0, pos);
                //std::cout << token << std::endl;
                line.erase(0, pos + delimiter.length());
            }
            //std::cout << line << std::endl;
        }
        fault_file.close();
    }
    else
    {
        std::cout << "Unable to open file\n";
    }
    std::cout << std::endl;
}

void fault_buffer::write_buffer()
{
    std::ofstream fault_file;
    fault_file.open(FM_CONSTANTS::DATA_STORAGE_FILE);
    while(!fault_queue.empty())
    {
        fault_file << fault_queue.top().time_stamp << ":" << fault_queue.top().event_string << std::endl;
        fault_queue.pop();
    }
    fault_file.close();
}