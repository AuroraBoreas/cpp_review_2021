#include <iostream>

using namespace std;

int main()
{
    long *ptr_long;
    ptr_long = new long;

    *ptr_long = 1234567;

    double *ptr_double;
    double z = 1.9;
    ptr_double = new double(z);
    // what the different from the line below?
    // ptr_double = &z;

    ++(*ptr_double);
    *ptr_double += *ptr_long;

    //ptr_long = new double(2.7); // ofc Error..
    return 0;
}
