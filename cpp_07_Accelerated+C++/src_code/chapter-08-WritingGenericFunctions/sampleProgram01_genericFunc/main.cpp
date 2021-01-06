#include <iostream>

using namespace std;

template<class T>
T sum(T a, T b)
{
    return a + b;
}

int main()
{
    cout << sum<int>(1, 2) << endl;
    cout << sum<double>(1.0, 2.0) << endl;
    cout << sum<float>(3.14, 2.718) << endl;
    cout << sum<long>(3, 4) << endl;

    return 0;
}
