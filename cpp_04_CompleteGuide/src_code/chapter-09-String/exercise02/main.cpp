#include <iostream>
#include <string>

using namespace std;

string reverse_str(string s);

int main()
{
    string user_input, reversed_user_input,
           header("Enter a word with period ended: "),
           line(50, '-');

    cout << header << endl << line << endl;
    while(cin >> user_input)
    {
        reversed_user_input = reverse_str(user_input);
        if(user_input == reversed_user_input)
        {
            cout << "your word: " << user_input
                 << " is palindrome!" << endl;
        }
        else
        {
            cout << "your word is NOT a palindrome!" << endl;
        }
        cout << endl << header << endl << line << endl;
        cout << "(continue? or press Ctrl+C to stop)" << endl;
    }

    return 0;
}

string reverse_str(string s)
{
    string res;

    for(unsigned int i=0; i < s.length(); ++i)
    {
        res = s[i] + res;
    }

    return res;
}
