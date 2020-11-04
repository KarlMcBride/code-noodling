#include <iostream>

#include "alpha.hpp"

alpha::alpha() : m_bravo(), m_charlie()
{
    m_charlie.print();
}

alpha::~alpha()
{

}

void alpha::print(void)
{
    std::cout << "Alpha print" << std::endl;
}

void alpha::call_chain(void)
{
    print();
    m_bravo.call_chain();
}
