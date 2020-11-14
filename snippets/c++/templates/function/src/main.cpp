#include <iostream>

template<typename Type> void print_variable(Type _var)
{
    std::cout << _var << std::endl;
}

int main()
{
    print_variable(1234);
    print_variable("5678");

    return 0;
}