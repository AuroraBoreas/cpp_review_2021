/*
wanna discuss raw pointer notation

what is pointer?
pointer is a var which stores memory address of another var.

why use pointer?
time and space saving

how to use?

declaration:
T x = 10;           // x is lvalue; 10 is rvalue;
T* tPtr = &x;       // tPtr is pointer to x;
or
T *tPtr = &x;       // note the position of *;
T** tPptr = & tPtr; // tPptr is pointer to tPtr;

*/
#include <iostream>

using namespace std;

template<class T>
void print(const T& x)
{
    cout << "value = " << x << ", addr = " << &x << endl;
}

int main()
{
    unsigned a = 10;
    print<unsigned>(a);

    unsigned *aPtr = &a;
    cout << aPtr << endl;
    cout << *aPtr << endl;

    unsigned **aPPtr = &aPtr;
    cout << aPPtr << endl;
    cout << **aPPtr << endl;

    unsigned **arr[] = { aPPtr };



    return 0;
}
