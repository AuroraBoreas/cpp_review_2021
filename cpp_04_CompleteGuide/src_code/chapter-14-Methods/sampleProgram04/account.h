#ifndef ACCOUNT_H_INCLUDED
#define ACCOUNT_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Account
{
    private:
        string name;
        unsigned long nr;
        double state;

    public:
        Account(const string& a_name = "X",
                unsigned long a_nr   = 11111111,
                double a_state       = 0.0)
        {
            name    = a_name;
            nr      = a_nr;
            state   = a_state;
        };

        ~Account() {};

        const string& getName() { return name; }
        // is it possible to set this as interface? should be OK, why? consistency in design paradigm.
//        bool setName(const string& s)
//        {
//            if(s.size() < 1)
//                return false;
//            name = s;
//            return true;
//        }
        bool setName(const string&);
        // interact with date member
        unsigned long getNr() { return nr; }
        void setNr(unsigned long n) { nr = n; }
        // interact with date member
        double getState() { return state; }
        void setState(double x) { state = x; }

        void display(void);
};

inline void Account::display()
{
    cout << fixed << setprecision(2)
         << "----------------------------------" << '\n'
         << "account name:     " << name  << '\n'
         << "account number:   " << nr    << '\n'
         << "account state:    " << state << '\n'
         << endl;
}

// implementation of methods in header file works
//bool Account::setName(const string& s)
//{
//    if(s.size() < 1)
//        return false;
//    name = s;
//    return true;
//}

// implementation of methods in header file (explicitly inline) works

//inline bool Account::setName(const string& s)
//{
//    if(s.size() < 1)
//        return false;
//    name = s;
//    return true;
//}

#endif // ACCOUNT_H_INCLUDED
