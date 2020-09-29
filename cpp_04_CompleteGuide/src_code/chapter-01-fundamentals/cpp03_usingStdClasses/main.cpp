// to use strings
#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    // defines four strings
    string prompt("what is your name:"),
           name,
           line(40, '-'),
           total = "hello ";

    cout << prompt;
    getline(cin, name);
    total = total + name;

    cout << line << endl
         << total << endl;
    cout << "Your name is "
         << name.length() << " characters long!" << endl;
    cout << line << endl;


    return 0;
}
