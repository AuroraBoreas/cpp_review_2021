// Demonstration of compound assignments
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    float x, y;

    cout << "\n Please enter a starting value: ";
    cin >> x;

    cout << "\n Please enter the increment value: ";
    cin >> y;
    
    x += y;
    cout << "\n And now multiplication! ";
    cout << "\n Please enter a factor: ";
    cin >> y;
    x *= y;
    cout << "\n Finally division.";
    cout << "\n Please supply a divisor: ";
    cin >> y;
    x /= y;
    cout << "\n And this is "
    << "your current lucky number: "
    // without digits after
    // the decimal point:
    << fixed << setprecision(0)
    << x << endl;
    return 0;
}