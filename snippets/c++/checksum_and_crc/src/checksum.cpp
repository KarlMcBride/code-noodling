#include <cstdint>
#include <iostream>

// Note: Length should always be full length icluding the checksum.
// The checksum byte is ignored when calculating the checksum.
uint8_t calculate_checksum(uint8_t *_data, uint8_t _length)
{
  uint16_t message_sum = 0;

  for (int index = 0; index < _length-1; index++)
  {
    message_sum += _data[index];
  }

  // Obtain 8 least significant bits of the sum and take the two's complement of it.
  message_sum &= 0xFF;
  return static_cast<uint8_t>(255 - message_sum + 1);
}