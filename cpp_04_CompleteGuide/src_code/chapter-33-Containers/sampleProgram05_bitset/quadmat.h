#ifndef QUADMAT_H_INCLUDED
#define QUADMAT_H_INCLUDED

#include <stdexcept>
using std::out_of_range;

template<class T, int cnt=10>
class QuadMatrix
{
private:
    T arr[cnt][cnt];
public:
    // constructor
    // destructor
    // dim
    int dim(void) const { return cnt; }
    // op ol []
    T* operator[](int line) throw out_of_range
    {
        if(line<0 || line>cnt)
        {
            throw out_of_range("Matrix: index out of range");
        }
        else return arr[line];
    }
    const T* operator[](int line) const throw out_of_range
    {
        if(line<0 || line>cnt)
        {
            throw out_of_range("Matrix: index out of range");
        }
        else return arr[line];
    }

};


#endif // QUADMAT_H_INCLUDED
