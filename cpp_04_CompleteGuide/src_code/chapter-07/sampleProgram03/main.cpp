#include <iostream>
#include <cctype> // what's this?

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    char c;
    long nChar(0), nConv(0);

    while(cin.get(c))   // as long as character
    {
        ++nChar;
        if(islower(c))
        {
            c = toupper(c);
            ++nConv;
        }
        cout.put(c);
    }

    // ctrl+z to simulate end-of-file in winos
    clog << "\nTotal of characters:     " << nChar
         << "\nTotal of converted characters: " << nConv
         << endl;

    return 0;
}
