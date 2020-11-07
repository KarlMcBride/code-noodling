#include <iostream>
#include <thread>

void looper(int _iterations)
{
    std::cout << "Entered looper" << std::endl;

    for (int index = 0; index < _iterations; index++)
    {
        std::cout << " " << index << std::endl;
    }
}

int main()
{
    std::thread thread(looper, 5);

    std::cout << "Started thread" << std::endl;
    thread.join();

    return 0;
}