#include <iostream>
#include <string>

#include <queue>
#include <iostream>

#include "fault_buffer.hpp"

int main()
{
    fault_buffer buffer_instance;
    buffer_instance.print_buffer();

    for(int n = 0; n < 5; n++)
    {
        int rand_num = rand() % 10000 + 1;
        std::string temp_string = "Event " + std::to_string(rand_num);
        buffer_instance.add_event(rand_num, temp_string);
    }

    buffer_instance.print_buffer();
}