#ifndef __STRUCT_FRUIT_HPP
#define __STRUCT_FRUIT_HPP

#include <string>

struct struct_fruit_t
{
    std::string name;
    std::string colour;
    bool is_bitter;

    struct_fruit_t(std::string _name, std::string _colour, bool _is_bitter)
    {
        name = _name;
        colour = _colour;
        is_bitter = _is_bitter;
    }

    std::string as_string(void) const
    {
        std::string struct_as_string = name + ":" + colour + ":" + std::to_string(is_bitter);
        return struct_as_string;
    }

    bool operator<(const struct_fruit_t& rhs_struct) const
    {
        return (name < rhs_struct.name);
    }

    bool operator>(const struct_fruit_t& rhs_struct) const
    {
        return (rhs_struct.name < name);
    }
};


#endif // __STRUCT_FRUIT_HPP