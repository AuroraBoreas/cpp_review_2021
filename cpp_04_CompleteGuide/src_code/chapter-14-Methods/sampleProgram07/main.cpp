#include <iostream>
#include "daytime.h"

using namespace std;

int main()
{
    DayTime d1(16, 9, 30),
            d2(20, 30, 55);
    cout << "d1 = ";
    d1.repr();
    cout << "d2 = ";
    d2.repr();

    // Class_id* const this = &actObj on P302;
    cout << "d1 address(&actObj): " << &d1 << endl;
    cout << "d2 address(&actObj): " << &d2 << endl;


    cout << "d1 < d2? " << boolalpha << (d1.isLess(d2)) << endl;

    cout << "swap d1, d2" << endl;
    d1.swap(d2);
    cout << "d1 = ";
    d1.repr();
    cout << "d2 = ";
    d2.repr();
    return 0;
}
