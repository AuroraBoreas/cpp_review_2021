/*

* @ what is constexpr?
* constexpr
* @ why?
* time saving. compile time(+), run time(-)
* @ how?
* constexpr specifies that the value of an obj or a func can be evaluated at compile time
* and the expression can be used in other constant expressions.
* @ constraints
1. In C++ 11, a constexpr function should contain only one return statement.
   C++ 14 allows more than one statements.
2. constexpr function should refer only constant global variables.
3. constexpr function can call only other constexpr function not simple function.
4. Function should not be of void type
   and some operator like prefix increment (++v) are not allowed in constexpr function.

*/
#include <iostream>

using namespace std;

const int x1 = 100;

constexpr int product(int x, int y)
{
    return x * y;
}


int main()
{
    const int x = product(x1, 20);
    cout << x;

    return 0;
}
