#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::boolalpha;

int main()
{
    int a = 12;
    // how to get -12?
    int b = ~a + 1; // this is the way
    cout << boolalpha << (b == -12) << endl;

    return 0;
}
