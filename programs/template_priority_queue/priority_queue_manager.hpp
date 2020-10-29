#ifndef __PRIORITY_QUEUE_MANAGER_HPP
#define __PRIORITY_QUEUE_MANAGER_HPP

#include <iostream>
#include <string>

#include "struct_car.hpp"
#include "struct_fruit.hpp"


class priority_queue_manager
{
    public:
        priority_queue_manager()  {};
        ~priority_queue_manager() {};

        template<typename Queue_type, typename Struct_type> void add_to_base_queue(Queue_type& _queue, Struct_type& _new_item)
        {
            _queue.push(_new_item);
        };

        template<typename Queue_type> void print_queue(Queue_type& _queue)
        {
            std::cout << "Queue size: " << _queue.size() << std::endl;
            while(!_queue.empty())
            {
                std::cout << _queue.top().as_string() << std::endl;
                _queue.pop();
            }
            std::cout << '\n';
        };
};

#endif // __PRIORITY_QUEUE_MANAGER_HPP