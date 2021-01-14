/*

pair cls

+ what does pair cls do?
    - treat two elements as one unit
+ pair cls
    - pair(const T& a, const T& b); // regular constructor
    - template<typename U, typename V>pair(U&& x, V&& y);
    - template<typename... Args1, typename... Args2>pair<piecewise_constructor_t, tuple<Args1...> first_args, tuple<Args2...> second_args);
+ std::make_pair()
    - create a pair with specifying types(implicit deduction)
    - std::make_pair() even works when types do not match..
    - why:
    template<template T1, template T2>
    pair<T1, T2> make_pair(const T1& x, const T2& y){ return pair<T1, T2>(x, y); }

    // c++11
    template<template T1, template T2>
    pair<V1, V2> make_pair(T1&& x, T2&& y);

*/

#include <iostream>
#include <utility>
#include <tuple>
#include <string>
#include <functional>

using namespace std;

class Foo
{
public:
    Foo(tuple<int, float>)
    {
        std::cout << "Foo::Foo(tuple)" << std::endl;
    }
    template<typename... Args>
    Foo(Args... args)
    {
        std::cout << "Foo::Foo(args...)" << std::endl;
    }
};

int add(int a, int b)
{
    return (a + b);
}

int main()
{
    // create tuple t
    std::tuple<int, float> t(1, 2.718);
    // pass the tuple  as a whole to the constructor of Foo
    std::pair<int, Foo> p1(42, t);
    // pass the elements of the tuple to the constructor of Foo
    std::pair<int, Foo> p2(std::piecewise_construct, std::make_tuple(42), t);

    // std:make_pair()
    auto p3 = std::make_pair(42, "hello world");
    // std::get<>();
    std::cout << std::get<1>(p3) << std::endl;
    std::cout << p3.first << std::endl;
    // move semantics in c++11
    std::string s1 = "", t1 = "";
    auto p4 = std::make_pair(std::move(s1), std::move(t1));

    // explicit and implicit type description has different result though
    auto p5 = std::make_pair(42, 7.77);               // implicit. double
    auto p6 = std::make_pair<int, float>(42, 7.77);   // explicit. float
    // if(p5 == p6); // not OK.

    int res = std::bind(add, 3, 4)();
    std::cout << res << std::endl;

    return 0;
}
