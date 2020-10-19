#ifndef ACCOUNT_H_INCLUDED
#define ACCOUNT_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Account
{
private:
    // data members
    string name;
    unsigned long nr;
    double state;
public:
    // constructors
    Account(const string& a_name = "X",
            unsigned long a_nr   = 111111111,
            double a_state       = 0.0)
    {
        name    = a_name;
        nr      = a_nr;
        state   = a_state;
    }
    ~Account() {}

    // accessing private data members
    // get read-only
    const string& getName() const { return name; }
    unsigned long getNr() const { return nr; }
    double getState() const { return state; }
    // set; read-only can be achieved but meaningless
    bool setName(const string& s)
    {
        if(s.size() < 1)
            return false;
        name = s;
        return true;
    }
    void setNr(unsigned long n) { nr = n; }
    void setState(double x) { state = x; }

    // other methods; ofc, can be set to read-only
    void display(void) const;
    void display(void);

};

inline void Account::display() const
{
    cout << fixed << setprecision(2)
         << "\n-----------------------" << '\n'
         << "account name:      " << name  << '\n'
         << "account number:    " << nr    << '\n'
         << "account state:     " << state << '\n'
         << endl;
}

void Account::display() // overloading display(), no problem as expected.
{
    cout << fixed << setprecision(2)
         << "\n-----------------------" << '\n'
         << "account name:      " << name  << '\n'
         << "account number:    " << nr    << '\n'
         << "account state:     " << state << '\n'
         << endl;
}

#endif // ACCOUNT_H_INCLUDED
