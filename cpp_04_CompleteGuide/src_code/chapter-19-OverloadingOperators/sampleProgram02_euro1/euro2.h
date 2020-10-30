#ifndef EURO2_H_INCLUDED
#define EURO2_H_INCLUDED

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

class Euro
{
    private:
        long data;
    public:
        // parameterized constructor
        Euro(int euro=0, int cents=0) { data = 100L * (long)euro + cents; }
        // parameterized constructor
        Euro(double x) { x *= 100.0; data = (long)(x>=0.0? (x+0.5) : (x-0.5)); }
        // getter
        long getWholePart(void) const { return data/100; }
        long getCents(void) const { return (long)(data%100); }
        double asDouble(void) const { return (double)data/100.0; }
        string asString() const
        {
            stringstream ss;
            long temp = data;
            if(temp<0) { ss << '-'; temp = -temp; }
            ss << (temp/100) << ',' << setfill('0') << setw(2) << (temp%100);
            return ss.str();
        }
        void print(ostream& os)
        {
            os << this->asString() << " Euro\n";
        }
        // ---- overloading operator ----
        Euro operator-(void) const
        {
            Euro temp;
            temp.data = -data;
            return temp;
        }
        Euro operator+(const Euro& e) const
        {
            Euro temp;
            temp.data = this->data + e.data;
            return temp;
        }
        Euro operator-(const Euro& e) const
        {
            Euro temp;
            temp.data = this->data - e.data;
            return temp;
        }
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
};

#endif // EURO2_H_INCLUDED
