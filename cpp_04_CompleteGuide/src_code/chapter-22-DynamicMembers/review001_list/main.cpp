#include <iostream>
#include "date.h"

using namespace std;

int main()
{
    Date d1, d2(2020, 11, 3);
    d1.setDate();
    cout << d1 << endl;
    cout << d2 << endl;
    cout << (d1 < d2) << endl; // false
    cout << (d1 == d2) << endl; // false

    return 0;
}
