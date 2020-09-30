#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    double x = 12.0;
    cout.precision(2);
    cout << " By default: " << x << endl;
    cout << " showpoint:  " << showpoint  << x << endl;
    cout << " fixed:      " << fixed      << x << endl;
    cout << " scientific: " << scientific << x << endl;

    return 0;
}
