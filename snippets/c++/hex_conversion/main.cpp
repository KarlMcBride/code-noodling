#include <cstdint>
#include <iostream>

// Includes needed for int_to_hex
#include <iomanip>
#include <sstream>
#include <string>

template< typename Type > std::string int_to_hex( Type _data )
{
    std::stringstream stream;
    stream << "0x" << std::setfill ('0') << std::setw(sizeof(Type)*2) << std::hex << _data;
    return stream.str();
}

int main()
{
    int int_number = 100;
    std::cout << "int_number   : " << int_number << " : " << int_to_hex(int_number) << std::endl;

    unsigned int u_int_number = 100;
    std::cout << "u_int_number : " << u_int_number << " : " << int_to_hex(u_int_number) << std::endl;

    short short_number = 100;
    std::cout << "short_number : " << short_number << " : " << int_to_hex(short_number) << std::endl;

    double double_number = 100;
    std::cout << "double_number: " << double_number << " : " << int_to_hex(double_number) << std::endl;

    uint8_t uint8_number = 100; // Represents character 'd' in ASCII.
    std::cout << "uint8_number : " << uint8_number << "   : " << int_to_hex(uint8_number) << std::endl;
    uint8_number = 68;          // Represents character 'D' in ASCII.
    std::cout << "uint8_number : " << uint8_number << "   : " << int_to_hex(uint8_number) << std::endl;

    uint16_t uint16_number = 100;
    std::cout << "uint16_number: " << uint16_number << " : " << int_to_hex(uint16_number) << std::endl;

    return 0;
}