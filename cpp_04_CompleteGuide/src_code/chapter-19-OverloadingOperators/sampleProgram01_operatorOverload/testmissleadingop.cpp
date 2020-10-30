#include <iostream>
#include <iomanip>
#include "misleadingop.h"

int main()
{
    MyClass m1(1), m2(2);
    std::cout << "1 < 2 == " << std::boolalpha << (m1 < m2) << std::endl;
    std::cout << "1 + 2 == " << m1 + m2 << std::endl;

    return 0;
}
