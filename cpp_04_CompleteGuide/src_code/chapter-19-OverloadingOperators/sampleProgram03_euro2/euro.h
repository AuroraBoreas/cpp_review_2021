#ifndef EURO_H_INCLUDED
#define EURO_H_INCLUDED

#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

class Euro
{
    private:
        long data;
    public:
        // parameterized constructors
        Euro(int euro=0, int cents=0) { data = 100L * (long)euro + cents; }
        Euro(double x) { x *= 100.0; data = (long)(x>0.0? (x+0.5) : (x-0.5)); }
        // getter
        long getWholePart(void) const { return (data/100); }
        int  getCents(void) const { return (data%100); }
        string asString(void) const
        {
            stringstream ss;
            long temp = data;
            if(temp<0) { temp = -temp; ss << '-'; }
            ss << (temp/100) << ',' << setfill('0') << setw(2) << (temp%100);
            return ss.str();
        }
        // print
        void print(ostream& os) const
        { os << asString() << " Euro\n"; }
        // --- overload operators
        Euro operator-(void) const  // overload unary operator -
        {
            Euro temp;
            temp.data = -data;
            return temp;
        }

//        Euro operator+(const Euro& e) const // overload addition operator +
//        {
//            Euro temp;
//            temp.data = data + e.data;
//            return temp;
//        }
//
//        Euro operator-(const Euro& e) const // overload subtraction operator -
//        {
//            Euro temp;
//            temp.data = data - e.data;
//            return temp;
//        }

        Euro& operator+=(const Euro& e) // overload self increment operator +=
        {
            data += e.data;
            return *this;
        }
        Euro& operator-=(const Euro& e) // overload self decrement operator -=
        {
            data -= e.data;
            return *this;
        }
};

// --- global operator functions
// !Attentions: they are NOT class methods.

inline Euro operator+(const Euro& e1, const Euro& e2)
{
    Euro temp(e1);
    temp += e2;
    return temp;
}

inline Euro operator+(const Euro& e1, const Euro& e2)
{
    Euro temp(e1);
    temp -= e2;
    return temp;
}

#endif // EURO_H_INCLUDED
