#include <iostream>
using namespace std;

int main()
{
    const int a(1), b(2),
              *p;
    int c(3), d(4),
        *np;

    // const pointer to const obj, non-const obj
    p = &a;
    //*p = 10; // Error..
    p = &c;
    //&p = 10; // Error..

    // non-const pointer to const obj, non-const obj
    // np = &b;  // Error..
    // *np = 10; // Error..
    np = &d;
    *np = 10; // OK.

    char ch[] = "hello world",
         *ptr = ch;
    ptr += 3;
    cout << ptr << endl;

    /*
    (https://stackoverflow.com/questions/501816/why-does-cout-print-char-arrays-differently-from-other-arrays)

    It's the operator<< that is overloaded for const void* and for const char*.

    Your char array is converted to const char* and passed to that overload,
    because it fits better than to const void*.

    The version taking the const char* actually treats it like a C-string
    and outputs every character until the terminating null character.
    */
    return 0;
}
