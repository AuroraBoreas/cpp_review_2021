#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    auto a = 1;
    auto b = 2.0;
    auto c = 'c';

    // auto a = 1, b = 2.0, c = 'c'; // exception

    cout << a << << setprecision(2) << b << c << endl;

    return 0;
}
