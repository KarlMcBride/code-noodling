#ifndef __STRUCT_CAR_HPP
#define __STRUCT_CAR_HPP

#include <string>

struct struct_car_t
{
    std::string manufacturer;
    std::string model;
    int horsepower;
    int door_count;

    struct_car_t(std::string _manufacturer, std::string _model, int _horsepower, int _door_count)
    {
        manufacturer = _manufacturer;
        model = _model;
        horsepower = _horsepower;
        door_count = _door_count;
    }

    std::string as_string(void) const
    {
        std::string struct_as_string = manufacturer + ":" + model + ":" + std::to_string(horsepower) + ":" + std::to_string(door_count);
        return struct_as_string;
    }

    bool operator==(const struct_car_t& rhs_struct) const
    {
       return (manufacturer == rhs_struct.manufacturer);
    }

    bool operator<(const struct_car_t& rhs_struct) const
    {
        return (manufacturer < rhs_struct.manufacturer);
    }

    bool operator>(const struct_car_t& rhs_struct) const
    {
        return (rhs_struct.manufacturer < manufacturer);
    }
};


#endif // __STRUCT_CAR_HPP