#include <libgen.h>

#include <iostream>

#include <stdio.h>
#define EMPTY

#define MACRO_LOG() macro_log(__FILE__, __FUNCTION__, __LINE__)

void macro_log(std::string _file, std::string _function, int _line)
{
    std::cout << "macro_log: " << _file << ", " << _function << ", " << _line << std::endl;
    std::cout << __BASE_FILE__ << std::endl;
    std::cout << __FILE__ << std::endl;
}

void second_function()
{
    MACRO_LOG();
}

int main()
{
    MACRO_LOG();

    second_function();

    return 0;
}