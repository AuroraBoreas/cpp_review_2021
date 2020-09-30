#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    cout << showpos << 123; // output: +123
    // or
    cout.setf(ios::showpos);
    cout << endl;
    cout << 123;
    cout << endl;
    cout << 22;
    cout << endl;
    cout << noshowpos << 123;
    cout << endl;
    cout.unsetf(ios::showpos);
    cout << 123;
    return 0;
}
