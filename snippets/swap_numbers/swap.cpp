#include <iostream>

#include "swap_class.hpp"

using namespace std;

int main()
{
    int number1 = 5;
    int number2 = 10;

    cout << "Numbers at start" << endl;
    cout << "Number 1: " << number1 << endl;
    cout << "Number 2: " << number2 << endl;

    swap_class swapper;

    swapper.swap_numbers(number1, number2);

    cout << "Numbers at end" << endl;
    cout << "Number 1: " << number1 << endl;
    cout << "Number 2: " << number2 << endl;
}
