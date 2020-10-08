#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    int c = cin.get();
    cout << c;
    // input: " "
    // converts into ASCII: 32

    // output: 32
    // input: 123
    // reads as "123", cin.get() reads the very first character '1', and converts it to ASCII 49
    // output: 49

    // input: "hello world"
    // output: 104

    return 0;
}
