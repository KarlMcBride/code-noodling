#include <iostream>

using namespace std;

void number_swap(int _num1, int _num2)
{
    _num1 += _num2;
    _num2 =  _num1 - _num2;
   _num1 -= _num2;

   cout << "Numbers within main" << endl;
   cout << "Number 1: " << _num1 << endl;
   cout << "Number 2: " << _num2 << endl;
}

int main()
{
    int number1 = 5;
    int number2 = 10;

    cout << "Numbers within main" << endl;
    cout << "Number 1: " << number1 << endl;
    cout << "Number 2: " << number2 << endl;

    number_swap(number1, number2);
}
