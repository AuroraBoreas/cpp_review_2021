#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    double x, y;

    cout << "Enter two floating-point values: ";
    cin >> x >> y;
    cout << "The average of the two numbers is: "
         << (x + y) / 2.0 << endl;

    cout << "x + y = " << x + y << endl;
    cout << "x - y = " << x - y << endl;
    cout << "x * y = " << x * y << endl;
    cout << "x / y = " << x / y << endl;
    //cout << "x % y = " << x % y << endl;

    return 0;
}
