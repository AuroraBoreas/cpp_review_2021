/*

SL tuple review

+ what is tuple?
    - tuple is an extend concept of pair
    - "superset"
    - differs from pair<>s, tuple may have a lot of Ts
    - maybe tuple shares same concept with tuple in python..
    - idk

+ manipulation
    - create. using std::tuple<typename... Types>, or std::make_tuple<[optional]>();
    - member access. using std::get<index>();
    - std::tuple_size<tupletype>::value. get the number of element inside tuple;
    - std::tuple_element<tupletype>::type. get the type of element

+ print out a tuple
    - no builtin function exists
    - boost
    - user-defined recursive function using template


+ implementation of tuple in std
    - it is important to notice that keyword explicit specifier in constructors.
    - it means no implicit initializer list is allowed

    ```c++11

    template<typename... Types>
    class tuple
    {
        public:
            explicit tuple(const Types&... Args);
            template<UTypes>
            explicit tuple(const Types&... args, const UTypes&... uargs>);
            ...
    }

    ```
*/
#include <iostream>
#include <tuple>
#include <string>
#include <memory>

typedef std::tuple<char, short, int, long, float, double, std::string> csilfd;
typedef std::tuple<int, float> ift;

int main()
{
    // create a tuple
    csilfd t1{'c', 128, 12345, 1234567890L, 3.14, 2.718, "bonjour"}; // OK
    ift t2(42, 3.1415);     // OK
    // ift t3 = {42, 3.1415};  // not OK

    // also using std::make_tuple<>()
    auto t4 = std::make_tuple(42, 3.14); // implicit
    auto t5 = std::make_tuple<int, std::string>(1, "hello"); // explicit
    std::tuple<int, double> t6 = std::make_tuple(42, 3.14); // explicit


    // member access
    std::get<0>(t2); // 42
    int i; float f;
    std::make_tuple(std::ref(i), std::ref(f)) = t2; // extract members from a tuple
    // or
    std::tie(i, f) = t2; // works as well. std::tie() makes Ref to var thou


    // number of elements, type of specified element
    std::tuple_size<ift>::value;        // 2
    // std::tuple_element<0, ift>::type;   // int. but not work in mingw32-g++11

    // combine
    int n;
    auto t7 = std::tuple_cat(std::make_tuple(42, 3.14, "hello"),
                             std::make_pair('a', "world!"),
                             std::tie(n));


    return 0;
}
