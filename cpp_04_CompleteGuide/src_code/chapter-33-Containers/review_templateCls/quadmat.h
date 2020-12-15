#ifndef QUADMAT_H_INCLUDED
#define QUADMAT_H_INCLUDED

#include <stdexcept>
using namespace std;

template<class T, int cnt=10>
class QuadMatrix
{
private:
    T arr[cnt][cnt];
public:
    // dim
    int dim() const { return cnt; }
    // write
    T* operator[](int line) throw(out_of_range)
    {
        if(line<0 || line>cnt)
        {
            throw out_of_range("Matrix: index out of range");
        }
        else
            return arr[line];
    }
    // read
    const T* operator[](int line) const throw(out_of_range)
    {
        if(line<0 || line>cnt)
        {
            throw out_of_range("Matrix: index out of range");
        }
        else
            return arr[line];
    }

};


#endif // QUADMAT_H_INCLUDED
