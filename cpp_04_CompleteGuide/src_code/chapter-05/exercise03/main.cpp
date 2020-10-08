#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    int x;
    x = 7;
    cout << boolalpha << (x < 10 && x >= -1) << endl; // true
    cout << boolalpha << (!x && x >= 3) << endl; // false
    cout << boolalpha << (x++ == 8 || x == 7) << endl; // false

    return 0;
}
