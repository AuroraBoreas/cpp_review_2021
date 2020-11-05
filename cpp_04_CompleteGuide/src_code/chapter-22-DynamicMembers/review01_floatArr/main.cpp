#include <iostream>
#include <iomanip>
#include "floatarr.h"

using namespace std;

void breaker(void);

int main()
{
    breaker();
    FloatArr fa1(5), // test parameterized constructor with default args
             fa2(3, 0.1F); // constructor

    for(int i=0; i < fa2.length(); ++i)
        cout << fa2[i] << endl; // test index op ol

    breaker();
    fa1 = fa2;  // test assignment op
    for(int i=0; i < fa1.length(); ++i)
        cout << fa1[i] << endl;

    breaker();
    FloatArr v3(fa2); // test copy-constructor
    for(int i=0; i < v3.length(); ++i)
        cout << v3[i] << endl;

    breaker();
    FloatArr v4(5);
    bool x = v4.append(3.0F); // test append method
    cout << boolalpha << x << endl;
    for(int i=0; i < v4.length(); ++i)
        cout << v4[i] << endl;

    breaker();
    FloatArr v5(5);
    v5.append(3.1F);
    v5.append(3.1F);
    v5.append(3.1F);
    bool z = v5.remove(0); // test remove method
    cout << boolalpha << z << endl;
    for(int i=0; i < v5.length(); ++i)
        cout << v5[i] << endl;

    return 0;
}

void breaker()
{
    std::cout << "\n--- breaker ---\n";
}
