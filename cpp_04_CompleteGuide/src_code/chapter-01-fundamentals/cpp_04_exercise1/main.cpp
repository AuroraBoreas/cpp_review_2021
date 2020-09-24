#include <iostream>

using namespace std;
void output(string);

int main()
{
    cout << "Hello world!" << endl;
    output("Oh what");
    output("a happy day!");
    output("Oh yes,");
    output("what a happy day!");
    return 0;
}

void output(string s)
{
    cout << s << endl;
}
