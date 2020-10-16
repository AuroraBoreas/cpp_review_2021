#include <iostream>
#include <iomanip>

#include "account.h"

using namespace std;

int main()
{
    Account current1, current2;

    current1.init("Cheers, Mary", 1234567, -1200.99);
    current1.display();
    // current1.balance += 100; // exception due to private label

    current2 = current1; // OK. MUST be same class thou
    current2.display();

    current2.init("Jones, Tom", 3512347, 199.40); // reassignment
    current2.display();

    Account& mtr = current1;    // reference
    mtr.display();

    return 0;
}
