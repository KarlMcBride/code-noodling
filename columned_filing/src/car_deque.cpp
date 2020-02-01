#include <car_deque.hpp>

#include <iostream>

const std::string MANUFACTURER = "MANUFACTURER";
const std::string MODEL        = "MODEL";
const std::string HORSEPOWER   = "HORSEPOWER";
const std::string DOOR_COUNT   = "DOOR_COUNT";

std::vector<std::string> car_columns = { MANUFACTURER, MODEL, HORSEPOWER, DOOR_COUNT };

// Inherit dequed_file as base class, and call its constructor with the
// local max size parameter and data columns from above
car_deque::car_deque(const int _max_size) : dequed_file(_max_size, car_columns)
{
    std::cout << "car_deque constructor called" << std::endl;
}

car_deque::~car_deque()
{
    std::cout << "car_deque deconstructor called" << std::endl;
}