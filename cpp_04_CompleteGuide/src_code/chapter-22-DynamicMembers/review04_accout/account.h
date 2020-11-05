#ifndef ACCOUNT_H_INCLUDED
#define ACCOUNT_H_INCLUDED

#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class Account
{
    private:
        string name;
        unsigned long nr;
        double balance;
        static int objCounter;
    public:
        // declaration -- constructors ACDD
        Account();
        Account(const string& s_name, unsigned long s_nr, double s_balance); // parameterized constructor with default args
        Account(const Account&); // copy-constructor
        // destructor?
        ~Account(void);
        // getter
        string getName(void)      const { return name; }
        unsigned long getNo(void) const { return nr; }
        double getBalance(void)   const { return balance; }
        static int getObjCounter(void)  { return objCounter; }
        // setter
        void setName(const string& s) { name = (s.size()<1)? "noname" : s; }
        void setNo(unsigned long n)   { nr = n; }
        void setBalance(double w)     { balance = w; }
        // repr, using global ostream op ol
        friend ostream& operator<<(ostream& os, const Account& a)
        {
            stringstream ss;
            ss << "\n --- Account Info --- \n"
               << "\nAccount name      : " << a.name
               << "\nAccount number    : " << fixed << a.nr
               << "\nAccount balance($): " << fixed << setprecision(2) << a.balance;
            os << ss.str();
            return os;
        }
};

#endif // ACCOUNT_H_INCLUDED
