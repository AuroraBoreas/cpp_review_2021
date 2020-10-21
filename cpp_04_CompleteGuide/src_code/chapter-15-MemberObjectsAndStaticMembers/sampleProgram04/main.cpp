#include <iostream>
#include "daytime.h"
#include "result4.h"

using namespace std;

int main()
{
//    cout << "Hello world!" << endl;
//    DayTime morning(6, 0, 0);
//    Result r1,
//           r2(1.0, morning),
//           r3(2.0, 8, 30, 0);
//
//    r1.print();
//    r2.print();
//    r3.print();

    DayTime d1(6, 30, 0);

    Result temp1, temp2(2.1, d1);

    Result temperatureTab[24] =
    {
        Result(-2.5, 0, 30, 30),
        Result(3.5),
        4.5,
        Result(temp1),
        temp2
    };

    int cnt = sizeof(temperatureTab) / sizeof(Result); // hmm, not working?
    std::cout << "size = " << cnt << std::endl;
    for(int i=0; i < cnt; ++i)
        temperatureTab[i].print();

    std::cout << std::endl;

    return 0;
}
