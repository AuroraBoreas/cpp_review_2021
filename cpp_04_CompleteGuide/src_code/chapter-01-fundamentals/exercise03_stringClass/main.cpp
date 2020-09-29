#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    string sentence("I have learned something new again!"),
           text,
           line(40, '*');
    cout << sentence << " length: " << sentence.length() << endl;
    getline(cin, text);
    cout << line << endl;
    cout << text << endl;
    cout << line << endl;

    return 0;
}
