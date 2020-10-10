#include <iostream>
#include <iomanip>

#include "myMacros.h" // pretty straightforward, easier than my thought.

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    char w(8);
    // test macro ABS
    cout << setw(w) << left
         << "ABS(-1)"  << " = " << ABS(-1)
         << endl;
    cout << setw(w) << left
         << "ABS(0)"   << " = " << ABS(0)
         << endl;
    cout << setw(w) << left
         << "ABS(3.1)" << " = " << ABS(3.1)
         << endl;
    cout << endl;
    // test macro MAX
    w = 13;
    cout << setw(w) << left
         << "MAX(111, 101)" << " = " << MAX(111, 101)
         <<endl;
    cout << setw(w) << left
         << "MAX(-1, 1)"    << " = " << MAX(-1, 1)
         << endl;
    cout << setw(w) << left
         << "MAX(-3, -2)"   << " = " << MAX(-3, -2)
         << endl;
    cout << setw(w) << left
         << "MAX(4.0, 4)"   << " = " << MAX(4.0, 4)
         << endl;

    return 0;
}
