#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    char charr1[20];
    string str1;

    cout << "before input, length: \n";
    cout << "charr1 : " << strlen(charr1) << endl;
    cout << "str1   : " << str1.size()    << endl;

    cout << "Enter a line of text: \n";
    cin.getline(charr1, 20);
    cout << "Enter another line of text: \n";
    getline(cin, str1);
    cout << "After input, length: \n";
    cout << "charr1 : " << strlen(charr1) << endl;
    cout << "str1   : " << str1.size()    << endl;

    // some experiments.
    cout << "Enter another line of text: \n";
    cin  >> str1;
    cout << "str1 : " << str1 << endl;

    return 0;
}
