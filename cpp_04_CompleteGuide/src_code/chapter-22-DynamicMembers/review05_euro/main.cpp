#include <iostream>
#include "euro.h"

using namespace std;

int main()
{
    Euro e1, e2(3, 10), e3(-e2);

    e1 + e2;

    e1 += e2;

    e1 = e2 + 6.0;

    e1 = 6 + e2; // Error? OK. global op ol

    return 0;
}
