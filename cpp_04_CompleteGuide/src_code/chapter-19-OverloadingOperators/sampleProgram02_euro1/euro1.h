#ifndef EURO1_H_INCLUDED
#define EURO1_H_INCLUDED

#include <string>
#include <sstream>
#include <iomanip>

class Euro
{
    private:
        long data;
    public:
        // constructors
        Euro(int euro=0, int cents=0) { data = 100L * (long)euro + cents; }
        Euro(double x) { x *= 100.0; data = (long)(x>=0.0?(x+0.5):(x-0.5)); }
        // getter
        long getWholePart() const { return data/100; }
        int  getCents()     const { return (int)data%100; }
        double asDouble()   const { return (double)data/100.0; }
        long getData()      const { return data; }
        // setter
        void setData(int d) { data = (long)d; }
        std::string asString() const
        {
            std::stringstream ss;
            long temp = data;
            if(temp<0) { ss << '-'; temp = -temp; }
                ss << (temp/100) << ',' << std::setfill('0') << std::setw(2) << (temp%100);
                return ss.str();
        }
        // print
        void print(std::ostream& os) const
        {
            os << this->asString() << " Euro\n";
        }
        // ---- operator functions ----
        Euro operator-() const // negative (unary minus)
        {
            Euro temp;
            temp.data = -data;
            return temp;
        }
        Euro operator+(const Euro& e) const // addition
        {
            Euro temp;
            temp.data = this->data + e.data;
            return temp;
        }
        Euro operator-(const Euro& e) const // subtraction
        {
            Euro temp;
            temp.data = this->data - e.data;
            return temp;
        }
        Euro& operator+=(const Euro& e)   // +=
        {
            this->data += e.data;
            return *this;
        }
        Euro& operator-=(const Euro& e)   // -=
        {
            this->data -= e.data;
            return *this;
        }
};

#endif // EURO1_H_INCLUDED
