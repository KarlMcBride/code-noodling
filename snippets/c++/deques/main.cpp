#include <algorithm>
#include <deque>
#include <iostream>
#include <string>

void print_forward_for_loop(std::deque<std::string> const& p_deque)
{
    std::cout << __FUNCTION__ << std::endl;

    for (int index = 0; index < p_deque.size(); index++)
    {
        std::cout << "    " << p_deque[index] << std::endl;
    }
}

void print_forward_iterator(std::deque<std::string> const& p_deque)
{
    std::cout << __FUNCTION__ << std::endl;
    for (auto iterator = p_deque.cbegin(); iterator != p_deque.cend(); ++iterator)
    {
        std::cout << "    " << *iterator << std::endl;
    }
}

void print_reverse_iterator(std::deque<std::string> const& p_deque)
{
    std::cout << __FUNCTION__ << std::endl;
    for (auto iterator = p_deque.crbegin(); iterator != p_deque.crend(); ++iterator)
    {
        std::cout << "    " << *iterator << std::endl;
    }
}

int main()
{
    std::deque<std::string> local_deque;
    local_deque.push_front("1");
    local_deque.push_front("2");
    local_deque.push_front("3");
    local_deque.push_back("4");
    local_deque.push_back("5");

    std::cout << "front: " << local_deque.front() << std::endl;
    std::cout << "back: " <<  local_deque.back() << std::endl;

    std::cout << "deque size @ line " << __LINE__ << ": " << local_deque.size() << std::endl;
    print_forward_for_loop(local_deque);
    print_forward_iterator(local_deque);
    print_reverse_iterator(local_deque);

    local_deque.pop_front();
    local_deque.pop_back();
    local_deque.erase(local_deque.begin() + 1);

    print_forward_for_loop(local_deque);

    return 0;
}