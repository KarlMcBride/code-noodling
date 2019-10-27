#include <functional>
#include <queue>
#include <vector>
#include <iostream>

template<typename T> void print_queue(T& q)
{
    while(!q.empty())
    {
        std::cout << q.top() << " ";
        q.pop();
    }
    std::cout << '\n';
}

int main()
{
    std::cout << "q1: default sort" << std::endl;
    std::priority_queue<int> q1;

    for(int n : {1,8,5,6,3,4,0,9,7,2})
    {
        q1.push(n);
    }

    std::cout << "q1: ";
    print_queue(q1);


    std::cout << "q2: inverted sort using operator" << std::endl;
    std::priority_queue<int, std::vector<int>, std::greater<int> > q2;

    for(int n : {1,8,5,6,3,4,0,9,7,2})
    {
        q2.push(n);
    }

    std::cout << "q2: ";
    print_queue(q2);


    // Using lambda to compare elements.
    std::cout << "q3: lamba-sorted queue" << std::endl;
    auto cmp = [](int left, int right) { return (left ^ 1) > (right ^ 1); };
    std::priority_queue<int, std::vector<int>, decltype(cmp)> q3(cmp);

    for(int n : {1,8,5,6,3,4,0,9,7,2})
    {
        q3.push(n);
    }

    std::cout << "q3: ";
    print_queue(q3);
}
