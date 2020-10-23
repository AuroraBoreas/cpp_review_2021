#include <iostream>
#include <string>
#define MAXL 200

using namespace std;

namespace MyScope // declaration
{
    const char* strstr(const char *str, const char* patt);
}

char line[500],
     patt[] = "is";

int main()
{
    int lineNr = 0;
    while(cin.getline(line, MAXL))
    {
        ++lineNr;
        if(MyScope::strstr(line, patt) != NULL)
        {
            cout.width(3);
            cout << lineNr << ": "
                 << line << endl;
        }
    }

    return 0;
}
