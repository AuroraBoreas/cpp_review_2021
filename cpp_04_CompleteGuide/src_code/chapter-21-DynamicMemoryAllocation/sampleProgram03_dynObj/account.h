#ifndef ACCOUT_H_INCLUDED
#define ACCOUT_H_INCLUDED

#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class Account
{
    private:
        string name;
        unsigned int nr;
        double state;
    public:
        // --- constructors ---
        Account(const string& s_name="noname", unsigned int s_nr=1111, double s_state=0.0)
        : name(s_name), nr(s_nr), state(s_state)
        { }
        // --- repr ---
        friend ostream& operator<<(ostream& os, const Account& a) // using friend techniques to overload o << operator
        {
            os << "\n--- Account Info ---\n"
               << "\nAccount name     : " << a.name
               << "\nAccount number   : " << a.nr
               << "\nAccount state($) : " << setprecision(2) << fixed << a.state;
            return os;
        }
        // --- getter ---
        string getName(void)         const { return name; }
        unsigned int getNumber(void) const { return nr; }
        double getState(void)        const { return state; }
        // --- setter ---
        void setName(const string& s)  { if(s.size() >= 1) { name = s; } }
        void setNumber(unsigned int n) { nr = n; }
        void setState(double x)        { state = x; }
};

#endif // ACCOUT_H_INCLUDED
