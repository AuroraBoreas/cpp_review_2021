/*
compiler generated functions

- default constructor
- copy constructor
- copy assignment operator
- default destructor

when

- when needed

what

- inline
- public

*/

#include <iostream>
#define ABS(a) ((a) < 0? (-a) : (a))

using namespace std;

inline bool isClose(int a, int b)
{
    return (double)(ABS(a-b)) / a < 1e-10;
}


//class Dog
//{
//    public:
//        Dog(){...} // default
//        Dog(const Dog& d){...} // copy constructor
//        Dog& operator=(const Dog& d){...} // copy assignment constructor
//        ~Dog(){...} // destructor
//};

int main()
{
//    Dog d1;

    int a = 10;
    int b = 10;
    cout << isClose(a, b);

    return 0;
}
