#ifndef __STRUCT_CAR_HPP
#define __STRUCT_CAR_HPP

#include <string>

template <typename value_type> struct file_data_t
{
    std::string column_name;
    int column_index;
    value_type value;

    bool operator < (const file_data_t& rhs_struct) const
    {
        return (value < rhs_struct.value);
    }

    bool operator > (const file_data_t& rhs_struct) const
    {
        return (rhs_struct.value < value);
    }

    bool operator == (const file_data_t& rhs_struct) const
    {
        return (value == rhs_struct.value);
    }
};

struct struct_car_t
{
    file_data_t<std::string> manufacturer;
    file_data_t<std::string> model;
    file_data_t<int> horsepower;
    file_data_t<int> door_count;
    std::string file_data_line;

    struct_car_t(std::string _manufacturer, std::string _model, int _horsepower, int _door_count)
    {
        manufacturer.column_index = 0;
        manufacturer.column_name = "MANUFACTURER";
        manufacturer.value = _manufacturer;

        model.column_index = 1;
        model.column_name = "MODEL";
        model.value = _model;

        horsepower.column_index = 2;
        horsepower.column_name = "HORSEPOWER";
        horsepower.value = _horsepower;

        door_count.column_index = 3;
        door_count.column_name = "DOOR_COUNT";
        door_count.value = _door_count;

        file_data_line = manufacturer.value + ";" + model.value + ";" + std::to_string(horsepower.value) + ";" + std::to_string(door_count.value);
    }

    std::string as_string(void) const
    {
        std::string struct_as_string = manufacturer.value + ":" + model.value + ":"
                                        + std::to_string(horsepower.value) + ":" + std::to_string(door_count.value);
        return struct_as_string;
    }

    bool operator == (const struct_car_t& rhs_struct) const
    {
       return (manufacturer.value == rhs_struct.manufacturer.value
                && model.value == rhs_struct.model.value
                && horsepower == rhs_struct.horsepower
                && door_count == rhs_struct.door_count);
    }

    bool operator < (const struct_car_t& rhs_struct) const
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

    bool operator > (const struct_car_t& rhs_struct) const
    {
        return (rhs_struct.manufacturer < manufacturer);
    }
};


#endif // __STRUCT_CAR_HPP