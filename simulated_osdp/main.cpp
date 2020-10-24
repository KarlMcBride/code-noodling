#include <iostream>

#include "reader.hpp"
#include "simulated_port.hpp"
#include "writer.hpp"

int main()
{
    std::cout << "simulated_osdp" << std::endl;

    simulated_port simulated_port_instance;

    reader reader_instance(&simulated_port_instance);
    writer writer_instance(&simulated_port_instance);

    reader_instance.join();
    writer_instance.join();
}