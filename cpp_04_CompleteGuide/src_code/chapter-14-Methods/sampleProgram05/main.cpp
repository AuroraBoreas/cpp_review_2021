#include <iostream>
#include "account.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    Account myAccount1, *ptr = &myAccount1;
    myAccount1.display();
    cout << myAccount1.getState() << endl;

    Account myAccount2("ZL", 1000001, 1000000000.00);
    cout << myAccount2.getNr() << endl;

    ptr->setName("ZL");
    ptr->setState(100000000000000.00);
    ptr->display();
    (*ptr).display();

    return 0;
}
