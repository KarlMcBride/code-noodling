#include <iostream>
#include <stdint.h>

void split_numeric(uint32_t _input_number, uint8_t *_output_array, int _output_array_size)
{
    std::cout << "split_numeric: " << std::endl;
    auto shifted_number = _input_number;

    // Bitwise AND lowest 16 bits, add to array, then bitshift to right by 8 to discard those bits.
    for (int index = _output_array_size - 1; index >= 0; index--)
    {
        auto value = (shifted_number & 0xFF);
        std::cout << "    " << index << ": " << std::to_string(value) << std::endl;
        _output_array[index] = value;
        shifted_number = (shifted_number >> 8);
    }
}


int main()
{
    uint32_t number_32_t = 0x12345;
    uint8_t output_array[4] = {0x00, 0x00, 0x00, 0x00 };

    split_numeric(number_32_t, output_array, 4);

    std::cout << "Resulting array: " << std::endl;
    for (int index = 0; index < 4; index++)
    {
        std::cout << "    " << index << ": " << std::to_string(output_array[index]) << std::endl;
    }

    return 0;
}