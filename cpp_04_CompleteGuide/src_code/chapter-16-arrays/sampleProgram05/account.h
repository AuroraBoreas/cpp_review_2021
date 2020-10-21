#ifndef ACCOUNT_H_INCLUDED
#define ACCOUNT_H_INCLUDED

#include <string>

class Account
{
    private:
        std::string name;
        int         nr;
        double      state;
        static unsigned int objCounter;
    public:
        // constructor
        Account();
        Account(const Account&);
        Account(const std::string&, int, double);
        // destructor
        ~Account();
        // getter
        const std::string& getName(void) const { return name; }
        int getNumber(void)              const { return nr; }
        double getState(void)            const { return state; }
        static unsigned int getObjCounter(void) { return objCounter; }
        // setter
        void setName(const std::string& s_name) { if(s_name.size() > 1) name = s_name; }
        void setNumber(int number)              { if(number > 0) nr = number; }
        void setState(double w)                 { state = w; }
        // print
        void print(void) const;
};

#endif // ACCOUNT_H_INCLUDED
