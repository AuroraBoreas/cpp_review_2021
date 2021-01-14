/*

tuple

+ what?
    // definition, < c++11
    template <typename T0 = ..., typename T1 = ..., typename T2 = ...,
            typename T3 = ..., typename T4 = ..., typename T5 = ...,
            typename T6 = ..., typename T7 = ..., typename T8 = ...,
            typename T9 = ...>
    class tuple;

    // definition, >= c++11
    template<typename... Types>
    class tuple;

*/

#include <iostream>
#include <bitset>
#include <tuple>
#include <string>
#include <complex>

using namespace std;

// usage of variadic template

template<typename T>
void print(const T& x)
{ std::cout << x << std::endl; }

template<typename T, typename... Types>
void print(const T& firstArg, const Types&... args)
{
    std::cout << firstArg << std::endl;
    print(args...);
}

int main()
{
    // review variadic template
    print(11, 3.14, "hello world!", std::bitset<16>(377), 'a');
    // create a tuple
    std::tuple<std::string, int, std::bitset<16>, std::complex<double>> t;
    // create and initialize a tuple
    std::tuple<int, float, std::string> t1{41, 6.3, "nico"};
    // iterate over elements:
    std::cout << std::get<0>(t1) << " ";
    std::cout << std::get<1>(t1) << " ";
    std::cout << std::get<2>(t1) << " ";
    std::endl;

    // create tuple with make_tuple()
    auto t2 = std::make_tuple(22, 44, "nico");

    // assign second value in t2 to t1
    std::get<1>(t1) = std::get<1>(t2);

    // comparison
    if(t1 < t2)
    {
        t1 = t;
    }

    return 0;
}
