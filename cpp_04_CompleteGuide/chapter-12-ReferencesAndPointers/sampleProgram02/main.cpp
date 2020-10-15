#include <iostream>
#include <string>

using namespace std;

float x = 10.7F;

int main()
{
    float &rx = x;
    // double &ref = x; // exception: different type

    rx *= 2;
    cout << "   x = " << x << endl
         << "  rx = " << rx << endl;

    // read-only reference
    const float& cref = x;
    cout << "cref = " << cref << endl; // OK
    // ++cref; // exception
    const string str = "I am a constant string!";
    // str = "That doesn't work!"; // exception
    // string& text = str;         // exception
    const string& text = str;
    cout << text << endl;

    return 0;
}
