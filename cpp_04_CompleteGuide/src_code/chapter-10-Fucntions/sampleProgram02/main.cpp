#include <iostream>
#include <iomanip>

using namespace std;

double area(double, double);

int main()
{
    double x(3.5), y(7.2), res;
    res = area(x, y+1);

    cout << fixed << setprecision(2)
         << "\n the area of a rectangle "
         << "\n with width " << setw(5) << x
         << "\n and length " << setw(5) << y + 1
         << "\n is         " << setw(5) << res
         << endl;


    return 0;
}

double area(double width, double len)
{
    return (width * len);
}
