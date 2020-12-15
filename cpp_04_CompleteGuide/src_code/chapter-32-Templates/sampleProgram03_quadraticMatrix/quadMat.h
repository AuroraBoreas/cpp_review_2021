#ifndef QUADMAT_H_INCLUDED
#define QUADMAT_H_INCLUDED

#include <stdexcept>
#include <iostream>

using namespace std;

template<class T, int cnt = 10>
class QuadMatrix
{
private:
    T mat[cnt][cnt];
public:
    int dim() const { return cnt; }
    T* operator[](int line) throw(out_of_range)
    {
        if(line<0 || line>=cnt)
            throw out_of_range("Matrix: index out of range");
        else
            return mat[line];
    }

    const T* operator[](int line) const throw(out_of_range)
    {
        if(line<0 || line>=cnt)
            throw out_of_range("Matrix: index out of range");
        else
            return mat[line];
    }

    friend QuadMatrix& operator+(const QuadMatrix&,
                                 const QuadMatrix&);
};


#endif // QUADMAT_H_INCLUDED
