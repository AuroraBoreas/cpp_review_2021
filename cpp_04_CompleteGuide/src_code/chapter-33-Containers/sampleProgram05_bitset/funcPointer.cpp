#include <iostream>
#include <cstdlib>
#include <cctype>
using namespace std;

void message_error(char*), message(char*),
     message_up(char*), message_low(char*),
     (*funcPtr[])(char*) = {message_error, message, message_up, message_low};

char call[] = "index out of range";
char hello[] = "Bonjour toute le monde!";
char prompt[] = "\nChoose your pills to cure your illness between(1, 2, 3): ";

int main()
{
    cout << prompt;
    int n;
    while(cin>>n)
    {
        if(n<1 || n>3)
        {
            (*funcPtr[0])(call);
            break;
        }
        else
        {
            (*funcPtr[n])(hello);
        }
        cout << endl;
        cout << prompt;
    }

    return 0;
}

void message_error(char* s)
{
    cerr << s << endl;
}

void message(char* s)
{
    cout << s << endl;
}

void message_up(char* s)
{
    char c;
    for(; *s != '\0'; ++s)
    {
        c = toupper(*s); cout.put(c);
    }
}

void message_low(char* s)
{
    char c;
    for(; *s != '\0'; ++s)
    {
        c = tolower(*s); cout.put(c);
    }
}
