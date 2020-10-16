#ifndef ACCOUNT_H_INCLUDED
#define ACCOUNT_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class Account
{
    private:
        string name;
        unsigned long nr;
        double balance;

    public:
        bool init(const string&, unsigned long, double);
        void display();
};

#endif // ACCOUNT_H_INCLUDED
