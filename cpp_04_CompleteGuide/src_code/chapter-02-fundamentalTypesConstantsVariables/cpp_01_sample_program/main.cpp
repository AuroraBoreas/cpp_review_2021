#include <iostream>
#include <climits>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    cout << "Range of types int and unsigned int"
         << endl << endl;
    cout << "Type            Min                 Max"
         << endl
         << "---------------------------------------"
         << endl;
    cout << "int            " << INT_MIN << "       "
                              << INT_MAX << endl;
    cout << "unsigned int   " << " 0                "
                              << UINT_MAX << endl;

    return 0;
}
