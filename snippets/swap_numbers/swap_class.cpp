#include "swap_class.hpp"

swap_class::swap_class()  {};
swap_class::~swap_class() {};

void swap_class::swap_numbers(int& _num1, int& _num2)
{
    _num1 += _num2;
    _num2  = _num1 - _num2;
    _num1 -= _num2;
}