#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    float x = 1.2, &rx = x;
    cout << rx << endl;
    cout << &rx << endl;


    return 0;
}
