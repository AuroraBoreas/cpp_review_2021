#include <iostream>
#include <cstdlib>
#include <cctype> // lower, upper
using namespace std;

void message_error(char*),
     message(char*),
     message_up(char*),
     message_low(char*);

void (*funcPtr[])(char*) = { message_error, message, message_up, message_low };

char call[] = "index out of range";
char hw[] = "Hello World!";

int main()
{
    cout << "\nChoose an integer btwn (1, 2, 3): ";
    int n;
    while(cin>>n)
    {
        if(n<1 || n>3)
        {
            (*funcPtr[0])(call);
            break;
        }
        else
            (*funcPtr[n])(hw);
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
        c =  toupper(*s); cout.put(c);
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
