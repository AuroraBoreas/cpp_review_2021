#include "tellist.h"
#include <iostream>
#include <iomanip>

bool TelList::append(const std::string& name, const std::string& telNr)
{
    if(   cnt < MAX
       && name.size() > 1
       && search(name) == PSEUDO)
    {
        v[cnt].name  = name;
        v[cnt].telNr = telNr;
        ++cnt;
        return true;
    }
    return false;
}

bool TelList::append(const std::string& key)
{
    int i = search(key);
    if(i != PSEUDO)
    {
        v[i] = v[cnt-1]; --cnt;
        return true;
    }
    return false;
}

int TelList::search(const std::string& key)
{
    for(int i=0; i < cnt; ++i)
    {
        if(v[i].name == key)
            return i;
    }
    return PSEUDO;
}

inline void tabHeader()
{
    std::cout << "\n Name                          Telephone #\n"
                 "----------------------------------------------";
    std::cout << std::endl;
}
