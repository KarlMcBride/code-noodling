#include <iostream>
#include <unistd.h>

#include "checksum.hpp"
#include "crc.hpp"

int main()
{
    // Last two digits are not used when calculating CRC
    uint8_t data_array[] = { 0x01, 0x02, 0x03, 0x04, 0x05 };
    uint8_t data_length = sizeof(data_array);

    auto checksum = calculate_checksum(data_array, data_length);

    std::cout << "CHK SUM: " << std::to_string(checksum) << std::endl;

    crc_data_t crc_data = calculate_crc(data_array, data_length);

    std::cout << "CRC LSB: " << std::to_string(crc_data.lsb) << std::endl;
    std::cout << "CRC MSB: " << std::to_string(crc_data.msb) << std::endl;

    return 0;
}