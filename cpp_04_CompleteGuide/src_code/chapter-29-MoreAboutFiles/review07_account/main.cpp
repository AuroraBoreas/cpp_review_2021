#include <iostream>
#include "account.h"

using namespace std;

int main()
{
    Account acc1,
            acc2(12345, "SCY", 99.99),
            acc3(54321, "ZL", 9999999999999.99),
            arr[3] = { acc1, acc2, acc3 };

    for(int i=0; i<3; ++i)
    {
        arr[i].display();
    }

    return 0;
}
