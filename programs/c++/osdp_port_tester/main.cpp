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

    // 0: reader number, 1: tone code, 2: on time, 3: off time, 4: count
    // BUZ byte numbering                                                    0     1     2     3     4
    uint8_t triple_buz_cmd[]        = { 0x53, 0x00, 0x0D, 0x00, 0x05, 0x6A, 0x00, 0x02, 0x0A, 0x05, 0x01, 0xED, 0x7A };
    uint8_t perm_buz_cmd[]          = { 0x53, 0x00, 0x0D, 0x00, 0x05, 0x6A, 0x00, 0x02, 0x0A, 0x05, 0x00, 0xCC, 0x6A };
    uint8_t clear_buz_cmd[]         = { 0x53, 0x00, 0x0D, 0x00, 0x05, 0x6A, 0x00, 0x01, 0x0A, 0x05, 0x00, 0x10, 0xF1 };

    std::cout << "Sending triple_buz_cmd" << std::endl;
    write(serial_port_fd, &triple_buz_cmd, 13);
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));

    std::cout << "Sending perm_buz_cmd" << std::endl;
    write(serial_port_fd, &perm_buz_cmd, 13);
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));

    // LED byte numbering                                                    0     1     2     3     4     5     6     7     8     9     10    11    12    13
    uint8_t perm_red_led_cmd[]      = { 0x53, 0x00, 0x16, 0x00, 0x05, 0x69, 0x00, 0x00, 0x00, 0x03, 0x03, 0x01, 0x02, 0x1E, 0x00, 0x01, 0x1E, 0x00, 0x01, 0x00, 0xC8, 0x7B };
    uint8_t perm_green_led_cmd[]    = { 0x53, 0x00, 0x16, 0x00, 0x05, 0x69, 0x00, 0x00, 0x00, 0x03, 0x03, 0x01, 0x02, 0x1E, 0x00, 0x01, 0x1E, 0x00, 0x02, 0x00, 0x9B, 0x2E };
    uint8_t perm_amber_led_cmd[]    = { 0x53, 0x00, 0x16, 0x00, 0x05, 0x69, 0x00, 0x00, 0x00, 0x03, 0x03, 0x01, 0x02, 0x1E, 0x00, 0x01, 0x1E, 0x00, 0x03, 0x00, 0xAA, 0x1D };
    uint8_t perm_blue_led_cmd[]     = { 0x53, 0x00, 0x16, 0x00, 0x05, 0x69, 0x00, 0x00, 0x00, 0x03, 0x03, 0x01, 0x02, 0x1E, 0x00, 0x01, 0x1E, 0x00, 0x04, 0x00, 0x3D, 0x84 };
    uint8_t perm_black_led_cmd[]    = { 0x53, 0x00, 0x16, 0x00, 0x05, 0x69, 0x00, 0x00, 0x00, 0x03, 0x03, 0x01, 0x02, 0x1E, 0x00, 0x01, 0x1E, 0x00, 0x00, 0x00, 0xF9, 0x48 };

    uint8_t perm_green_nop_cmd[]    = { 0x53, 0x00, 0x16, 0x00, 0x05, 0x69, 0x00, 0x00, 0x00, 0x03, 0x03, 0x01, 0x02, 0x1E, 0x00, 0x00, 0x1E, 0x00, 0x02, 0x00, 0xCA, 0x84 };

    // Temp command - 500ms on/off for 2500ms. However, LED controller does not currently support repeat parameter, with osdp_temp_param_program.json hardcoded to 5 repeats.
    uint8_t temp_red_led_cmd[]      = { 0x53, 0x00, 0x16, 0x00, 0x05, 0x69, 0x00, 0x00, 0x02, 0x05, 0x05, 0x01, 0x00, 0x19, 0x00, 0x00, 0x1E, 0x00, 0x02, 0x00, 0x89, 0x96 };


    std::cout << "Setting perm red" << std::endl;
    write(serial_port_fd, &perm_red_led_cmd, 22);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "Setting perm green" << std::endl;
    write(serial_port_fd, &perm_green_led_cmd, 22);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "Setting perm amber" << std::endl;
    write(serial_port_fd, &perm_amber_led_cmd, 22);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    std::cout << "Sending clear_buz_cmd" << std::endl;
    write(serial_port_fd, &clear_buz_cmd, 13);
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));

    std::cout << "Setting perm blue" << std::endl;
    write(serial_port_fd, &perm_blue_led_cmd, 22);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "Setting perm black" << std::endl;
    write(serial_port_fd, &perm_black_led_cmd, 22);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "Setting perm amber, followed by perm green NO-OP" << std::endl;
    write(serial_port_fd, &perm_amber_led_cmd, 22);
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    write(serial_port_fd, &perm_green_nop_cmd, 22);
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    std::cout << "Setting perm black" << std::endl;
    write(serial_port_fd, &perm_black_led_cmd, 22);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    std::cout << "Setting perm green, followed by temp red" << std::endl;
    write(serial_port_fd, &perm_green_led_cmd, 22);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    write(serial_port_fd, &temp_red_led_cmd, 22);
}