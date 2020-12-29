/*
logical constness vs bitwise constness

what is logical constness?
- data member, not array or other containers.

what is bitwise constness?
- data member, array or other containers

*/

#include <iostream>
#include <cstdlib>
using std::cerr;
using std::cout; using std::endl;

class BigData
{
private:
    int* basePtr;
    unsigned m_tip, m_max;
public:
    BigData(unsigned n)
    {
        m_max = n;
        m_tip = 0;
        basePtr = new int[n];
    }
    virtual ~BigData() { delete[] basePtr; }
    const int operator[](unsigned i) const
    {
        if(i< (m_max-1) && i>0)
            return basePtr[i];  // OK. logical constness
        else
            cerr << "index out of range" << endl; return -1;
    }
    int& operator[](unsigned i)
    {
        return basePtr[i]; // OK. bitwise constness
    }
};

int main()
{
    BigData bd(10);

    cout << bd[3] << endl;
    bd[1] = 1;
    cout << bd[1] << endl;

    return 0;
}
