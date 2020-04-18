#include <iostream>

const std::string CPP_STRING = "${VAR_TO_BE_SUBSTITUTED}";

int main()
{
    std::cout << "Var: [ " << CPP_STRING << " ]" << std::endl;

    return 0;
}