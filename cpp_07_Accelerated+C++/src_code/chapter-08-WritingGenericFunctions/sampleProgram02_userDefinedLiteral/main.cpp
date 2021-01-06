#include <iostream>

using namespace std;

constexpr long double operator''_m(long double x)
{ return x * 1000; }

constexpr long double operator''_cm(long double x)
{
    return x * 10;
}

constexpr long double operator''_mm(long double x)
{
    return x;
}


int main()
{
    long double a = 10_cm;


    return 0;
}
