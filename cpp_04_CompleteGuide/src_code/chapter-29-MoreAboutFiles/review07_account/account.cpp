#include "account.h"
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

Account::Account()
{
    nr = 0L; name = "noname"; balance = 0.0;
}

Account::Account(long n=0L, const string& s_name="", double w=0.0)
: nr(n), name(s_name), balance(w){}

string Account::asString(void) const
{
    stringstream ss;
    ss << "\n----Account Info-------"
       << "\nnumber     : " << nr
       << "\nname       : " << name
       << "\nbalance($) : " << std::fixed << std::setprecision(2) << balance;
    return ss.str();
}
