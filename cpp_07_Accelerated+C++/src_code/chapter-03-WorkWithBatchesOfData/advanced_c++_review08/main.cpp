/*
all casting considerate

- dynamic_cast; // downcasting, obj pointer only
- static_cast; // anything
- const_cast; // obj pointer only. adding or removing const
- reinterpret_cast; // force conversion in bitwise. C-style casting

*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int a = 1;
    float c = static_cast<float>(a);
    cout << std::fixed << std::setprecision(2) << c << endl;

    double d = 3.1415926;
    int e = static_cast<int>(d);
    cout << e << endl;

    short* ch = dynamic_cast<short*>(&e); // downcasting
    cout << *ch << endl;

    const int x = 10;
    int* y = const_cast<int*>(&x);
    cout << *y << endl;
    int s = 11;
    const int* s1 = const_cast<const int*>(&s);
    cout << *s1 << endl;


    return 0;
}
