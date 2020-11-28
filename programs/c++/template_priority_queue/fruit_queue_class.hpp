#ifndef __FRUIT_QUEUE_CLASS_HPP
#define __FRUIT_QUEUE_CLASS_HPP

#include <string>

#include "struct_fruit.hpp"
#include "priority_queue_manager.hpp"

class fruit_queue_class : priority_queue_manager
{
    public:
        fruit_queue_class();
        ~fruit_queue_class();

        void add_to_queue(struct_fruit_t _new_fruit);
        void print_fruit_queue();

    private:
        priority_queue_manager queue_manager;
};


#endif // __FRUIT_QUEUE_CLASS_HPP