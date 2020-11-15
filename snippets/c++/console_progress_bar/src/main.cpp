#include <chrono>
#include <iostream>
#include <thread>

void report_progress(const int _progress)
{
    const int MAX_BAR_WIDTH = 20;
    int hash_count = 0;

    if (_progress > 0)
    {
        hash_count = ((_progress * MAX_BAR_WIDTH) / 100) ;
    }

    std::string progress_bar = "";
    for (int index = 0; index < MAX_BAR_WIDTH; index++)
    {
        if (index <= hash_count)
        {
            progress_bar += "#";
        }
        else
        {
            progress_bar += ".";
        }
    }

    std::string prog_message = "Progress: " + std::to_string(_progress) + "% [" + progress_bar + "]";
    std::cout << std::string(prog_message.length(), '\b');

    std::cout << progress_bar << std::endl;
}

int main()
{
    for (int index = 0; index <= 100; index+=3)
    {
        report_progress(index);
    }
    std::string str="Hello!";
    std::cout << str;
    std::cout << std::string(str.length(),'\b');
    std::cout << "Hello again!";
    return 0;
}