#include <cstdlib>
#include <iostream>
#include "daytime.h"

using namespace std;

int main()
{
    // testing class DayTime
    DayTime d1,
            d2(6, 30, 0),
            d3(18, 10, 15);

    DayTime arr[] =
    {
      d1,
      d2,
      d3,
      DayTime(2, 10, 30)
    };

    for(int i=0; i < 4; ++i)
    {
        std::cout << "before ++DayTime: ";
        arr[i].print();
        ++arr[i];
        std::cout << "after  ++DayTime: ";
        arr[i].print();
    }

    if(d1 < d2)
        std::cout << "d1 < d2" << std::endl;
    else
        std::cout << "d1 >= d2" << std::endl;

    std::system("pause");

    return 0;
}
