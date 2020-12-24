#include <iostream>
#include <iomanip>
#include "time.h"
#include "date.h"
#include "datetime.h"

int main()
{
    // test cls Time
    std::cout << "\ntest cls Time" << std::endl;
    Time t1, t2(8, 0, 0), t3(16, 35, 0),
         arr[] = { t1, t2, t3 };

    for(int i=0; i<3; ++i)
        std::cout << "t" << (i+1) << " = " << arr[i] << std::endl;

    std::cout << "the original: ";
    std::cout << t1 << std::endl;
    t1.setTime();
    std::cout << "after: ";
    std::cout << t1 << std::endl;

    std::cout << "\nt1 < t2 " << std::boolalpha << (t1 < t2) << std::endl;

    // test cls Date
    std::cout << "\ntest cls Date" << std::endl;
    Date d1, d2(2020, 1, 1), d3(2021, 1, 1),
         darr[] = { d1, d2, d3 };
    for(int i=0; i<3; ++i)
        std::cout << "d" << (i+1) << " = " <<  darr[i] << std::endl;

    d1.setDate();
    std::cout << d1 << std::endl;

    std::cout << "\nd1 < d3 " << std::boolalpha << (d1 < d3) << std::endl;

    // test cls DateTime
    std::cout << "\ntest cls DateTime" << std::endl;
    DateTime dt1(2022, 12, 31, 6, 10, 5), dt2(2020,1,1,8,30,0), dt3(2021, 1, 1, 16, 35, 10),
             dtarr[] = { dt1, dt2, dt3 };

    for(int i=0; i<3; ++i)
        std::cout << "dt" << (i+1) << " = " << dtarr[i] << std::endl;

    std::cout << "\ndt1 < dt3 " << std::boolalpha << (dt1 < dt3) << std::endl;

    return 0;
}
