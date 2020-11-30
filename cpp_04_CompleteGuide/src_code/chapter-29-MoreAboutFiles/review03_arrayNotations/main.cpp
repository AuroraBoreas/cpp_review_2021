#include <iostream>
#include "datetime.h"

using namespace std;

int main()
{
    // test cls
    DateTime d1,
             d2(8, 10, 30);

    d1.display();
    d2.display();

    // test array notations
    DateTime arr[3] = { d1, d2, DateTime(9, 15, 05) };
    // address notation
    int i;
    for(i=0; i<3; ++i)
    {
        (arr + i)->display();
    }
    // index
    for(i=0; i<3; ++i)
    {
        arr[i].display();
    }
    // ptr
    DateTime* ptr = arr;
    for(i=0; i<3; ++i)
    {
        ptr->display();
        ++ptr;
    }

    return 0;
}
