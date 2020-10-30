#ifndef EURO_H_INCLUDED
#define EURO_H_INCLUDED

class Euro
{
    private:
        long data;  // store cents
    public:
        // parameterized constructor
        Euro(int euro=0, int cents=0) // 1 euro = 100 cents
        { data = 100L * (long)euro + cents; }
        // overloading constructor
        Euro(double x)
        {

        }
};

#endif // EURO_H_INCLUDED
