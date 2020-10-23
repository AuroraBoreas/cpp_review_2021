#include <iostream>

using namespace std;

float v[6] = {0.0, 0.1, 0.2, 0.3, 0.4, 0.5},
      *pv, x;

int main()
{
    pv = v + 4; // pv = v[4]
    *pv  = 1.4; // v[4] = 1.4
    pv  -= 2;   // pv = v[2]
    ++pv;       // pv = v[3]

    x = *pv++;  // precedence! i know, u fuckers.
    // x = *(pv++); x = 0.3, pv = v[4]
    x += *pv--; // x = x + 1.4, pv = v[3]

    --pv; // pv = v[2]

    cout << x << endl; // output 1.7

    // pointer comparison
    cout << endl;

    int nums[6] = {1, 3, 5, 7, 9},
        *ptr;

    for(ptr=nums+5; ptr>=nums; --ptr)
        cout << (void*)ptr << " = " << *ptr << endl;

    cout << endl;

    return 0;
}
