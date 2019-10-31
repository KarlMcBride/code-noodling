#include <iostream>
#include <queue>
#include <string>
#include <sstream>

#include "fruit_queue_class.hpp"
#include "struct_fruit.hpp"

// Sorting rule that is applied when inserting new items into the priority queue
auto fruit_sort_lambda = [] (struct_fruit_t const& s1, struct_fruit_t const& s2) -> bool
{
    return s1 > s2;
};

std::priority_queue<struct_fruit_t, std::vector<struct_fruit_t>, decltype(fruit_sort_lambda)> fruit_priority_queue(fruit_sort_lambda);

fruit_queue_class::fruit_queue_class()
{

}

fruit_queue_class::~fruit_queue_class()
{

}

void fruit_queue_class::add_to_queue(struct_fruit_t _new_fruit)
{
    queue_manager.add_to_base_queue (fruit_priority_queue, _new_fruit);
}

void fruit_queue_class::print_fruit_queue()
{
    queue_manager.print_queue(fruit_priority_queue);
}