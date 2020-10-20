#include <iostream>
#include "daytime.h"
#include "result4.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    DayTime morning(6, 0, 0);
    Result r1,
           r2(1.0, morning),
           r3(2.0, 8, 30, 0);

    r1.print();
    r2.print();
    r3.print();

    return 0;
}
