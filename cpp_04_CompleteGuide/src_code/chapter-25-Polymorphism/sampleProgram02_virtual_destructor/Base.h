#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <cstring>
using std::cout;

class Base
{
    public:
        Base()
        { cout << "Constructor of class Base\n"; }
        virtual ~Base()
        { cout << "Destructor of class Base\n"; }
};

class Data
{
    private:
        char* name;
    public:
        Data(const char *n)
        {
            cout << "Constructor of class Data\n";
            name = new char[strlen(n) + 1]; strcpy(name, n);
        }
        ~Data()
        {
            cout << "Destructor of class Data for "
                 << "object: " << name << "\n";
            delete [] name;
        }
};

class Derived: public Base
{
    private:
        Data data;
    public:
        Derived(const char *n): data(n)
        { cout << "Constructor of class Derived\n"; }
        ~Derived()  // implicit virtual
        { cout << "Destructor of class Derived\n"; }
};


#endif // BASE_H
