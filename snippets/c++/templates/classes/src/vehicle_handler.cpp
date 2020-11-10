#include <iostream>

#include "vehicle_handler.hpp"

template<class Type> vehicle_handler<Type>::vehicle_handler(Type _vehicle) : m_vehicle(_vehicle)
{

}

template<class Type> vehicle_handler<Type>::~vehicle_handler()
{

}

template<class Type> void vehicle_handler<Type>::describe(void)
{
    m_vehicle.describe();
}
