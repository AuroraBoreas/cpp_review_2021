#ifndef ACCOUNT_H_INCLUDED
#define ACCOUNT_H_INCLUDED

#include <string>
#include <sstream>
using namespace std;

class Euro
{
    private:
        long data;
    public:
        // constructor
        Euro(int euro=0, int cents=0)
        { data = 100L * (long)euro + cents; }
        explicit Euro(double x)
        { x *= 100.0; data = (long)(x >= 0.0? (x+0.5) : (x-0.5)); }
        // getter, setter, repr?
        string asString(void) const
        {
            stringstream ss;
            long temp = data;
            if(temp<0) { temp = -temp; ss << '-'; }
            ss << (temp/100) << ',' << (temp%100) << " Euro";
            return ss.str();
        }
        // global, overload io operator <<
        friend ostream& operator<<(ostream& os, const Euro& e)
        { os << e.asString(); return os; }
        // method, in-place operator
        Euro& operator+=(const Euro& e)
        {
            this->data += e.data;
            return *this;
        }
        Euro& operator-=(const Euro& e)
        {
            this->data -= e.data;
            return *this;
        }
        // using friend technique to overload operator
        friend Euro operator*(const Euro& e, double x)
        {
            Euro temp((double)e.data * x);
            return temp;
        }
        // method, explicit type conversion
        operator double(void)
        { return (double)data; }

};

// global, symmetric operators overloading
// why? DRY. dont wanna write same function name with arg position difference.
inline Euro operator+(const Euro& e1, const Euro& e2)
{
    Euro temp(e1);
    temp += e2;
    return temp;
}

inline Euro operator-(const Euro& e1, const Euro& e2)
{
    Euro temp(e1);
    temp -= e2;
    return temp;
}


#endif // ACCOUNT_H_INCLUDED
