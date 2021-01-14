/*
utilities

+ clock and timer,      <ctime>
+ numeric               <numeric>
+ pair and tuple,       <tuple>
+ smart pointers,       <memory>
+ ratio                 <ratio>
+ type traits and type utilities

*/

#include <iostream>
#include <bitset>
#include <tuple>

using namespace std;

template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& p)
{
    return os << "[" << p.first << "," << p.second << "]";
}

void print(){};

template<typename T, typename... Types>
void print(const T& firstArg, const Types&... args)
{
    std::cout << firstArg << std::endl;
    print(args...);
}

int main()
{
    // parameter array
    print(3.14, 11, "hello", std::bitset<16>(377), 'a');

    // pair
    typedef std::pair<int, float> IntFloatPair;
    IntFloatPair p(42, 3.14);

    std::cout << std::get<0>(p) << std::endl;
    std::cout << p.first << std::endl;
    std::cout << std::get<1>(p) << std::endl;

    std::cout << std::tuple_size<IntFloatPair>::value << std:: endl;
    // std::cout << (std::tuple_element<0,IntFloatPair>::type) << std::endl;

    return 0;
}
