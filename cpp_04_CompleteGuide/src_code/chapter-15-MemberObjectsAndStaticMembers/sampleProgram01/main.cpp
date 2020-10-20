#include <iostream>
#include <iomanip>
#include "daytime.h"
#include "result.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    DayTime d1(13, 49, 30),
            d2(18, 30, 00);

    d1.print();
    d2.print();

    cout << "d1 == d2? " << boolalpha << d1.isEqual(d2) << endl;
    cout << "d1 < d2?  " << boolalpha << d1.isLess(d2)  << endl;

    Result r1,
           r2(1.0),
           r3(2.0, 18, 30, 11);
    r1.print();
    r2.print();
    r3.print();

    return 0;
}
