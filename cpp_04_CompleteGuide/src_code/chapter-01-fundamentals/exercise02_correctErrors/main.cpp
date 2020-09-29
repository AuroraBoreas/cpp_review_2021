#include <iostream>
#include <string>
#include <cstdlib>
//#void srand(seed);

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    string message("\nLearn from your mistakes!");
    cout << message << endl;

    int len = message.length();
    cout << "Length of the string: " << len << endl;

    int a, b;
    srand(12.5);
    b = rand();
    cout << "\nRandom number: " << b << endl;

    return 0;
}
