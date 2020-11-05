#ifndef EURO_H_INCLUDED
#define EURO_H_INCLUDED

class Euro
{
    private:
        long data;
    public:
        // constructors
        Euro(int euro=0, int cents=0)
        {
            data = 100L * (long)euro + cents;
        }
        Euro(double w)
        {
            w *= 100.0;
            data = (double)((w >= 0.0)? (w + 0.5) : (w - 0.5));
        }
        // getter, setter

        // op ol, unary operators
        Euro operator-(void)
        {
            Euro temp;
            temp.data = -data;
            return temp;
        }
        // op ol, binary operators, in-place operators
        Euro& operator+=(const Euro& e)
        {
            data += e.data;
            return *this;
        }

        // using friend techniques to do op ol

        // repr

};

// global, inline op ol

inline Euro operator+(const Euro& e1, const Euro& e2)
{
    Euro temp(e1);
    temp += e2;
    return temp;
}

#endif // EURO_H_INCLUDED
