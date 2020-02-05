#include <car_deque.hpp>

#include <iostream>
#include <deque>
#include <vector>

const std::string DATA_FILE_PATH = "car_file.txt";

std::vector<std::string> car_columns = { "MANUFACTURER", "MODEL", "HORSEPOWER", "DOOR_COUNT" };

// Inherit dequed_file as base class, and call its constructor with the
// local max size parameter and data columns from above

car_deque::car_deque(const int _max_size) : dequed_file(_max_size, car_columns, DATA_FILE_PATH)
{

}

car_deque::~car_deque(void)
{

}