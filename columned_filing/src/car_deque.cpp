#include <car_deque.hpp>

#include <iostream>
#include <deque>
#include <vector>

const std::string DATA_FILE_PATH = "car_file.txt";

const std::string MANUFACTURER = "MANUFACTURER";
const std::string MODEL        = "MODEL";
const std::string HORSEPOWER   = "HORSEPOWER";
const std::string DOOR_COUNT   = "DOOR_COUNT";

std::vector<std::string> car_columns = { MANUFACTURER, MODEL, HORSEPOWER, DOOR_COUNT };

// Inherit dequed_file as base class, and call its constructor with the
// local max size parameter and data columns from above

car_deque::car_deque(const int _max_size) : dequed_file(_max_size, car_columns, DATA_FILE_PATH)
{
    std::cout << "car_deque constructor called" << std::endl;

    parse_file_vectors();
}

car_deque::~car_deque(void)
{
    std::cout << "car_deque deconstructor called" << std::endl;
}

void car_deque::parse_file_vectors(void)
{
    std::cout << "car_deque parse_file_vectors called" << std::endl;

    std::deque<std::string> file_column_headers;
    std::deque<std::deque<std::string>> file_data;
    read_file(file_column_headers, file_data);
    std::deque<int> header_indices = get_header_indices(file_column_headers);
    struct_car_t new_car = struct_car_t(file_data.front(), header_indices);
    std::cout << "new_car: [ " << new_car.as_string() << " ]" << std::endl;
}