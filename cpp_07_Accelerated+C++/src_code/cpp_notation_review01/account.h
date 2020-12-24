#ifndef ACCOUNT_H_INCLUDED
#define ACCOUNT_H_INCLUDED

#include <string>
#include <sstream>
#include <iomanip>

class Account
{
    private:
        unsigned    nr;
        std::string name;
        double      stat;
    public:
        // constructor
        Account(unsigned n=0L, const std::string& s="noname", double w=0.0)
        : nr(n), name(s), stat(w){}
        // destructor
        virtual ~Account(){}
        // getter
        unsigned getNr(void)             const { return nr; }
        const std::string& getName(void) const { return name; }
        double   getStat(void)           const { return stat; }
        // setter
        void setNr(unsigned n)             { nr = n; }
        void setName(const std::string& s) { name = s; }
        void setStat(double w)             { stat = w; }
        // repr
        std::string asString(void) const
        {
            std::stringstream ss;
            ss << "\nnumber  : " << nr;
            ss << "\nname    : " << name;
            ss << "\nstate($): " << std::fixed << std::setprecision(2) << stat;
            return ss.str();
        }

        friend std::ostream& operator<<(std::ostream& os, const Account& acc)
        {
            os << acc.asString();
            return os;
        }

};

#endif // ACCOUNT_H_INCLUDED
