#include <cstddef>
#include <iostream>
#include <vector>

namespace lec11
{

template <typename T> //parametrization with type
T max(T a, T b)
{
    return (a > b) ? a : b;
}

template <std::size_t n>
std::size_t print_num()
{
    std::cout << n << std::endl;
}

void print_example()
{
    print_num<4>();
}

//Compile-time factorial
template <std::size_t n> //parametrization with value
std::size_t factorial() 
{
    return n * factorial<n - 1>();
}

//compilation will fail if base case is not defined
template <>
std::size_t factorial<1>()
{
    return 1;
}

std::size_t fact()
{
    return factorial<5>();
}
}

enum Color
{
    red,
    green,
    blue
};

template <Color val>
void enum_func()
{
    std::cout << val << std::endl;
}

void some_func()
{
    std::cout << "hello from some_func() " << std::endl;
}

//can be pointer to function
template <void(*ptr)()>
void func_ptr_func()
{
    ptr();
}

//can be address of an object with static storage duration
template <const char* val>
void char_func()
{
    std::cout << val << std::endl;
}

//ERROR! floating point types are not allowed until C++20
/*
template <float val>
void float_func()
{
}
*/

//ERROR! class-type objects are not allowed
/*
template <std::string s>
void string_func()
{
}
*/

int main()
{
    lec11::print_example();

    std::cout << "factorial " << lec11::fact() << std::endl;

    enum_func<Color::red>();


    func_ptr_func<some_func>();

    static const char str[] = "hello";
    char_func<str>();
    //char_func<"hello">(); //ERROR! literals are not allowed

    return 0;
}
