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

    cout << "d1 < d2? " << boolalpha << (d1.isLess(d2)) << endl;

    return 0;
}
