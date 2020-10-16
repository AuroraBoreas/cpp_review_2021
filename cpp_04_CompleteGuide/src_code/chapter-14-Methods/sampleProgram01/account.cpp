#include "account.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

Account::Account(const string& a_name,
                 unsigned long a_nr,
                 double a_state)
{
    name  = a_name;
    nr    = a_nr;
    state = a_state;
}

Account::Account(const string& a_name)
{
    name  = a_name;
    nr    = 11111;
    state = 0.0;
}

bool Account::init(string& a_name, unsigned long a_nr, double a_state)
{
    if(a_name.size() < 1)
        return false;
    name  = a_name;
    nr    = a_nr;
    state = a_state;
    return true;
}

void Account::display()
{
    cout << fixed << setprecision(2);

    cout << "\n----- account info -----" << endl
         << "name: " << name << endl
         << "account: " << nr << endl
         << "state: " << state << endl;
}
