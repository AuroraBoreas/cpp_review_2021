#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    float x, y;

    // a += b
    cout << "Enter an starting value: ";
    cin >> x;
    cout << "Enter the increment value: ";
    cin >> y;
    x += y;

    cout << "and multiplication!";
    cout << "please enter a factor: ";
    cin >> y;
    x *= y;

    cout << "finally division!";
    cout << "please enter a divisor: ";
    cin >> y;
    x /= y;

    cout << "and this is "
         << "your current lucky number: "
         << fixed << setprecision(0)
         << x << endl;

    return 0;
}
