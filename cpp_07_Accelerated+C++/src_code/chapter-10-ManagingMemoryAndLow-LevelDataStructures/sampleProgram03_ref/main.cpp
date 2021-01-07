/*
&& is new in C++11.
int&& a means "a" is an r-value reference.
&& is normally only used to declare a parameter of a function.
And it only takes a r-value expression
*/

#include <iostream>
#include <iomanip>

using namespace std;

void foo(int&& a){};

int main()
{
    unsigned a = 11;
    unsigned& refa = a;
    cout << refa << endl;
    cout << std::boolalpha << (&refa == &a) << endl;

    // unsigned& refb; // not OK
    unsigned&& rrefb = 6;
    cout << rrefb << endl;

    int b = 1;
//    foo(b); // not OK
    foo(5); // OK
    foo(b+3); // OK

//    int&& c = b; // not OK
    int&& c = 5; // OK
    int&& d = std::move(b);
/*

std::move is used to indicate that an object t may be "moved from",
i.e. allowing the efficient transfer of resources from t to another object.

In particular,
std::move produces an xvalue expression that identifies its argument t.
It is exactly equivalent to a static_cast to an rvalue reference type.

*/

    return 0;
}
