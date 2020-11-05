#include "account.h"
#include <string>
#include <iostream>
using namespace std;

// static class member
int Account::objCounter = 0;

// constructors
Account::Account()
{
    name = "noname"; nr = 111; balance = 0.0;
    ++objCounter;
}

Account::Account(const string& s_name="noname",
                 unsigned long s_nr=111,
                 double s_balance=0.0)
: name(s_name), nr(s_nr), balance(s_balance)
{
    ++objCounter;
}

Account::Account(const Account& a)
: name(a.name), nr(a.nr), balance(a.balance)
{
    ++objCounter;
}

// destructor
Account::~Account()
{
    cout << "Account object No." << objCounter-- << " is destroyed.";
    cout << " there are " << objCounter << " left." << endl;
}
