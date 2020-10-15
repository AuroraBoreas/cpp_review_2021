#include <iostream>
#include <string>

using namespace std;

string& message(void);

int main()
{
    cout << "Hello world!" << endl;
    string s = message();
    cout << s << endl;

    return 0;
}


string& message()
{
    // static string str = "today only cold cuts!";
    string str = "today only cold cuts!";
    return str;
}
