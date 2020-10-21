#include <iostream>
#include <cmath>

#define COUNT  20

using namespace std;

int main()
{
    int arrFib[COUNT+1] = {0, 1};
    int i;
    for(i = 1; i < COUNT+1; ++i)
    {
        arrFib[i+1] = arrFib[i] + arrFib[i-1];
    }

    double lim = (1.0 + sqrt(5.0)) / 2.0;

    cout << "Fib: 0\t1\t";
    for(i = 2; i < COUNT+1; ++i)
    {
        cout << arrFib[i] << '\t';
    }


    return 0;
}
