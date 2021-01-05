#include <iostream>
#include "square.h"

int main()
{
    // 4.6-exercise 4-2
    typedef MyVec<int> MyVecInt;
    MyVecInt mvi(10);
    mvi.display();

    // 4.6-exercise 4-4
    typedef MyVec<double> MyVecDo;
    MyVecDo mvd(100);
    mvd.display();

    return 0;
}
