#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    int chest = 42;
    int waist = 42;
    int inseam = 42;

    cout << "Moisture cuts a striking figure!" << endl;
    cout << "chest  = " << chest << " (decimal for 42)" << endl;
    cout << hex; //change cout default value format from decimal to hex
    cout << "waist  = " << waist << " (hexadecimal for 42)" << endl;
    cout << oct; //change cout default value format from hex to octal
    cout << "inseam = " << inseam << " (octal for 42)" << endl;
    cout << hex;

    return 0;
}
