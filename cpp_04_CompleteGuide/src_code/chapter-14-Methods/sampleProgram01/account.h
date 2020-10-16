#ifndef ACCOUNT_H_INCLUDED
#define ACCOUNT_H_INCLUDED

#include <string>
using namespace std;

class Account
{
    private:
        string name;
        unsigned long nr;
        double state;
    public:
        Account(const string&, unsigned long, double);
        Account(const string&);
        bool init(string&, unsigned long, double);
        void display(void);
};

#endif // ACCOUNT_H_INCLUDED
