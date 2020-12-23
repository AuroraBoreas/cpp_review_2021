#ifndef ACCOUNT_H_INCLUDED
#define ACCOUNT_H_INCLUDED

#include <string>
#include <sstream>
#include <iomanip>
using std::string;
using std::stringstream;
using std::ostream;

class Account
{
    private:
        unsigned long nr;
        string        name;
        double        stat;
    public:
        // constructor
        Account(unsigned long n=0L,
                const string& s="noname",
                double        w=0.0)
        : nr(n), name(s), stat(w){}
        // destructor
        virtual ~Account(){}
        // getter
        unsigned long getNr(void)   const { return nr; }
        const string& getName(void) const { return name; }
        double        getStat(void) const { return stat; }
        // setter
        void setNr(unsigned long n)   { nr = n; }
        void setName(const string& s) { name = s; }
        void setStat(double w)        { stat = w; }
        // repr
        string asString(void) const
        {
            stringstream ss;
            ss << "\nnumber : " << nr;
            ss << "\nname   : " << name;
            ss << "\nstate  : " << std::fixed << std::setprecision(2) << stat;
            return ss.str();
        }
        friend ostream& operator<<(ostream& os, const Account& acc)
        {
            os << acc.asString();
            return os;
        }
        // op ol
        friend bool operator<(const Account& a, const Account& b)
        {
            return (a.nr < b.nr);
        }
};


#endif // ACCOUNT_H_INCLUDED
