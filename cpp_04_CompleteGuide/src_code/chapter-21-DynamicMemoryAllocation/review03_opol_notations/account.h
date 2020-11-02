#ifndef ACCOUNT_H_INCLUDED
#define ACCOUNT_H_INCLUDED

#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class Account
{
    private:
        string name; unsigned long nr; double balance;
    public:
        // constructor
        Account(const string& s_name="noname", unsigned long s_nr=111, double s_balance=0.0)
        : name(s_name), nr(s_nr), balance(s_balance) {}
        // getter, setter
        string getName(void)          const { return name; }
        unsigned long getNumber(void) const { return nr; }
        double getBalance(void)       const { return balance; }
        void setName(const string s)    { name = (s.size()<1)? "noname" : s; }
        void setNumber(unsigned long n) { nr = n; }
        void setBalance(double x)       { balance = x; }
        // repr
        string asString(void) const
        {
            stringstream ss;
            ss << "\n--- Account Info ---"
               << "\nAccount name   : " << name
               << "\nAccount number : " << nr
               << "\nAccount balance: " << balance;
            return ss.str();
        }
        // global, overload io operator
        friend ostream& operator<<(ostream& os, const Account& a)
        { os << a.asString(); return os; }

};

#endif // ACCOUNT_H_INCLUDED
