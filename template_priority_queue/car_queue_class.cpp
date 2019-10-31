#include <iostream>
#include <queue>
#include <string>
#include <sstream>

#include "car_queue_class.hpp"
#include "struct_car.hpp"

// Sorting rule that is applied when inserting new items into the priority queue
auto car_sort_lambda = [] (struct_car_t const& s1, struct_car_t const& s2) -> bool
{
    return s1 > s2;
};

std::priority_queue<struct_car_t, std::vector<struct_car_t>, decltype(car_sort_lambda)> car_priority_queue(car_sort_lambda);

priority_queue_manager queue_manager;

car_queue_class::car_queue_class()
{

}

car_queue_class::~car_queue_class()
{

}

void car_queue_class::add_to_car_queue(struct_car_t _new_car)
{
    queue_manager.add_to_base_queue(car_priority_queue, _new_car);
}

void car_queue_class::print_car_queue()
{
    queue_manager.print_queue(car_priority_queue);
}