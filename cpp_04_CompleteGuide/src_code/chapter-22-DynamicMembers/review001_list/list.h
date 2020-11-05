#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include "date.h"
using namespace std;

class ListEl
{
    //...
    private:
        Date date;
        double amount;
        ListEl *next;
    public:
        // constructor
        ListEl(Date d=Date(1, 1, 1),
               double b=0.0,
               ListEl *p=NULL)
        : date(d), amount(b), next(p) {}
        // getter
        const Date& getDate(void) const { return date; }
        double getAmount(void)    const { return amount; }
        ListEl* getNext(void)     const { return next; }
        // setter
        void setDate(void)                { date.setDate(); }
        bool setDate(int y, int m, int d) { return date.setDate(y, m, d); }
        void setAmount(double w)          { amount = w; }
        // friend class
        friend class List;
};

inline ostream& operator<<(ostream& os, const ListEl& le)
{
    //...
    os << le.getDate().asString() << " Amount: ";
    os << fixed << setprecision(2) << setw(10) << le.getAmount();
    return os;
}

class List
{
    //...
    private:
        ListEl *first, *last;
    public:
        // constructor
        List() { first = last = NULL; }
        ~List()
        {
            ListEl *pEl = first, *next = NULL;
            for(; pEl != NULL; pEl = next)
            {
                next = pEl->next;
                delete pEl;
            }
        }
        // push
        void pushBack(const Date& d, double b)
        {
            ListEl *pEl = new ListEl(d, b);
            if(last == NULL)
                first = last = pEl;
            else
                last->next = pEl, last = pEl;
        }
        // pop
        void popFront()
        {
            if(first != NULL)
            {
                ListEl *pEl = first;
                first = first->next;
                delete pEl;
                if(first == NULL)
                    last = NULL;
            }
        }
};

inline ostream& operator<<(ostream& os, const List& List)
{
    ListEl *pEl = List.front();
    if(pEl == NULL)
        os << "The list is empty!" << endl;
    for(; pEl != NULL; pEl = pEl->getNext())
        os << *pEl << endl;
    return os;
}

#endif // LIST_H_INCLUDED
