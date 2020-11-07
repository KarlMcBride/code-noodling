// Source:
//      https://cplusplus.com/reference/chrono/steady_clock/
//      https://cplusplus.com/reference/chrono/system_clock/


#include <ctime>
#include <iostream>
#include <ratio>
#include <chrono>
#include <thread>

void timer()
{
    std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();

    std::cout << "printing out 1000 stars...\n";
    for (int i=0; i<1000; ++i)
    {
        std::cout << "*";
    }

    std::cout << std::endl;

    std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();

    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

    std::cout << "It took me " << time_span.count() << " seconds.";
    std::cout << std::endl;
}

void real_time_clock()
{
    std::chrono::duration<int,std::ratio<60*60*24> > one_day (1);

    std::chrono::system_clock::time_point today = std::chrono::system_clock::now();
    std::chrono::system_clock::time_point tomorrow = today + one_day;

    std::time_t tt;

    tt = std::chrono::system_clock::to_time_t ( today );
    std::cout << "today is: " << ctime(&tt);

    tt = std::chrono::system_clock::to_time_t ( tomorrow );
    std::cout << "tomorrow will be: " << ctime(&tt);

}

int main ()
{
    timer();
    real_time_clock();

    uint64_t seconds_since_epoc = std::chrono::system_clock::now().time_since_epoch() / std::chrono::seconds(1);
    std::cout << "seconds_since_epoc: " << seconds_since_epoc << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(4));

    seconds_since_epoc = std::chrono::system_clock::now().time_since_epoch() / std::chrono::seconds(1);
    std::cout << "seconds_since_epoc: " << seconds_since_epoc << std::endl;

    return 0;
}