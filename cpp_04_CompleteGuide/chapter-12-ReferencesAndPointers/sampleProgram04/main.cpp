#include <iostream>
#include <string>

using namespace std;

// prototype
double& refMin(double&, double&);


int main()
{
    double x1 = 1.1, x2 = x1 + 0.5, y;

    y = refMin(x1, x2);
    cout << "x1 = " << x1 << "     "
         << "x2 = " << x2 << endl;
    cout << "Minimum: " << y << endl;

    ++refMin(x1, x2);
    cout << "x1 = " << x1 << "     " // 2.1
         << "x2 = " << x2 << endl;   // 1.6

    ++refMin(x1, x2);   // x1 = 2.1, x2 = 2.6
    cout << "x1 = " << x1 << "     " // 2.1
         << "x2 = " << x2 << endl;   // 2.6

    refMin(x1, x2) = 10.1;
    cout << "x1 = " << x1 << "     " // 10.1
         << "x2 = " << x2 << endl;   // 2.6

    refMin(x1, x2) += 5.0;
    cout << "x1 = " << x1 << "     " // 10.1
         << "x2 = " << x2 << endl;   // 7.6

    return 0;
}


double& refMin(double& a, double& b)
{
    return a <= b? a : b;
}
