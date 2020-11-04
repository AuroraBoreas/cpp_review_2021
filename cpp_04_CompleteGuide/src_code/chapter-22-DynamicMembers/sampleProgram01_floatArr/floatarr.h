#ifndef FLOATARR_H_INCLUDED
#define FLOATARR_H_INCLUDED

#include <cstdlib>
using namespace std;

class FloatArr
{
    private:
        float* arrPtr; //dynamic member
        int max;       //max quantity w/o reallocation of new storage
        int cnt;       //number of array elements
    public:
        // constructor
        FloatArr(int n = 256)
        {
            max = n; cnt = 0;
            arrPtr = new float[max]; // dynamically allocated in heap
        }
        // constructor
        FloatArr(int n, float val)
        {
            max = cnt = n;
            arrPtr = new float[max];
            for(int i=0; i < cnt; ++i)
                arrPtr[i] = val;
        }
        // copy constructor
        FloatArr(const FloatArr& src)
        {
            max=src.max; cnt=src.cnt;
            arrPtr = new float[max];
            for(int i=0; i < cnt; ++i)
                arrPtr[i] = src.arrPtr[i];
        }
        FloatArr& operator=(const FloatArr& src)
        {
            if(this!=&src)
            {
                max = src.max;
                cnt = src.cnt;
                delete[] arrPtr;
                arrPtr = new float[max];
                for(int i=0; i<cnt; ++i)
                    arrPtr[i] = src.arrPtr[i];
            }
            return *this;
        }
        // destructor
        ~FloatArr()
        { delete[] arrPtr; }
        // method
        int length() const { return cnt; }
        // method op ol
        float& operator[](int i)
        {
            if(i<0 || i>=cnt)
            {
                cerr << "\n class FloatArr:: out of range!";
                exit(1);
            }
            return arrPtr[i];
        }
        // method op ol
        float  operator[](int i) const
        {
            if(i<0 || i>=cnt)
            {
                cerr << "\n class FloatArr:: out of range!";
                exit(i);
            }
            return arrPtr[i];
        }
        // method
        bool append(float val)
        {
            if(cnt < max)
            {
                arrPtr[cnt++] = val; return true;
            }
            else
                return false;
        }
        // method
        bool remove(int pos)
        {
            if(pos>=0 && pos < cnt)
            {
                for(int i=pos; i < cnt-1; ++i)
                    arrPtr[i] = arrPtr[i+1];
                --cnt;
                return true;
            }
            else
                return false;
        }
};

#endif // FLOATARR_H_INCLUDED
