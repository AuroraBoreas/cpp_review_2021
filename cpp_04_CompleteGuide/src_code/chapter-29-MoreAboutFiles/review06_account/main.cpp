#include <iostream>
#include "account.h"
using namespace std;

int main()
{
    Account acc1, acc2(12345, "SCY", 0.0);
    Account arr[3] = { acc1, acc2, Account(54321, "HelloWorld", 999.99) };

    for(int i=0; i<3; ++i)
    {
        arr[i].display();
    }

    return 0;
}
