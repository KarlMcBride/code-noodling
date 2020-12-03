#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <memory>
#include <string>
#include <thread>
#include <chrono>

int main()
{
    int serial_port_fd = open("/dev/ttyUSB0", O_RDWR);
    fcntl(serial_port_fd, F_SETFL, 0);
    struct termios tty;

    if(tcgetattr(serial_port_fd, &tty) < 0)
    {
      return -1;
    }

    cfsetospeed(&tty, B9600);
    cfsetispeed(&tty, B9600);

    tty.c_cflag |= (CLOCAL | CREAD);
    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8;
    tty.c_cflag &= ~PARENB;
    tty.c_cflag &= ~CSTOPB;
    tty.c_cflag &= ~CRTSCTS;

    // Setup for Non-Canonical Mode
    tty.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR | IGNCR | ICRNL | IXON);
    tty.c_lflag &= ~(ECHO | ECHONL | ICANON | ISIG | IEXTEN);
    tty.c_oflag &= ~OPOST;

    // Read Data will Block
    tty.c_cc[VMIN] = 1;
    tty.c_cc[VTIME] = 1;

    if ( tcsetattr(serial_port_fd, TCSANOW, &tty) != 0 )
    {
      return -1;
    }


    uint8_t port_read_data_buffer[64];
    //uint8_t port_write_data_buffer[256];

    while(true)
    {
      int data_read = read(serial_port_fd, &port_read_data_buffer, sizeof(port_read_data_buffer));

      if (data_read > 0)
      {
        std::cout << "Data read: ";
        for (int buffer_index = 0; buffer_index < data_read; buffer_index++)
        {
          uint8_t val = static_cast<uint8_t>(port_read_data_buffer[buffer_index]);
          std::cout << std::to_string(val);
          //input_queue.push(port_read_data_buffer[buffer_index]);
        }
        std::cout << std::endl;
      }
    }

}