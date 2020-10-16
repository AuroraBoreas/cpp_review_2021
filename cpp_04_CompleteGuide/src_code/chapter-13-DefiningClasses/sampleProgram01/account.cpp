#include "account.h"
#include <iostream>
#include <iomanip>

using namespace std;

bool Account::init(const string& i_name,
                   unsigned long i_nr,
                   double        i_balance)
{
    if(i_name.size() < 1)
        return false;

    name    = i_name;
    nr      = i_nr;
    balance = i_balance;
    return true;
}

void Account::display()
{
    cout << fixed << setprecision(2)
         << "--------------------------------------\n"
         << "Account holder:    " << name << '\n'
         << "Account number:    " << nr   << '\n'
         << "Account balance:   " << balance << '\n'
         << "--------------------------------------\n"
         << endl;
}
