#include <iostream>
#include <string>

#include <queue>
#include <iostream>
#include <ctime>

#include "fault_queue.hpp"

int main()
{
    fault_queue buffer_instance;
    buffer_instance.print_buffer();

    srand(time(NULL));

    for(int n = 0; n < 5; n++)
    {
        int rand_num = rand() % 10000 + 1;
        std::string temp_string = "Event " + std::to_string(rand_num);
        buffer_instance.add_event(rand_num, temp_string);
    }

    buffer_instance.print_buffer();
}