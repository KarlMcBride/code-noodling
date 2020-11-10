#include <iostream>

#include "boat.hpp"
#include "tank.hpp"
#include "vehicle_handler.cpp"  // Required to access template constructor, otherwise "undefined reference" will be encountered.

int main()
{
    boat boat_instance;
    boat_instance.describe();

    tank tank_instance;
    tank_instance.describe();

    vehicle_handler<boat> boat_handler(boat_instance);
    boat_handler.describe();

    vehicle_handler<tank> tank_handler(tank_instance);
    tank_handler.describe();

    return 0;
}