#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    int number;
    string prompt("Please input an integer: ");
    cout << prompt;
    cin >> number;

    cout << uppercase
         << "octal \t  decimal \t  hexadecimal\n"
         << oct << number << "      \t"
         << dec << number << "      \t"
         << hex << number << endl;

    cout.setf(ios::hex);
    cout << 11 << endl;

    return 0;
}
