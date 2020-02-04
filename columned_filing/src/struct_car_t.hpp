#ifndef __STRUCT_CAR_HPP
#define __STRUCT_CAR_HPP


#include <iostream>
#include <string>
#include <vector>

#include <constants.hpp>


struct struct_car_t
{
    std::string manufacturer;
    std::string model;
    int horsepower;
    int door_count;

    struct_car_t(std::vector<std::string> data_tokens, std::vector<std::string> data_header_tokens)
    {
        for(std::size_t i = 0; i < data_tokens.size(); i++)
        {
            std::cout << "struct_car_t: data_tokens: " << data_tokens[i] << '\n';
        }
        for(std::size_t i = 0; i < data_header_tokens.size(); i++)
        {
            std::cout << "struct_car_t: data_header_tokens: " << data_header_tokens[i] << '\n';
        }
    }

    struct_car_t(std::string _manufacturer, std::string _model, int _horsepower, int _door_count)
    {
        manufacturer = _manufacturer;
        model = _model;
        horsepower = _horsepower;
        door_count = _door_count;
    }

    struct_car_t(std::deque<std::string>& _car_data_deque, std::deque<int>& _data_column_order)
    {
        manufacturer = get_string_data_field(_car_data_deque, _data_column_order);
        model        = get_string_data_field(_car_data_deque, _data_column_order);
        horsepower   = get_int_data_field(_car_data_deque, _data_column_order);
        door_count   = get_int_data_field(_car_data_deque, _data_column_order);
    }

    std::string get_string_data_field(std::deque<std::string>& _car_data_deque, std::deque<int>& _data_column_order)
    {
        std::string return_value = "NO_DATA";

        if (_data_column_order.front() > -1)
        {
            std::cout << __FUNCTION__ << ":" << __LINE__ << _data_column_order.front() << std::endl;
            return_value = _car_data_deque[_data_column_order.front()];
        }
        _data_column_order.pop_front();
        std::cout << "string return_value: [ " << return_value << " ]" << std::endl;
        return return_value;
    }

    int get_int_data_field(std::deque<std::string>& _car_data_deque, std::deque<int>& _data_column_order)
    {
        int return_value = -1;
        std::cout << __FUNCTION__ << ":" << __LINE__ << std::endl;
        if (_data_column_order.front() > -1)
        {
            try
            {
                std::cout << __FUNCTION__ << ":" << __LINE__ << std::endl;
                std::cout << __FUNCTION__ << ":" << __LINE__ << _data_column_order.front() << std::endl;
                return_value = std::stoi(_car_data_deque[_data_column_order.front()]);
                std::cout << __FUNCTION__ << ":" << __LINE__ << std::endl;
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
                std::cout << __FUNCTION__ << ":" << __LINE__ << std::endl;
                return_value = -2;
                std::cout << __FUNCTION__ << ":" << __LINE__ << std::endl;
            }

        }
        _data_column_order.pop_front();
        std::cout << __FUNCTION__ << ":" << __LINE__ << std::endl;
        std::cout << __FUNCTION__ << ":" << __LINE__ << std::endl;
        return return_value;
    }

    std::string as_string(void) const
    {
        std::string struct_as_string = manufacturer + constants::FIELD_DELIMITER
                                                    + model + constants::FIELD_DELIMITER
                                                    + std::to_string(horsepower) + constants::FIELD_DELIMITER
                                                    + std::to_string(door_count);
        return struct_as_string;
    }

    bool operator == (const struct_car_t& rhs_struct) const
    {
       return (manufacturer == rhs_struct.manufacturer
                && model == rhs_struct.model
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