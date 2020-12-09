#ifndef ACCOUNT_H_INCLUDED
#define ACCOUNT_H_INCLUDED

#include <string>
#include <iostream>
using std::cout;
using std::string;

class Account
{
private:
    long nr;
    string name;
    double balance;
public:
    // constructor
    Account();
    Account(long, const string&, double);
    // destructor
    virtual ~Account(){}
    // getter
    long getNr(void)            const { return nr; }
    const string& getName(void) const { return name; }
    double getBalance(void)     const { return balance; }
    // setter
    void setNr(long n)            { nr = n > 0L? n: 0L; }
    void setName(const string& s) { name = s; }
    void setBalance(double w)     { balance = w; }
    // repr
    string asString(void) const;
    virtual void display(void) const
    {
        std::cout << asString() << "\n";
    }
};

class SavAcc:public Account
{
private:
public:
    // constructor
    // destructor
    // getter
    // setter
    // repr
};

class DebitAcc:public Account
{
private:
public:
    // constructor
    // destructor
    // getter
    // setter
    // repr
};

#endif // ACCOUNT_H_INCLUDED
