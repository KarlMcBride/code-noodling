#include <chrono>
#include <iostream>
#include <string>

int main()
{
    long ms_start = std::chrono::steady_clock::now().time_since_epoch().count();

    std::cout << "printing out 1000 stars...\n";
    for (int i=0; i<100; ++i) std::cout << "*";
    std::cout << std::endl;

    float ms_end = std::chrono::steady_clock::now().time_since_epoch().count();
    float ms_duration = (ms_end - ms_start) / 100000000;

    std::cout << "Start time: " << ms_start << std::endl;
    std::cout << "End time: " << ms_end << std::endl;
    std::cout << "Duration: " << ms_duration << "s" << std::endl;
}
