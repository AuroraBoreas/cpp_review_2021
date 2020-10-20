#include <iostream>
#include "result3.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    cout << endl;

    DayTime morning(6, 45);
    Result temp1(6.45, morning),
           temp2(11.2, 12, 0, 0);

    temp1.print();
    temp2.print();

    return 0;
}
