#ifndef __CAR_QUEUE_CLASS_HPP
#define __CAR_QUEUE_CLASS_HPP

#include <string>

#include "struct_car.hpp"
#include "priority_queue_manager.hpp"

class car_queue_class : priority_queue_manager
{
    public:
        car_queue_class();
        ~car_queue_class();

        void add_to_car_queue(struct_car_t _new_car);
        void print_car_queue();

    private:
};


#endif // __CAR_QUEUE_CLASS_HPP