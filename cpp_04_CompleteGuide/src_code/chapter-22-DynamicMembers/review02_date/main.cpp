#include <iostream>
#include <iomanip>
#include "date.h"

using namespace std;

int main()
{
    Date d1, d2(2020, 13, 03);
    d1.setDate();

    std::cout << d1 << std::endl;
    std::cout << d2 << std::endl;

    std::cout << std::boolalpha << (d1 < d2) << std::endl;

    return 0;
}
