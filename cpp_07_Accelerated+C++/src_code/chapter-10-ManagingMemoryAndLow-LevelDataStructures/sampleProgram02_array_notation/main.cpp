#include <iostream>
#include <iomanip>
#include "datetime.h"

using namespace std;

int main()
{
    DateTime dt1(2021, 1, 6, 8, 30, 0),
             dt2(2020, 1, 6, 8, 30, 0);
//    cout << dt1 << endl;
//    cout << dt2 << endl;
//    cout << std::boolalpha << (dt1 < dt2) << endl;

    DateTime dtArr[] = { dt1, dt2 };
    // address notation
    cout << "\narray address notation\n";
    int i;
    for(i=0; i<2; ++i)
    {
        cout << *(dtArr+i) << endl;
    }
    // index notation
    cout << "\narray index notation\n";
    for(i=0; i<2; ++i)
        cout << dtArr[i] << endl;
    // pointer notation
    cout << "\narray pointer notation\n";
    DateTime *ptr = &dtArr[0];
    for(i=0; i<2; ++i)
    {
        cout << *ptr << endl; ++ptr; // pointer arithmetic
    }

    return 0;
}
