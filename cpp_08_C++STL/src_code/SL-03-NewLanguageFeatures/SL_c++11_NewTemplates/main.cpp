/*
new template features

- variadic templates

- alias templates

- templates with default args

*/

#include <iostream>
#include <bitset>

using namespace std;

// version 1

//void print(){}
//
//template<typename T, typename... Types>
//void print(const T& firstArg, const Types&... args)
//{
//    std::cout << firstArg << std::endl;
//    print(args...);
//}

// version 2

template<typename T>
void print(const T& arg)
{
    std::cout << arg << std::endl;
}

template<typename T, typename... Types>
void print(const T& firstArg, const Types&... args)
{
    std::cout << firstArg << std::endl;
    print(args...);
}

//template<typename T>
//using Vec = std::vector<T, MyAlloc<T>>;


int main()
{

    print(11, "hello world", bitset<16>(377), 3.14, CHAR_MAX);

    Vec<int> coll;
    // or
    // std::vector<int, MyAlloc<int>> coll;

    return 0;
}
