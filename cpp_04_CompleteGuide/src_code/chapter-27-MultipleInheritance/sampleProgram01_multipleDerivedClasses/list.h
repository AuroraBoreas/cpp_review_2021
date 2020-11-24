#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include "cell.h"
#include <string>
#include <iostream>
using namespace std;

class InhomList
{
    private:
        Cell* first;
    protected:
        Cell* getPrev(const string& s);
        Cell* getPos(const string& s);
        void  insertAfter(const string& s, Cell* prev);
        void  insertAfter(const string& s, const string& b, Cell* prev);
        void  erasePos(Cell* pos);
    public:
        // constructor
        InhomList() { first = NULL; } // default constructor
        InhomList(const InhomList& src); // copy constructor
        {
            first = NULL;
            Cell *pEl = src.first;
            for(; pEl != NULL; pEl = pEl->getNext())
                if(typeid(*pEl) == typeid(DerivedEl))
                    insert(dynamic_cast<DerivedEl*>(pEl)->getName(), dynamic_cast<DerivedEl*>(pEl)->getRem());
                else
                    insert(dynamic_cast<BaseEl*>(pEl)->getName());
        }
        ~InhomList();
        InhomList& operator=(const InhomList& src); // assignment op ol
        // methods
        void insert(const string& n);
        void insert(const string& n, const string& b);
        void erase(const string& s);
        void displayAll() const;
};


#endif // LIST_H_INCLUDED
