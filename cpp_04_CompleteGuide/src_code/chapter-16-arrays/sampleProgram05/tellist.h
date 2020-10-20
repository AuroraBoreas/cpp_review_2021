#ifndef TELLIST_H_INCLUDED
#define TELLIST_H_INCLUDED

// (353) telList.h
#include <string>
#define PSEUDO -1
#define MAX    100

using namespace std;

struct Element { string name, telNr; };

class TelList
{
    private:
        Element v[MAX]; // Element array with MAX size
        int counter;
    public:
        // constructor
        TelList() { counter = 0; }
        // getter
        int getCounter(void) const { return counter; }
        Element* retrieve(int i)   { return (i>=0 && i < counter)? &v[i]:NULL; }

        bool append(const Element& el) { return append(el.name, el.telNr); }
        bool append(const string& name, const string& telNr);
        bool erase(const string& name);
        int  search(const string& name);
        void print(void) const;
        int  print(const string& name);
        int  getNewEntries();


};


#endif // TELLIST_H_INCLUDED
