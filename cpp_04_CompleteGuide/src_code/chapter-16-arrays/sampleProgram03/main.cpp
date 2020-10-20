#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

#define TERMINATE_NULL '\0'
#define NAME_SIZE 20
#define MSG_SIZE 80

char header[] = "\n    *** c string ***    \n\n";

int main()
{
    char hello[] = "hello ", name[NAME_SIZE], msg[MSG_SIZE];
    cout << header;

    // get name from user input
    cout << "your name: ";
    cin >> setw(NAME_SIZE) >> name; // setw(20) constrains overflow
    strcpy(hello, name);
    cout << hello << endl;
    cin.sync(); // clear previous user input in IO buffer

    // get msg from user input
    cout << "what is your message today?" << endl;
    cin.getline(msg, MSG_SIZE);
    if(strlen(msg) > 0)
    {
        for(int i=0; msg[i] != TERMINATE_NULL; ++i)
            cout << msg[i] << ' ';
        cout << endl;
    }
    cout << endl;

    return 0;
}
