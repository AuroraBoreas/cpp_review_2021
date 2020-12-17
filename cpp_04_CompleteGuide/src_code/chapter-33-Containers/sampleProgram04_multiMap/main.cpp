#include <iostream>
#include <map>
#include <string>

using namespace std;

typedef multimap<int, string> MulMap;
typedef MulMap::const_iterator mulMapIter;

inline void display(const MulMap& m)
{
    cout << endl;
    mulMapIter pos;
    for(pos=m.begin(); pos != m.end(); ++pos)
        cout << pos->first << " " << pos->second << endl;
    cout << endl;
}


int main()
{
    MulMap mm;
    mm.insert(pair<int, string>(7, "ZL"));
    mm.insert(pair<int, string>(4, "SCY"));
    mm.insert(pair<int, string>(5, "LL"));
    mm.insert(pair<int, string>(3, "ZZ"));
    mm.insert(pair<int, string>(1, "SS"));
    mm.insert(pair<int, string>(1, "DD"));

    display(mm);

    mulMapIter pos;
    pos = mm.find(3);
    if(pos != mm.end())
        cout << pos->first << " " << pos->second << endl;
    cout << endl;

    int key = 1;

    cout << "there are " << mm.count(key)
         << " pairs with key " << key << endl;


    return 0;
}

