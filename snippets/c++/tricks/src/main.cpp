#include <chrono>
#include <iostream>
#include <math.h>
#include <queue>
#include <string>

void avoiding_strlen(void)
{
    std::cout << __FUNCTION__ << std::endl;

    char char_array[] = { 'a', 'b', 'c', 'd' };

    for (int i = 0; char_array[i]; i++)
    {
        std::cout << "char_array[" << i << "]: " << char_array[i] << std::endl;
    }

    std::cout << std::endl;
}

void emplace_vs_push(void)
{
    std::cout << __FUNCTION__ << std::endl;

    std::queue<std::string> string_queue;
    const int num_of_iterations = 100000;
    const std::string string_to_add = "This is a test string to be added to the queue via emplace and push";

    std::chrono::steady_clock::time_point emplace_start = std::chrono::steady_clock::now();
    for (int index = 0; index < num_of_iterations; index++)
    {
        string_queue.emplace(string_to_add);
    }
    std::chrono::steady_clock::time_point emplace_end = std::chrono::steady_clock::now();
    std::chrono::duration<double> emplace_span = std::chrono::duration_cast<std::chrono::duration<double>>(emplace_end - emplace_start);
    std::cout << num_of_iterations << " emplaces took " << emplace_span.count() << " seconds" << std::endl;


    std::chrono::steady_clock::time_point push_start = std::chrono::steady_clock::now();
    for (int index = 0; index < num_of_iterations; index++)
    {
        string_queue.push(string_to_add);
    }
    std::chrono::steady_clock::time_point push_end = std::chrono::steady_clock::now();
    std::chrono::duration<double> push_span = std::chrono::duration_cast<std::chrono::duration<double>>(push_end - push_start);
    std::cout << num_of_iterations << " pushes took " << push_span.count() << " seconds" << std::endl;

    std::cout << std::endl;
}

void math_fast_multiplication_division_by_2(int _input)
{
    std::cout << __FUNCTION__ << std::endl;

    int mul_result = _input << 1;
    int div_result = _input >> 1;
    std::cout << "input: " << _input << ", input*2: " << mul_result << ", input/2: " << div_result << std::endl;

    std::cout << std::endl;
}

void math_most_significant_digit(int _input)
{
    std::cout << __FUNCTION__ << std::endl;

    double intermediate = log10(_input);
    intermediate = intermediate - floor(intermediate);
    int X = pow(10, intermediate);
    std::cout << "Most significant digit of " << _input << " is " << X << std::endl;

    std::cout << std::endl;
}

void math_number_of_bits(int _input)
{
    std::cout << __FUNCTION__ << std::endl;

    int num_of_bits = floor(log10(_input)) + 1;
    std::cout << "Number " << _input << " has " << num_of_bits << " bits" << std::endl;

    std::cout << std::endl;
}

void swap_via_xor(void)
{
    std::cout << __FUNCTION__ << std::endl;

    int num_1 = 12345;
    int num_2 = 99999;

    std::cout << "pre-swap,  num_1: " << num_1 << ", num_2: " << num_2 << std::endl;
    num_1 ^= num_2;
    num_2 ^= num_1;
    num_1 ^= num_2;
    std::cout << "post-swap, num_1: " << num_1 << ", num_2: " << num_2 << std::endl;

    std::cout << std::endl;
}

int main()
{
    std::cout << std::endl;

    avoiding_strlen();
    emplace_vs_push();
    math_fast_multiplication_division_by_2(256);
    math_most_significant_digit(284964);
    math_number_of_bits(12345);
    swap_via_xor();

    return 0;
}