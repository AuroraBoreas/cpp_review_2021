#ifndef FLOATARR_H_INCLUDED
#define FLOATARR_H_INCLUDED

#include <iostream>
#include <cstdlib>

using namespace std;

class FloatArr
{
    private:
        float *ptr;
        int max;
        int cnt;
    public:
        // parameterized constructor with default args
        FloatArr(int n=256)
        {
            max = n; cnt = 0;
            ptr = new float[max];
        }
        // constructor
        FloatArr(int n, float val)
        {
            max = cnt = n;
            ptr = new float[max];
            for(int i=0; i < cnt; ++i)
                ptr[i] = val;
        }
        // copy constructor
        FloatArr(const FloatArr& src)
        {
            max = src.max; cnt = src.cnt;
            // delete[] ptr; ptr is NOT initialized yet..
            ptr = new float[max];
            for(int i=0; i < cnt; ++i)
                ptr[i] = src.ptr[i];
        }
        // ol assignment operator
        FloatArr& operator=(const FloatArr& src)
        {
            if(this != &src)
            {
                max = src.max; cnt = src.cnt;
                delete[] ptr;
                ptr = new float[max];
                for(int i=0; i < cnt; ++i)
                ptr[i] = src.ptr[i];
            }
            return *this;
        }
        // destructor
        ~FloatArr()
        {
            delete[] ptr;
        }
        // getter
        int length(void) const
        {
            return cnt;
        }
        // setter
        // index op ol
        float& operator[](int i)
        {
            if(i<0 || i>=cnt)
            {
                cerr << "\nFloatArr::index is out of range!" << endl;
                exit(1);
            }
            return ptr[i];
        }
        // method
        float operator[](int i) const
        {
            if(i<0 || i>=cnt)
            {
                cerr << "\nFloatArr::index is out of range!" << endl;
                exit(1);
            }
            return ptr[i];
        }
        // append element to last
        bool append(float val)
        {
            if(cnt < max)
            {
                ptr[cnt++] = val; return true;
            }
            return false;
        }
        // remove element with a given position/index
        bool remove(int pos)
        {
            if(pos >= 0 && pos < cnt)
            {
                for(int i=pos; i<cnt-1; ++i)
                    ptr[i] = ptr[i+1];
                --cnt;
                return true;
            }
            return false;
        }

};

#endif // FLOATARR_H_INCLUDED
