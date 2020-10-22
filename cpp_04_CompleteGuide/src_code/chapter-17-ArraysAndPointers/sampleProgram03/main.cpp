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

    x = *pv++;  // precedence!
    x += *pv--;

    --pv;

    cout << x << endl;

    return 0;
}
