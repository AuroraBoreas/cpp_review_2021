#include <iostream>
#include "euro.h"

using namespace std;

int main()
{
    Euro e1(33, 10);

    e1 = e1 / 20.0;
    e1.print(cout);

    e1 = 100.0 * e1;
    e1.print(cout);

    e1 = 400 / e1;
    e1.print(cout);
    cout << e1 << endl;

    Euro e3(10,0);
    e3 = e3 + 108.3;
    cout << e3 << endl;
    e3 += 101.7;
    cout << e3 << endl;

    Euro e4(108.3);
    cout << e4 << endl;

    return 0;
}
