// P275
#include <iostream>
#include <string>

#include "account.h"

bool getAccount(Account* pAccount);

int main()
{
    Account current1, current2, *ptr = &current1;
    ptr->init("Cheer, Mary", 3512345, 99.40);
    ptr->display();

    ptr = &current2;
    if(getAccount(ptr))
        ptr->display();
    else
        cout << "Invalid input!" << endl;

    return 0;
}

bool getAccount(Account* pAccount)
{
    string name, line(50, '-');
    unsigned long nr;
    double startCapital;

    cout << line << '\n'
         << "Enter data for a new account: \n"
         << "Account holder: ";

    if(!getline(cin, name) || name.size()==0)
        return false;

    cout << "Account number:  ";
    if(!(cin >> nr)) return false;
    cout << "Starting capital: ";
    if(!(cin >> startCapital)) return false;
    // all input OK
    pAccount->init(name, nr, startCapital);
    return true;
}

