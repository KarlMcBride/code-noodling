#include <chrono>
#include <iostream>
#include <thread>

void report_progress(const int _progress)
{
    const int MAX_BAR_WIDTH = 20;
    int hash_count = 0;

    if (_progress > 0)
    {
        hash_count = (((double)_progress / 100) * MAX_BAR_WIDTH);
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
            progress_bar += " ";
        }
    }

    std::string prog_message = "Progress: " + std::to_string(_progress) + "% [" + progress_bar + "]";
    std::cout << std::string(prog_message.length(), '\r');
    std::cout << prog_message << std::flush;
}

int main()
{
    std::cout << "Progress bar example" << std::endl;

    for (int index = 0; index <= 100; index++)
    {
        report_progress(index);
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }

    return 0;
}