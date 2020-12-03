#include <iostream>
#include <iomanip>
#include "datetime.h"

using namespace std;

int main()
{
    // unittest
    Date d1(2020, 12, 1);
    cout << "\nd1  : " << d1 << endl;

    Time t1(11, 31, 10);
    cout << "\nt1  : ";
    t1.display();

    DateTime dt1, dt2(2020, 12, 1, 9, 30, 10);
    // init
    cout << "\ndt1 : ";
    dt1.display();
    cout << "\ndt2 : ";
    dt2.display();
    // set datetime
    dt1.setDateTime();
    cout << "\ndt1 : ";
    dt1.display();
    // set time
    DateTime dt3(1950, 11, 10, 8, 30, 5);
    dt3.setTime();
    cout << "\ndt3 : ";
    dt3.display();
    // set date
    dt3.setDate();
    cout << "\ndt3 : ";
    dt3.display();
    cout << "\ndt1 < dt2 : ";
    cout << std::boolalpha << (dt1 < dt2) << endl;

    return 0;
}
