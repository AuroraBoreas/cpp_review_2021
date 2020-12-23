#include <iostream>
#include <iomanip>
#include "time.h"
#include "date.h"

int main()
{
    // test cls Time
    Time t1, t2(8, 0, 0), t3(16, 35, 0),
         arr[] = { t1, t2, t3 };

    for(int i=0; i<3; ++i)
        std::cout << arr[i] << std::endl;

    std::cout << "the original: ";
    std::cout << t1 << std::endl;
    t1.setTime();
    std::cout << "after: ";
    std::cout << t1 << std::endl;

    std::cout << "\nt1 < t2 " << std::boolalpha << (t1 < t2) << std::endl;

    // test cls Date
    std::cout << std::endl;
    Date d1, d2(2020, 1, 1), d3(2021, 1, 1),
         darr[] = { d1, d2, d3 };
    for(int i=0; i<3; ++i)
        std::cout << darr[i] << std::endl;

    d1.setDate();
    std::cout << d1 << std::endl;

    std::cout << "\nd1 < d3 " << std::boolalpha << (d1 < d3) << std::endl;

    return 0;
}
