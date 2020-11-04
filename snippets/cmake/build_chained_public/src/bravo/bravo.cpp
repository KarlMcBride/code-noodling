#include <iostream>

#include "bravo.hpp"

bravo::bravo() : m_charlie()
{

}

bravo::~bravo()
{

}

void bravo::call_chain(void)
{
    print();
    m_charlie.print();
}

void bravo::print(void)
{
    std::cout << "Bravo print" << std::endl;
}
