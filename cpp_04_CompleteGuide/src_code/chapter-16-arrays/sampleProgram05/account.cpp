#include "account.h"
#include <iostream>
#include <iomanip>
#include <string>

#define DUMMY_NAME "noname"
#define DUMMY_NUMBER 1111111
#define DUMMY_STATE 0.0
#define HEADER "\n--- Account Info ---\n"

// static data member as class's characteristic
unsigned int Account::objCounter = 0;

// definition of class constructor
Account::Account()
: name(DUMMY_NAME), nr(DUMMY_NUMBER), state(DUMMY_STATE)
{ objCounter++; }

Account::Account(const Account& z)
: name(z.name), nr(z.nr), state(z.state)
{ objCounter++; }

Account::Account(const std::string& s_name, int s_nr, double s_state)
{
    name  = (s_name.size() > 0)? s_name: DUMMY_NAME;
    nr    = (s_nr >= 0)? s_nr : DUMMY_NUMBER;
    state = s_state;
    objCounter++;
}

// definition of class destructor
Account::~Account()
{
    std::cout << "Account name: " << std::setw(15) << std::left << name;
    std::cout << ". Account object No." << objCounter-- << " is destroyed. ";
    std::cout << "there are still "    << objCounter   << " Account objects left.\n";
}

void Account::print() const
{
    std::cout << HEADER;
    std::cout << "account name : " << name << std::endl
              << "account no   : " << std::fixed << nr << std::endl
              << "account state: " << std::fixed << std::setprecision(2) << state << std::endl;
}
