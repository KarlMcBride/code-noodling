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
       return (manufacturer == rhs_struct.manufacturer
                && model == rhs_struct.model
                && horsepower == rhs_struct.horsepower
                && door_count == rhs_struct.door_count);
    }

    bool operator<(const struct_car_t& rhs_struct) const
    {
        if (manufacturer < rhs_struct.manufacturer)
        {
            return true;
        }
        else if (manufacturer > rhs_struct.manufacturer)
        {
            return false;
        }
        else
        {
            if (model < rhs_struct.model)
            {
                return true;
            }
            else if (model > rhs_struct.model)
            {
                return false;
            }
            else
            {
                if (horsepower < rhs_struct.horsepower)
                {
                    return true;
                }
                else if (horsepower > rhs_struct.horsepower)
                {
                    return false;
                }
                else
                {
                    if (door_count < rhs_struct.door_count)
                    {
                        return true;
                    }
                    else if (door_count > rhs_struct.door_count)
                    {
                        return false;
                    }
                    else
                    {
                        return false;
                    }
                }

            }

        }
    }

    bool operator>(const struct_car_t& rhs_struct) const
    {
        return (rhs_struct.manufacturer < manufacturer);
    }
};


#endif // __STRUCT_CAR_HPP