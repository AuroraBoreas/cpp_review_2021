#include <iostream>
#include "account.h"

using namespace std;

Account* clone(const Account* pK);

int main()
{
    cout << "\nDynamically created objects.\n" << endl;
    // allocate storage
    Account *ptrA1, *ptrA2, *ptrA3;

    ptrA1 = new Account; // default parameterized constructor
    cout << *ptrA1 << endl; // OK? YES
    ptrA1->setNumber(302010);
    ptrA1->setName("SCY");
    ptrA1->setState(2345.87);
    cout << *ptrA1 << endl;

    // use constructor with three args
    ptrA2 = new Account("Liang, Zhang", 7531357, 999.99);
    cout << *ptrA2 << endl;

    ptrA3 = clone(ptrA1);
    cout << "\ncopy of the first account: "
         << *ptrA3
         << endl;

    // release memory
    delete ptrA1;
    delete ptrA2;
    delete ptrA3;

    return 0;
}

Account* clone(const Account* pK)
{
    return new Account(*pK); // dereference-> copy constructor->dynamically allocating memory in heap
}
