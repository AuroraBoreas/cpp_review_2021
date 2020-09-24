/*
definition and use of variables
*/
#include <iostream>

using namespace std;


int gVar1;
int gVar2 = 2;

int main()
{
    cout << "Hello world!" << endl;
    char ch('A'); // or char ch = "A";

    cout << "Value of gVar1: " << gVar1 << endl;
    cout << "Value of gVar2: " << gVar2 << endl;
    cout << "Character in ch:" << ch << endl;

    int sum, number = 3;
    sum = number + 5;
    cout << "Value of sum: " << sum << endl;

    return 0;
}
