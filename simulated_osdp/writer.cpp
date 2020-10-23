#include <iostream>

#include "writer.hpp"

writer::writer()
{
    std::cout << "writer constructor" << std::endl;
}

writer::~writer()
{
    std::cout << "writer deconstructor" << std::endl;
}