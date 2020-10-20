#include <iostream>
#include "result.h"
#include "daytime.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    DayTime start(10, 15);
    Result m1(101.01, start),
           m2(m1),
           m3(99.9);
    // m2 = m3; // exception. const keyword in class definition.
    m2.setVal(100.9);
    cout << "\n Result Time \n"
         << "-------------------------" << endl;
         m1.print(); m2.print(); m3.print();

    return 0;
}
