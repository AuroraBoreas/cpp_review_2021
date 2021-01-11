#include <iostream>
#include <string>

using namespace std;

void foo(int x)
{
    std::cout << x << std::endl;
}

//void foo(const int& x)
//{
//    std::cout << x << std::endl;
//}

void foo(int&& x)
{
    std::cout << x << std::endl;
}

class A
{

};

int add(int a, int b) noexcept
{
    return a + b;
}

int main()
{
    int a = 42;
    foo(a); // not OK. why? compiler sees foo(int), foo(int&) as same

    std::string name = R"(\n\n\n嫖疏)";   // raw string
    std::string jap = u8"こんにちは";      // UTF-8
    std::cout << name << jap << std::endl;

    std::cout << add('s', 'b') << std::endl;

    return 0;
}
