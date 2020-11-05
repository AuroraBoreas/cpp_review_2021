#include <iostream>
#include "account.h"

using namespace std;

int main()
{
    Account a1, a2("SCY, GSN", 100001, 99.99);

    Account arr[] = {
        a1,
        a2,
        Account(a1),
        Account("NMGB, CNM", 300011, 1009.90)
    };

    // test
    for(int i=0; i<4; ++i)
        cout << arr[i] << endl;


    return 0;
}
