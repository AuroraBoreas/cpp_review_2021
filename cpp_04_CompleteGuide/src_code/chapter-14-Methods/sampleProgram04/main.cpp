#include <iostream>
#include "account.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    Account myAccount1;
    myAccount1.display();

    Account* ptr = &myAccount1;
    // const Account* ptr = &myAccount1; // exception due to const keyword. P298
    ptr->setName("ZL");
    cout << ptr->getName() << endl;

    return 0;
}
