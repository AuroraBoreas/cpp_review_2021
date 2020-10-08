#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    char ch;
    string word;

    cout << "Let's go! Press the return key: ";
    cin.get(ch);
    cout << "Enter a word containing three characters at most: ";
    cin >> word;
    cout << "Your input: " << word << endl;

    return 0;
}
