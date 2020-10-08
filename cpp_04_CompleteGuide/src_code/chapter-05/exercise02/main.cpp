#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    int x, i;
    i = 0;
    x = -4 * i++ - 6 % 4; // -2
    cout << "x = " << x << endl;
    // insert
    x = -(4 * ++i) - (6 % 4); // -10
    cout << "x = " << x << endl;

    i = -2;
    x = -4 * i++ - 6 % 4; // 6
    cout << "x = " << x << endl;

    return 0;
}
