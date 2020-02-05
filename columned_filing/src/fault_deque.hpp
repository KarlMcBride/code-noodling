#ifndef __FAULT_DEQUE_HPP
#define __FAULT_DEQUE_HPP


#include <dequed_file.hpp>
#include <struct_fault_t.hpp>


class fault_deque : public dequed_file<struct_fault_t>
{
    public:
        fault_deque(const int _max_size);
        ~fault_deque(void);

    protected:
        // No items

    private:
        // No items
};


#endif // __FAULT_DEQUE_HPP