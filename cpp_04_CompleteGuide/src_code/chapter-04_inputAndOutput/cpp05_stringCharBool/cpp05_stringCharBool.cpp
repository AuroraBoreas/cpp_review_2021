#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    //
    int number = ' ',
    cout << "The whitespace code is as follows: "
         << number << endl;
    char ch;
    string prompt("\nPlease enter a character followed by <return>: ");
    cout << prompt;
    cin >> ch;

    number = ch;
    cout << "the character " << ch << " has code" << number << endl;

    cout << uppercase
         << "   octal   decimal     hexadecimal\n"
         << oct << setw(8) << number
         << dec << setw(8) << number
         << hex << setw(8) << number << endl;
         
    return 0;
}