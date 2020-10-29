#include <iostream>
#include <string>

#include <queue>
#include <iostream>
#include <ctime>

#include "car_queue_class.hpp"
#include "fruit_queue_class.hpp"
#include "struct_car.hpp"
#include "struct_fruit.hpp"

void car_queue_test()
{
    car_queue_class car_queue;

    struct_car_t car_1("Ferrari", "Enzo", 651, 2);
    struct_car_t car_2("Audi", "A4", 130, 4);
    struct_car_t car_3("Pagandi", "Zonda R", 750, 2);

    car_queue.add_to_car_queue(car_1);
    car_queue.add_to_car_queue(car_2);
    car_queue.add_to_car_queue(car_3);

    car_queue.print_car_queue();
}

void fruit_queue_test()
{
    fruit_queue_class fruit_queue;

    struct_fruit_t fruit_1("Lemon", "Yellow", true);
    struct_fruit_t fruit_2("Apple", "Red/Green", false);
    struct_fruit_t fruit_3("Strawberry", "Red", false);

    fruit_queue.add_to_queue(fruit_1);
    fruit_queue.add_to_queue(fruit_2);
    fruit_queue.add_to_queue(fruit_3);

    fruit_queue.print_fruit_queue();
}

int main()
{
    car_queue_test();
    fruit_queue_test();

    return 0;
}