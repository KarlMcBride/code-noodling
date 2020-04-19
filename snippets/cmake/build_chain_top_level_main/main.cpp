#include <iostream>

#include <calculator.hpp>

int main()
{
    Calculator calcInstance;

    std::cout << "2+3 = " << calcInstance.AddTwoNumbers(2, 3) << std::endl;

    return 0;
}