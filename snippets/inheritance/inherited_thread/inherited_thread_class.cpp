#include <chrono>
#include <iostream>
#include <string>
#include <thread>

// Base class
class BaseClassWithThread
{
    public:
        BaseClassWithThread()
        {
            std::cout << "BaseClassWithThread constructor called" << std::endl;
            bg_thread = std::thread(&BaseClassWithThread::bg_work, this);
        }

        void WaitForThreadStop(void)
        {
            bg_thread.join();
        }

    private:
        std::thread bg_thread;
        void bg_work(void)
        {
            std::cout << "bg_work started" << std::endl;
            for (int i = 1; i <= 3; i ++)
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                std::cout << "bg_work [ " << i << " ]" << std::endl;
            }
            std::cout << "bg_work finished" << std::endl;
        }
};

class InheritingClass: public BaseClassWithThread
{
    public:
        InheritingClass()
        {
            std::cout << "InheritingClass constructor called" << std::endl;
        }

        ~InheritingClass()
        {
            std::cout << "InheritingClass destructor called (waiting for thread stop)" << std::endl;
            WaitForThreadStop();
            std::cout << "InheritingClass destructor thread stopped" << std::endl;
        }
};

int main(void)
{
    InheritingClass inheritingInstance;

    return 0;
}
