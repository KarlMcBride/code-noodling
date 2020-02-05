#ifndef __STRUCT_FAULT_HPP
#define __STRUCT_FAULT_HPP


#include <iostream>
#include <string>
#include <deque>
#include <vector>

#include <constants.hpp>

struct struct_fault_t
{
    int date_time;
    std::string severity;
    std::string application;
    std::string fault_message;

    struct_fault_t(std::vector<std::string> data_tokens, std::vector<std::string> data_header_tokens)
    {
        for(std::size_t i = 0; i < data_tokens.size(); i++)
        {
            std::cout << "struct_fault_t: data_tokens: " << data_tokens[i] << '\n';
        }
        for(std::size_t i = 0; i < data_header_tokens.size(); i++)
        {
            std::cout << "struct_fault_t: data_header_tokens: " << data_header_tokens[i] << '\n';
        }
    }

    struct_fault_t(int _date_time, std::string _severity, std::string _application, std::string _fault_message)
    {
        date_time = _date_time;
        severity = _severity;
        application = _application;
        fault_message = _fault_message;
    }

    struct_fault_t(std::deque<std::string>& _data_deque, std::deque<int> _data_column_order)
    {
        date_time     = get_int_data_field(_data_deque, _data_column_order);
        severity      = get_string_data_field(_data_deque, _data_column_order);
        application   = get_string_data_field(_data_deque, _data_column_order);
        fault_message = get_string_data_field(_data_deque, _data_column_order);
    }

    std::string get_string_data_field(std::deque<std::string>& _data_deque, std::deque<int>& _data_column_order)
    {
        std::string return_value = "NO_DATA";

        if (_data_column_order.front() > -1)
        {
            return_value = _data_deque[_data_column_order.front()];
        }
        _data_column_order.pop_front();
        return return_value;
    }

    int get_int_data_field(std::deque<std::string>& _data_deque, std::deque<int>& _data_column_order)
    {
        int return_value = -1;
        if (_data_column_order.front() > -1)
        {
            try
            {
                return_value = std::stoi(_data_deque[_data_column_order.front()]);
            }
            catch(const std::exception& e)
            {
                std::cout << e.what() << std::endl;
                return_value = -2;
            }

        }
        _data_column_order.pop_front();
        return return_value;
    }

    std::string as_string(void) const
    {
        std::string struct_as_string = std::to_string(date_time) + constants::FIELD_DELIMITER
                                                    + severity + constants::FIELD_DELIMITER
                                                    + application + constants::FIELD_DELIMITER
                                                    + fault_message;
        return struct_as_string;
    }

    bool operator < (const struct_fault_t& rhs_struct) const
    {
        if (date_time < rhs_struct.date_time)
        {
            return true;
        }
        else if (rhs_struct.date_time < date_time)
        {
            return false;
        }
        else
        {
            if (severity < rhs_struct.severity)
            {
                return true;
            }
            else if (rhs_struct.severity < severity)
            {
                return false;
            }
        }
    }
};


#endif // __STRUCT_FAULT_HPP