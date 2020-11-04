#include <iostream>
#include "floatarr.h"

using namespace std;

int main()
{
    FloatArr v(10);
    FloatArr w(20, 1.0F);

    v.append(0.5F);
    cout << " current number of elements in v: "
         << v.length() << endl;

    cout << " current number of elements in w: "
         << w.length() << endl;

    const FloatArr kw(w);
    v = w;

    return 0;
}
