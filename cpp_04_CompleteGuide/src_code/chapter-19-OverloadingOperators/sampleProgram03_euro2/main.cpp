#include <iostream>
#include "euro.h"

using namespace std;

int main()
{
    Euro e1, e2(33, 10), e3(10.01), e4(-e2);
    Euro arr[] = {e1, e2, e3, e4};

    for(int i=0; i < 4; ++i)
    {
        cout << "e" << (i + 1) << ": " << arr[i].asString() << endl;
        arr[i].print(cout);
    }

    e1+=e2;
    cout << "e1: " << e1.asString() << endl;

    return 0;
}
