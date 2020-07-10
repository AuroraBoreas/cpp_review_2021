#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    int higgens = 5;
    int* p_higgens = &higgens;

    cout << "Value of higgens = " << higgens
         << "; address of higgens = " << &higgens << endl;

    cout << "Value of *p_higgens = " << *p_higgens
         << "; address of higgens = " << p_higgens << endl;

    return 0;
}
