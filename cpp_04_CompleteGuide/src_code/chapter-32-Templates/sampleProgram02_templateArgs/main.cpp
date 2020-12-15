#include <iostream>

using namespace std;

template<class T>
T mini(T a, T b)
{
    return ((a < b)? a : b);
}

template<class T>
void display(T x, T y)
{
    cout << "x = " << x << ", y = " << y << "\n"
         << "the smaller one is " << mini(x, y) << "\n";
}

int main()
{
    int x = 1;
    int y = 2;
    display(x, y);

    double a = 3.1415926;
    double b = 2.7182818;
    display(a, b);

//    double c = a;
//    float  d = 1.1111;
//    display(c, d); // not OK
    return 0;
}
