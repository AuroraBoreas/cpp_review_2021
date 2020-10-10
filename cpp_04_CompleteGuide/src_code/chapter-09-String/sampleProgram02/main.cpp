#include <iostream>
#include <string>

using namespace std;

string prompt("Please enter some text!\n"),
       line(50, '-');

int main()
{
    prompt+="Terminate the input with an empty line.\n ";
    cout << line << '\n' << prompt << line << endl;
    string text, line;
    while(true)
    {
        getline(cin, line); // Reads a line of text
        if( line.length() == 0) // Empty line?
            break; // Yes ->end of the loop
        text = line + '\n' + text; // Inserts a new line at the beginning.
    }
    // Output:
    cout << line << '\n'
         << "Your lines of text in reverse order:"
         << '\n' << line << endl;
    cout << text << endl;
    return 0;
}
