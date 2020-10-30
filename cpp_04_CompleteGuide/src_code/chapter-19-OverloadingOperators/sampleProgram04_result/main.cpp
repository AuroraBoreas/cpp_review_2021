#include <iostream>
#include <iomanip>
#include "daytime.h"

using namespace std;

int main()
{
    DayTime d1, d2(6,30,0), d3(8,30,0), d4(d2);
    DayTime arr[4] = { d1, d2, d3, d4};

    for(int i=0; i < 4; ++i)
    {
        cout << "d" << (i+1) << ": " << arr[i].asString() << endl;
        arr[i].print(cout);
    }

    cout << "d1 < d2 : " << boolalpha << (d1 < d2) << endl;
    cout << "d2 == d4 : " << boolalpha << (d2 == d4) << endl;

    return 0;
}
