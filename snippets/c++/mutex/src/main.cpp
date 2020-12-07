#include <iostream>
#include <thread>
#include <mutex>

// Sample program that spawns 10 threads, with each attempting to increment the
// counter a set number of times each.
// Demonstrates obtaining the lock with "try_lock()" and using the result to determine
// whether the lock was obtained.

int counter = 0;
std::mutex counter_mutex;

void attempt_10k_increases ()
{
    for (int i = 0; i < 10000; ++i)
    {
        if (counter_mutex.try_lock())
        {
            ++counter;
            counter_mutex.unlock();
        }
    }
}

int main ()
{
    std::thread threads[10];
    for (int i = 0; i < 10; ++i)
    {
        threads[i] = std::thread(attempt_10k_increases);
    }

    for (auto& th : threads)
    {
        th.join();
    }

    std::cout << counter << " successful increases of the counter.\n";

    return 0;
}