/*
c++ understand keyword const

- compile time constness. it is a promise.
- enable compiler to do optimization

*/

#include <iostream>

using namespace std;

int main()
{
    // const
    int i = 42;
    // const int i = 42;
    // i = 3;   // not OK.
    // keyword const enforces constness in compile time
    const int *p1 = &i;
    *p1++;  // not OK
    p1++;   // OK

    int * const p2 = &i;
    // *p2++;  // not OK
    // p2++;   // not OK

    const int* const p3 = &i;
    // *p3++;  // not OK
    // p3++;   // not OK

    // notation
    const int* p4 = &i;
    int const* p5 = &i;

    // cast: a hack way
    const int j = 11;
    const_cast<int&>(j) = 5;    // remove const of j
    int k;
    static_cast<const int&>(k);  // add constness to k
    std::cout << k << std::endl;


    return 0;
}
