#include <iostream>

#include <car_deque.hpp>
#include <struct_car_t.hpp>


void add_car_list(car_deque& _car_deque)
{
    _car_deque.add_car(struct_car_t("Audi", "A3", 200, 4));
    _car_deque.add_car(struct_car_t("Audi", "A4", 300, 4));
    _car_deque.add_car(struct_car_t("Ferrari", "Enzo", 700, 2));
    _car_deque.add_car(struct_car_t("Audi", "A4", 500, 4));
    _car_deque.add_car(struct_car_t("Ferrari", "F40", 650, 2));
    _car_deque.add_car(struct_car_t("Audi", "A5", 350, 4));
    _car_deque.add_car(struct_car_t("Aston Martin", "DB9", 550, 2));
}


int main()
{
    car_deque car_list = car_deque(6);

    add_car_list(car_list);
    car_list.print_forward();
    //car_queue.check_equality();
    car_list.write();
    car_list.read();

    return 0;
}