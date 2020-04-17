#include <iostream>

#include <TestTemp.hpp>
#include <TestTemp.cpp>

int main()
{
    TestTemp<int> int_test;
    int_test.SetValue(5);

    int return_val = int_test.Getalue();

    std::cout << "Value [ " << return_val << "]" << std::endl;

    return 0;
}