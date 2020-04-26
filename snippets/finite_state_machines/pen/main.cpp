#include <iostream>

#include "pen.hpp"

int main()
{
    std::cout << "Pen FSM Example" << std::endl;

    Pen pen;
    pen.Click();
    pen.Click();
    pen.Click();
    pen.Snap();
    pen.Click();
    pen.Snap();

    return 0;
}