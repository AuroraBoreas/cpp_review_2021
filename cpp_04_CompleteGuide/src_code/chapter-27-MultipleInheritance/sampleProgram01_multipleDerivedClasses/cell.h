#ifndef CELL_H_INCLUDED
#define CELL_H_INCLUDED

#include <iostream>
#include <string>
using std::string;
using std::cout;

class Cell
{
    private:
        Cell* next;
    protected:
        // constructor
        Cell(Cell* suc=NULL)
        {
            next = suc;
        }
    public:
        // destructor
        virtual ~Cell(){}
        // getter
        Cell* getNext(void) const { return next; }
        // setter
        void setNext(Cell* suc) { next = suc; }
        // repr
        virtual void display(void) const = 0;
};

class BaseEl:public Cell
{
    private:

        string name;
    public:
        // constructor
        BaseEl(Cell* suc=NULL, const string& s="")
        : Cell(suc), name(s){}
        // getter
        const string& getName(void) const { return name; }
        // setter
        void setName(const string& s) { name = s; }
        // repr
        void display(void) const
        {
            cout << "\n-------------------------------"
                 << "\nname : " << name;
            cout << "\n";
        }
};

class DerivedEl:public BaseEl
{
    private:
        string rem;
    public:
        // constructor
        DerivedEl(Cell* suc=NULL, const string& s="", const string& b="")
        : BaseEl(suc, s), rem(b){}
        // getter
        const string& getRem(void) const { return rem; }
        // setter
        void setRem(const string& b) { rem = b; }
        // repr
        void display(void) const
        {
            BaseEl::display();
            cout << "remark : " << rem;
            cout << "\n";
        }
};


#endif // CELL_H_INCLUDED
