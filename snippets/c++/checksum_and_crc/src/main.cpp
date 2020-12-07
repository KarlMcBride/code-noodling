#include <iostream>
#include <unistd.h>

#include "checksum.hpp"
#include "crc.hpp"

int main()
{
    // Last two digits are not used when calculating CRC
    //uint8_t data_array[] = {         0x53, 0x00, 0x19, 0x00, 0x06, 0x6B,
    //    0x00, // Reader number
    //    0x02, // Text command (behaviour)
    //    0x00, // Temp text time
    //    0x01, // Row where first character will be displayed (1-indexed)
    //    0x01, // Column where first character will be displayed (1-indexed)
    //    0x0B, // Text length
    //    0x54, 0x65, 0x73, 0x74, 0x5F, 0x33, 0x2D, 0x31, 0x32, 0x2D, 0x31,
    //    0x84, 0xC8 };
    uint8_t data_array[] = { 0x53, 0x7F, 0x0D, 0x00, 0x07, 0x6E, 0x00, 0x80, 0x25, 0x00, 0x00, 0xEC, 0xFC };
    uint8_t data_length = sizeof(data_array);

    auto checksum = calculate_checksum(data_array, data_length);

    std::cout << "CHK SUM: " << std::to_string(checksum) << std::endl;

    crc_data_t crc_data = calculate_crc(data_array, data_length);

    std::cout << "CRC LSB: " << std::to_string(crc_data.lsb) << std::endl;
    std::cout << "CRC MSB: " << std::to_string(crc_data.msb) << std::endl;

    return 0;
}