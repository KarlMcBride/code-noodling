#include <iostream>

#include <car_deque.hpp>
#include <fault_deque.hpp>
#include <struct_car_t.hpp>
#include <struct_fault_t.hpp>


void add_car_list(car_deque& _car_deque)
{
    _car_deque.add_item(struct_car_t("Audi", "A3", 200, 4));
    _car_deque.add_item(struct_car_t("Audi", "A4", 300, 4));
    _car_deque.add_item(struct_car_t("Ferrari", "Enzo", 700, 2));
    _car_deque.add_item(struct_car_t("Audi", "A4", 500, 4));
    _car_deque.add_item(struct_car_t("Ferrari", "F40", 650, 2));
    _car_deque.add_item(struct_car_t("Audi", "A5", 350, 4));
    _car_deque.add_item(struct_car_t("Aston Martin", "DB9", 550, 2));
}


void add_fault_list(fault_deque& _fault_deque)
{
    _fault_deque.add_item(struct_fault_t(1000001, "INFORMATION", "C++", "First fault"));
    _fault_deque.add_item(struct_fault_t(1000001, "CRITICAL",    "F++", "Second fault"));
    _fault_deque.add_item(struct_fault_t(1000000, "INFORMATION", "C++", "Third fault"));
    _fault_deque.add_item(struct_fault_t(1000000, "ALERT",       "C++", "Fourth fault"));
}


int main()
{
    car_deque car_list = car_deque(6);

    //add_car_list(car_list);
    car_list.print_forward();
    //car_queue.check_equality();
    car_list.write_file();

    fault_deque fault_list = fault_deque(3);
    add_fault_list(fault_list);
    fault_list.print_forward();
    fault_list.write_file();

    return 0;
}