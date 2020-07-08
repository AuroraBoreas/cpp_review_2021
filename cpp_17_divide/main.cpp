#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    cout.setf(ios_base::fixed, ios_base::floatfield);

    cout << "integer division: 9/5      = " << 9/5 << endl;
    cout << "float division: 9.0/5.0    = " << 9.0/5.0 << endl;
    cout << "mixed division: 9.0/5      = " << 9.0/5 << endl;
    cout << "mixed division: 9/5.0      = " << 9/5.0 << endl;
    cout << "double constants: 1e7/9.0  = " << 1e7/9.0 << endl;
    cout << "float constants: 1e7f/9.0f = " << 1e7/9.0f << endl;

    return 0;
}
