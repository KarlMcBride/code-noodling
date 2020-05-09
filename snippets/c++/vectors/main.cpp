#include <algorithm>
#include <iostream>
#include <vector>

void iteratePrint(std::vector<int> _vector)
{
    for(std::vector<int>::iterator iterator = _vector.begin(); iterator != _vector.end(); ++iterator)
    {
        std::cout << *iterator << " ";
    }
    std::cout << std::endl;
}


int main()
{
    std::cout << "Vector Example" << std::endl;

    std::vector<int> intVector;
    intVector.push_back(2);
    intVector.push_back(5);
    intVector.push_back(3);
    intVector.push_back(4);
    intVector.push_back(1);

    std::cout << "Initial vector: ";
    iteratePrint(intVector);

    std::cout << "vector std::less: ";
    std::sort(intVector.begin(), intVector.end(), std::less<int>());
    iteratePrint(intVector);

    std::cout << "vector std::greater: ";
    std::sort(intVector.begin(), intVector.end(), std::greater<int>());
    iteratePrint(intVector);

    return 0;
}