#ifndef EURO_H_INCLUDED
#define EURO_H_INCLUDED

#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

class Euro
{
    private:
        long data;
    public:
        // constructor
        Euro(int euro=0, int cents=0)
        { data = 100L * (long)euro + cents; }

        Euro(double x)
        { x *= 100.0; data = (long)(x > 0.0? (x+0.5) : (x-0.5)); }

        // repr
        string asString(void) const
        {
            stringstream ss;
            long temp = data;
            if(temp < 0.0) { ss << '-'; temp=-temp; }
            ss << (temp/100) << ',' << setw(2) << setfill('0') << (temp%100);
            return ss.str();
        }

        void print(ostream& os) const
        { os << this->asString() << " Euro\n"; }

        // destructor, getter, setter?
        // --- member methods: operator overloading ---
        Euro operator-(void) const // unary operator -
        {
            Euro temp;
            temp.data = -data;
            return temp;
        }

//        Euro operator+(const Euro& e) const // binary operator a+b
//        {
//            Euro temp;
//            temp.data = this->data + e.data;
//            return temp;
//        }
//
//        Euro operator-(const Euro& e) const // binary operator a-b
//        {
//            Euro temp;
//            temp.data = this->data - e.data;
//            return temp;
//        }

        Euro& operator+=(const Euro& e) // in-place operator +=
        {
            this->data += e.data;
            return *this;
        }

        Euro& operator-=(const Euro& e) // in-place operator -=
        {
            this->data -= e.data;
            return *this;
        }

        // --- friend techniques ---
        Euro operator/(double x)
        { return (*this * (1.0/x)); }   // this technique thou..

        friend Euro operator/(double x, const Euro& e)
        {
            Euro temp(1.0/(((double)e.data/100.0)/x));
            return temp;
        }

        friend Euro operator*(const Euro& e, double x)
        {
            Euro temp(((double)e.data/100.0) * x);
            return temp;
        }

        friend Euro operator*(double x, const Euro& e)
        { return e * x; }

        // --- friend class technique ---
        friend class ControlPoint;
};

// --- global operator overloading ---
// NOTE: global op ol can NOT coexist with member op ol thou with same operators..

inline Euro operator+(const Euro& e1, const Euro& e2) // cover a+b, b+a
{
    Euro temp(e1);
    temp += e2;
    return temp;
}

inline Euro operator-(const Euro& e1, const Euro& e2) // cover a-b, b-a
{
    Euro temp(e1);
    temp -= e2;
    return temp;
}

class ControlPoint
{
    // access private members of class Euro.
    private:
        string name;
        Euro members[100];
    public:
        bool statistic() // access private members of member[i]
        {
            return false;
        }
};

#endif // EURO_H_INCLUDED
