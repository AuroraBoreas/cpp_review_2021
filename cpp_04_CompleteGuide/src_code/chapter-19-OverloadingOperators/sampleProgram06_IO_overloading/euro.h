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
        // parameterized constructor
        Euro(int euro=0, int cents=0)
        { data = 100L * (long)euro + cents; }
        // parameterized constructor
        Euro(double x)
        {
            x *= 100.0;
            data = (long)((x >= 0.0)? (x+0.5) : (x-0.5));
        }
        // repr
        string asString(void) const
        {
            stringstream ss;
            long temp = data;
            if(temp < 0) { temp=-temp; ss << '-'; }
            ss << (temp/100) << ',' << setw(2) << setfill('0') << (temp%100);
            return ss.str();
        }

        void print(ostream& os) const
        { os << this->asString() << " Euro" << endl; }

        // --- member methods overload operator: in-place operators ---
        Euro operator+=(const Euro& e) const
        {
            Euro temp;
            temp.data = this->data + e.data;
            return temp;
        }

        Euro operator-=(const Euro& e) const
        {
            Euro temp;
            temp.data = this->data - e.data;
            return temp;
        }

        Euro operator/(double x) const
        { return (*this * (1.0/x)); }

        // --- global operator overloading ---
        friend Euro operator/(double x, const Euro& e)
        {
            Euro temp(1.0/((double)e.data/x) * 100);
            return temp;
        }

        friend Euro operator*(const Euro& e, double x)
        {
            Euro temp(((double)e.data/100.0) * x);
            return temp;
        }

        friend Euro operator*(double x, const Euro& e)
        { return e * x; }

};

// --- global operator overloading ---
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

// --- declaration of shift operators, global? yes
// NOTE: `void print(ostream& os) const` is superfluous

inline ostream& operator<<(ostream& os, const Euro& e)
{
    os << e.asString() << " Euro";
    return os;
}

inline istream& operator>>(istream& is, Euro& e)
{
    cout << "Euro amount (Format ...x,xx): ";
    int euro = 0, cents = 0; char c = 0;
    if(!(is >> euro >> c >> cents))
        return is;
    if((c != ',' && c != '.') || cents >= 100)
        is.setstate(ios::failbit);
    else
        e = Euro(euro, cents);
    return is;
}

#endif // EURO_H_INCLUDED
