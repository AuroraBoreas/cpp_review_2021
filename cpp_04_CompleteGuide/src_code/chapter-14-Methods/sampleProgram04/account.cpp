#include "account.h"
using namespace std;

// implementation of methods in `source file` works too.

// OK, three modular design pattern work as expected. @ZL, 20201016
bool Account::setName(const string& s)
{
    if(s.size() < 1)
        return false;
    name = s;
    return true;
}
