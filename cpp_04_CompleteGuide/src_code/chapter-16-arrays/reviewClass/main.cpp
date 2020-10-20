#include <iostream>
#include "daytime.h"
#include "result.h"

using namespace std;

int main()
{
    // test class DayTime
    DayTime d1,
            d2(6,30,0),
            d3(d2);

    d2.setHour(9);
    cout << "d1 < d2? " << boolalpha << d1.isLess(d2) << endl;

    d1.print();
    d2.print();
    d3.print();
    // test class Result
    Result r1,
           r2(10.0, d2),
           r3(r2);
    r1.print();
    r2.print();
    r3.print();
    r1.setMin(11.0);
    std::cout << r1.getMin() << std::endl;

    Result r4, r5, r6(9.9, d2);
    Result r7, r8, r9(r5);

    return 0;
}
