#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    string header("    **** Counts words   ****\n"),
           prompt("Enter a text and terminate"
                  " with a period and return:"),
           line(60, '-'),
           text;

    cout << header << endl << prompt << endl
         << line << endl;

    getline(cin, text, '.');

    // counts words and whitespace characters
    int i,
        nSpace = 0,
        nWord  = 0;
    bool fSpace = true;

    for(i=0; i<text.length(); ++i)
    {
        if(isspace(text[i]))
        {
            ++nSpace; fSpace = true;
        }
        else if(fSpace)
        {
            ++nWord; fSpace = false;
        }
    }

    cout << line
         << "\nyour text contains (without periods)"
         << "\n           characters: " << text.size()
         << "\n                words: " << nWord
         << "\n           whitespace: " << nSpace
         << endl;

    return 0;
}
