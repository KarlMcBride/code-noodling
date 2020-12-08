#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>
#include <limits>
#include <string>

template<typename T> void showMinMax(std::string _name)
{
    std::cout << _name << ":" << std::endl;
    std::cout << "  min: " << std::numeric_limits<T>::min() << std::endl;
    std::cout << "  max: " << std::numeric_limits<T>::max() << std::endl;
}

int main()
{
    showMinMax<short>("short");
    showMinMax<int>("int");
    showMinMax<long>("long");
    showMinMax<float>("float");
    showMinMax<double>("double");
    showMinMax<long double>("long double");
    showMinMax<unsigned short>("unsigned short");
    showMinMax<unsigned int>("unsigned int");
    showMinMax<unsigned long>("unsigned long");
    std::cout << std::endl;

    showMinMax<boost::multiprecision::uint128_t>("boost::multiprecision::uint128_t");
    showMinMax<boost::multiprecision::uint256_t>("boost::multiprecision::uint256_t");
    showMinMax<boost::multiprecision::uint512_t>("boost::multiprecision::uint512_t");

    std::cout << "inline std::numeric_limits<boost::multiprecision::uint128_t>::max(): "
              << std::numeric_limits<boost::multiprecision::uint128_t>::max() << std::endl;

    return 0;
}