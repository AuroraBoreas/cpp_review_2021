#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    int a;

    cout << "enter an positive integer: ";
    cin >> a;

    cout << "decimal: " << dec << a << endl;
    cout << "octal  : " << oct << a << endl;
    cout << "hex    : " << hex << a << endl;

    return 0;
}
