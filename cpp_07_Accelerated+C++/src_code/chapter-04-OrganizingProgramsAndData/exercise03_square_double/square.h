#ifndef SQUARE_H_INCLUDED
#define SQUARE_H_INCLUDED

#include <iostream>
#include <vector>
#define SQUARE(x) ((x)*(x))
using std::vector; using std::cout;

template<class T>
class MyVec
{
    private:
        vector<T> vtPtr1;
        vector<T> vtPtr2;
        unsigned max;
        // populate
        void populate(unsigned n)
        {
            for(unsigned i=0; i<n; ++i)
            { vtPtr1.push_back(i); vtPtr2.push_back(SQUARE(i)); }
        }

    public:
        // constructor
        MyVec(unsigned n): max(n){ populate(n); }

        // display
        void display(void) const
        {
            cout << "\nval" << "\t" << "square\n";
            for(unsigned i=0; i<max; ++i)
            { cout << vtPtr1[i] << "\t" << vtPtr2[i] << "\n"; }
        }
};

#endif // SQUARE_H_INCLUDED
