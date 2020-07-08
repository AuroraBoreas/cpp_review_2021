#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    cout << "Enter mile: ";
    int miles, gas;
    cin  >> miles;
    cout << "Enter gas: ";
    cin  >> gas;
    cout << "gas per mile = "
         << (float)gas / miles
         << endl;
    return 0;
}
