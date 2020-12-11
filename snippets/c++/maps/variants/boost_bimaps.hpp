// https://www.geeksforgeeks.org/map-vs-unordered_map-c/

#ifndef __BOOST_BIMAPS_HPP__
#define __BOOST_BIMAPS_HPP__

#include <iostream>
#include <boost/bimap.hpp>

void boost_bimap_demo(void)
{
    std::cout << "##########" << std::endl;
    std::cout << "Boost bimap:" << std::endl;

    boost::bimap<char,int> bimap;
	bimap.insert({'A', 65});
	bimap.insert({'B', 66});
	bimap.insert({'C', 67});
	bimap.insert({'D', 68});
	bimap.insert({'E', 69});

	int value = 'F';

	auto it = bimap.right.find(value);

	if (it->first != value)
    {
		std::cout << "Key with given value not found" << std::endl;
	}
	else
    {
		std::cout << it->second << " -> " << it->first << std::endl;
    }

    std::cout << "##########" << std::endl;
}

#endif // __BOOST_BIMAPS_HPP__