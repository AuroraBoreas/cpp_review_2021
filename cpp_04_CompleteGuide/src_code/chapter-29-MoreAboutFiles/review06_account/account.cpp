#include "account.h"
#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;

Account::Account()
{
    nr = 0L; name = "noname"; balance = 0.0;
}

Account::Account(long n=0L, const string& s_name="", double w=0.0)
: nr(n), name(s_name), balance(w) {}

const string Account::asString(void) const
{
    stringstream ss;
    ss << "\n-----------------"
       << "\nnumber   : " << nr
       << "\nname     : " << name
       << "\nbalance  : " << std::fixed << std::setprecision(2) << balance;
    return ss.str();
}
