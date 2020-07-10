// address.cpp -- using the & operator to find addresses of variables.
#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    int donuts = 6;
    double cups = 4.99;

    cout << "donuts value   = " << donuts << "\n"
         << "donuts address = " << &donuts << "\n";

    cout << "cups value   = " << cups << "\n"
         << "cups address = " << &cups << "\n";


    return 0;
}
