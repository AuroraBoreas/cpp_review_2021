#include <iostream>
#include <iomanip>
#include "daytime.h"

using namespace std;

int main()
{
    DayTime v, w(06, 30, 10);
    v.setDayTime();

    v.print();
    w.print();

    std::cout << std::boolalpha << v.isEqual(w) << std::endl;

    return 0;
}
