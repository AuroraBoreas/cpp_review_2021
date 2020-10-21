#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

char header[] = "\n    ***   C Strings   ***\n\n";

int main()
{
    char hello[30] = "hello ", name[20], message[80];
    cout << header   << "your first name: ";
    cin  >> setw(20) >> name;
    //cin  >> name;   // i see..., w/o setw(20) statement, user input overflows array name[20]. program crashes.

    strcat(hello, name);
    cout << hello << endl;
    cin.sync();

    cout << "\nwhat is the message for today?" << endl;
    cin.getline(message, 80); // why not getline(message)? same reason: constrain user input to avoid overflow. or program crashes.
    if(strlen(message) > 0)
    {
        for(int i = 0; message[i] != '\0'; ++i)
            cout << message[i] << ' ';
        cout << endl;
    }

    return 0;
}
