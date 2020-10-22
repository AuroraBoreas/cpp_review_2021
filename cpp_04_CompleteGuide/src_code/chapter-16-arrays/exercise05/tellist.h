#ifndef TELLIST_H_INCLUDED
#define TELLIST_H_INCLUDED

#include <string>
#define PSEUDO -1
#define MAX 100

struct Element { std::string name, telNr; };

class TelList
{
    private:
        Element v[MAX];
        int cnt;
    public:
        TelList() { cnt = 0; }
        int getCnt() const { return cnt; }
        Element *retrieve(int i)       { return (i >= 0 && i < cnt)? &v[i] : NULL; }
        bool append(const Element& el) { return append(el.name, el.telNr); }
        // declarations only, definitions are in SF
        bool append(const std::string& name, const std::string& telNr);
        bool erase(const std::string& name);
        int  search(const std::string& name);
        void print(void);
        int  print(const string& name);
        int  getNewEntries(void);
};


#endif // TELLIST_H_INCLUDED
