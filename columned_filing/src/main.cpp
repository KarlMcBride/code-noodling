#include <iostream>
#include <bits/stdc++.h>

#include <columned_queue_file.hpp>
#include <struct_car.hpp>


void add_cars(columned_queue_file<struct_car_t> &_car_queue)
{
    _car_queue.add_item(struct_car_t("Audi", "A3", 200, 4));
    _car_queue.add_item(struct_car_t("Audi", "A4", 300, 4));
    _car_queue.add_item(struct_car_t("Ferrari", "Enzo", 700, 2));
    _car_queue.add_item(struct_car_t("Audi", "A4", 500, 4));
    _car_queue.add_item(struct_car_t("Ferrari", "F40", 650, 2));
    _car_queue.add_item(struct_car_t("Audi", "A5", 350, 4));
    _car_queue.add_item(struct_car_t("Aston Martin", "DB9", 550, 2));
}


int main()
{
    columned_queue_file<struct_car_t> car_queue(6);

    add_cars(car_queue);
    car_queue.print_forward();

    car_queue.check_equality();

    return 0;
}