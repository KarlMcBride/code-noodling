#include <algorithm>
#include <iostream>
#include <vector>

#include "animal_factory.hpp"

int main()
{
    std::vector<Animal*> animalVector;
    int choice;
    while (true)
    {
        std::cout << "Bird(1) Cat(2) Dog(3) Go(0): ";
        std::cin >> choice;
        if (choice == 0)
        {
            break;
        }
        animalVector.push_back(Animal::create_animal(choice));
    }
    for (int i = 0; i < animalVector.size(); i++)
    {
        animalVector[i]->make_noise();
    }

    for (int i = 0; i < animalVector.size(); i++)
    {
        delete animalVector[i];
    }
}