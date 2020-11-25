#include <iostream>
#include "car.h"
using namespace std;

int main()
{
    SUV mySUV = SUV(8, 301., "SVIP", true, 1234567, "XIAOMI");

    mySUV.display();

    return 0;
}
