#include <boost/fusion/adapted/struct.hpp>
#include <boost/fusion/include/for_each.hpp>
#include <boost/phoenix/phoenix.hpp>
using boost::phoenix::arg_names::arg1;

#include <string>
#include <iostream>

struct A
{
    int a;
    int b;
    std::string c;
};

struct B
{
    char a;
    char b;
    char c;
    int d;
    std::string e;
};

BOOST_FUSION_ADAPT_STRUCT(A, (int,a) (int,b) (std::string,c));
BOOST_FUSION_ADAPT_STRUCT(B, (char,a) (char,b) (char,c) (int,d) (std::string,e));

int main()
{
    const A _a = { 1, 42, "The Answer To Laifu" };
    const B _b = { 'a', 'b', 'c', 42, "Wasabi" };

    boost::fusion::for_each(_a, std::cout << arg1 << "\n");
    boost::fusion::for_each(_b, std::cout << arg1 << "\n");
}