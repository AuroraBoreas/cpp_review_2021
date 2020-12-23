#include <iostream>

using namespace std;

int main()
{
    int a;  // lvalue
    int *ptr = &a; // ptr is lvalue, a is rvalue
    a = 1; // 1 is rvalue

    std::cout << a << std::endl;
    std::cout << ptr << std::endl;


    return 0;
}
