#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    float x(.123456);
    cout << setw(15)
         << x;

    cout << endl;
    float y(23.987);
    cout << setprecision(2)
         << right
         << setw(12)
         << y;

    cout << endl;
    float z(-123.456);
    cout << setw(10)
         << setprecision(4)
         << scientific
         << z;
    return 0;
}
