#ifndef STACKN_H_INCLUDED
#define STACKN_H_INCLUDED

#include <stdexcept>
using namespace std;

template<class T, int n=10, int m=10>
class Stack
{
private:
    T arr1[n][n];
    T arr2[m][m];
public:
    // dim
    int dim_len(void) const { return n; }
    int dim_hai(void) const { return m; }

    T* operator[](int line) throw(out_of_range)
    {
        if(line<0 || line>n)
        {
            throw out_of_range("Matrix: index out of range");
        }
        else
            return arr1[n];
    }
    const T* operator[](int line) const throw(out_of_range)
    {
        if(line<0 || line>n)
        {
            throw out_of_range("Matrix: index out of range");
        }
        else
            return arr1[n];
    }

};

#endif // STACKN_H_INCLUDED
