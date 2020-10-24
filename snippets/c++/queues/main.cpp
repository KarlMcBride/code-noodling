#include <iostream>
#include <queue>
#include <string>

void print_and_clear_queue(std::string p_message, std::queue<std::string>& p_queue)
{
    std::cout << p_message << std::endl;
    while(!p_queue.empty())
    {
        std::cout << "    " << p_queue.front() << std::endl;
        p_queue.pop();
    }
}

int main()
{
    std::queue<std::string> local_queue;
    local_queue.push("1");
    local_queue.push("2");
    local_queue.push("3");
    local_queue.emplace("4");
    local_queue.emplace("5");

    std::cout << "Queue size @ line " << __LINE__ << ": " << local_queue.size() << std::endl;
    print_and_clear_queue("Local queue contents:", local_queue);

    return 0;
}