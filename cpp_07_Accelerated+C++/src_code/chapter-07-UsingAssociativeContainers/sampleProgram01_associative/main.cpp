#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    map<string, int> counters;
    string s;
    // read input
    while(cin>>s && s != "-1")
        ++counters[s];

    // write
    for(map<string, int>::const_iterator it = counters.begin();
        it != counters.end();
        ++it)
    {
        cout << it->first << "\t" << it->second << endl;
    }

    return 0;
}
