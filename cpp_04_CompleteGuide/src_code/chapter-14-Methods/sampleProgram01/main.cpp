#include <iostream>
#include "account.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    Account a("ZL", 1234567, 123.00);
    a.display();

    // Account a; // exception
    Account b("SL");
    b.display();

    return 0;
}
