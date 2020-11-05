#include <iostream>

void print_array(int *_array, const int _length)
{
    std::cout << "Printing array: " << std::endl;

    for (int index = 0; index < _length; index++)
    {
        std::cout << "  " << index << ": " << _array[index] << std::endl;
    }
}

bool overwrite_data(int *_array, const int _array_len, int *_new_data, const int _new_data_len, const int _insert_index)
{
    if ( (_new_data_len + _insert_index) > _array_len)
    {
        return false;
    }

    for (int index = 0; index < _new_data_len; index++)
    {
        _array[_insert_index + index] = _new_data[index];
    }
    return true;
}


int main ()
{
    int int_array[] = { 0, 2, 4, 8, 16, 32, 64, 128 };

    print_array(int_array, (sizeof(int_array) / sizeof(int_array[0])) );

    int new_data[] = { 1, 2, 3 };

    overwrite_data(int_array, (sizeof(int_array) / sizeof(int_array[0])), new_data, (sizeof(new_data) / sizeof(new_data[0])), 3 );

    print_array(int_array, (sizeof(int_array) / sizeof(int_array[0])) );

    return 0;
}