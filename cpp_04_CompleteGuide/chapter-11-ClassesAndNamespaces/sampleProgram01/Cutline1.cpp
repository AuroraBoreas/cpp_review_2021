// Cutline1.cpp
// A filter to remove white-space characters
// at the ends of lines.
// --------------------------------------------------

#include <iostream>
#include <string>
#include "Cutline2.h"

using namespace std;

string line;

int main()
{
    while(getline(cin, line))
    {
        cutline();
        cout << line << endl;
    }
    return 0;
}
