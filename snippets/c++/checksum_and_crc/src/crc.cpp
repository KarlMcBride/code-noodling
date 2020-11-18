#include "crc.hpp"

// Note: length should always be full length of data, including the CRC bytes.
// These two CRC bytes are then ignored when calculating the CRC.
crc_data_t calculate_crc(uint8_t *_data, uint8_t _length)
{
  uint16_t crc_value = 0x1D0F;

  for (uint16_t index = 0; index < _length-2; index++)
  {
    crc_value = (crc_value << 8) ^ CrcTable[ ((crc_value >> 8) ^ _data[index]) & 0xFF];
  }

  crc_data_t crc_data;
  crc_data.value = crc_value;
  crc_data.lsb = crc_value & 0xFF;
  crc_data.msb = (crc_value >> 8);

  return crc_data;
}
