// https://www.geeksforgeeks.org/map-vs-unordered_map-c/

#ifndef __STANDARD_MAPS_HPP__
#define __STANDARD_MAPS_HPP__

#include <iostream>
#include <iterator>
#include <string>
#include <map>
#include <bits/stdc++.h>

const int DIRECT_ACCESS_INDEX = 2;

void ordered_map_demo(void)
{
    std::cout << "##########" << std::endl;
    std::cout << "Ordered map:" << std::endl;

    // Ordered map
    std::map<int, std::string> order;

    // Mapping values to keys
    order[5] = "five";
    order[3] = "three";
    order[20] = "twenty";
    order[1] = "one";

    std::cout << "Direct access order[" << DIRECT_ACCESS_INDEX << "]: [ " << order[2] << " ]" << std::endl;
    // Iterating the map and printing ordered values
    for (auto i = order.begin(); i != order.end(); i++)
    {
        std::cout << i->first << " : " << i->second << std::endl;
    }
    std::cout << "##########" << std::endl;
}

void unordered_map_demo(void)
{
    std::cout << "##########" << std::endl;
    std::cout << "Unordered map:" << std::endl;

    // Unordered map
    std::unordered_map<int, std::string> order;

    // Mapping values to keys
    order[5] = "five";
    order[3] = "three";
    order[20] = "twenty";
    order[1] = "one";

    std::cout << "Direct access order[" << DIRECT_ACCESS_INDEX << "]: [ " << order[2] << " ]" << std::endl;
    // Iterating the map and printing unordered values
    for (auto i = order.begin(); i != order.end(); i++)
    {
        std::cout << i->first << " : " << i->second << '\n';
    }

    std::cout << "##########" << std::endl;
}

#endif // __STANDARD_MAPS_HPP__