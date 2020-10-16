#include <iostream>

using namespace std;
int& add(int&, int&);
int* mul(int*, int*);

int main()
{
    int a(1), b(2); // *ptr = &a;
    cout << "a = " << a << ", b = " << b << endl;

    cout << "a + b = " << add(a, b) << endl;

    cout << "a * b = " << *mul(&a, &b) << endl;

    return 0;
}

int& add(int& x, int& y)
{
    static int res = x + y;
    // int res = x + y; // exception->crash
    return res;
}

int* mul(int* x, int* y)
{
    static int res = (*x)*(*y);
    return &res;
}
