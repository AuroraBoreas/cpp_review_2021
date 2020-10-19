#ifndef ACCOUNT_H_INCLUDED
#define ACCOUNT_H_INCLUDED

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// yeah. Account::display can't be advanced before cls Account definition as expected
//inline void Account::display() // explicit inline
//{
//    cout << fixed << setprecision(2)
//         << "--------------------------------------\n"
//         << "Account holder:   " << name  << '\n'
//         << "Account number:   " << nr    << '\n'
//         << "Account state:    " << state << '\n'
//         << "--------------------------------------\n"
//         << endl;
//}

class Account
{
private:
    string name;
    unsigned long nr;
    double state;
public:
    Account(const string& a_name = "X",
            unsigned long a_nr   = 1111111,
            double a_state        = 0.0)
    {
        name  = a_name;
        nr    = a_nr;
        state = a_state;
    };

    ~Account() {}; // dummy destructor: implicit inline

    void display();
};

inline void Account::display() // explicit inline
{
    cout << fixed << setprecision(2)
         << "--------------------------------------\n"
         << "Account holder:   " << name  << '\n'
         << "Account number:   " << nr    << '\n'
         << "Account state:    " << state << '\n'
         << "--------------------------------------\n"
         << endl;
};

#endif // ACCOUNT_H_INCLUDED
