#include <iostream>
#include "datetime.h"
using namespace std;

int main()
{
    DateTime d1,
             d2(8, 30, 10);

    cout << d1 << endl;
    d1.setDate();
    cout << d1 << endl;
    cout << d2 << endl;

    // ptr
    DateTime *dPtr = &d1,
            **pPtr = &dPtr;

    // dereference
    dPtr->setDate();
    cout << *dPtr << endl;
    (**pPtr).setDate(16, 00, 10);
    cout << (**pPtr) << endl;

    cout << "demo of array notations \n";
    // array notations
    DateTime arr[5] = {d1, d2, DateTime(15,30,10), DateTime(), DateTime(7,30,05)};
    // address notation
    int i;
    for(i=0; i<5; ++i)
    {
        cout << *(arr + i) << endl;
    }
    // index notation
    for(i=0; i<5; ++i)
    {
        cout << arr[i] << endl;
    }
    // pointer notation
    DateTime *ptr = arr;
    for(i=0; i<5; ++i)
    {
        cout << *ptr << endl;
        ptr++;
    }

    return 0;
}
