# abstract classes

(586)

topics:

1. how `abstract classes` can be created by defining pure virtual methods
2. how u can use `abstract classes` as a polymorphic interface for derived classes.

## pure virtual methods

(587)

### motivation

virtual methods are declared in the base class to ensure that they are available in any derived classes via the common class interface. it may happen that they rarely perform any useful tasks in the base class.

in this case, u can define a virtual dummy method whose address is entered in the VMT of the base class. however, this creates op-code for a function that should never be called. it makes more sense NOT to define a function like this. and this is where C++ steps in and gives u the opportunity of declaring `pure virtual methods`.

### declaration

when a `pure virtual method` is declared, the method is identified by adding the expression `= 0`.

example:

```c++
// coworker.h
#ifndef COWORKER_H_INCLUDED
#define COWORKER_H_INCLUDED

#include <string>
using std::string;

class Coworker
{
    private:
        string name;
    public:
        // constructor
        Coworker(const string& s="")
        { name = s; }
        virtual Coworker& operator=(const Coworker&);
        // destructor
        virtual ~Coworker() {};
        // getter
        const string& getName(void) const { return name; }
        // setter
        void setName(const string& n) { name = n; }
        // repr
        void display(void) const;
        // pure virtual method
        virtual double income(void) = 0;
};

#endif //COWORKER_H_INCLUDED

```

example: `virtual void demo() = 0; // pure virtual`

this informs the compiler that there is no definition of the `demo()` method in the class. **A `NULL pointer` is then entered in the virtual method table for the pure virtual method**.

## abstract and concrete classes

(589)

### concrete or abstract?

if a class comprises `pure virtual method`, **u can NOT create objects of this class type**.

example:

```c++

Coworker worker("Black, Michael"); // error as the Coworker class contains the pure virtual method income().

```

**a class that does NOT allow u to create any objects is referred to as an `abstract class`**.

in contrast, a class that allows u to create objects is referred to as a `concrete class`.

table: concrete class vs abstract class

| item          | concrete class          | abstract class                                      |
|---------------|-------------------------|-----------------------------------------------------|
| what          | allows to create obj    | NOT allow to create obj                             |
| how           | normal method           | `virtual typename method_name(typename args) = 0;`  |
| why           | SOLID                   | SOLID                                               |

### deriving abstract classes

when a class derived from an abstract class, it inherits all the methods the base class contains, particularly the `pure virtual method`. if **all of these pure virtual methods are implemented in the drived class**, u can then create an object of the drived class type.

- `VMT` : `virtual method table`, page 571
- `PVM` : `pure virtual method`, page 590


a class dervied from a concrete class can again contain `pure virtual methods`, due to additional definitions in the derived class. in other words, `an abstract class can be derived from a concrete class`.

an abstract class does NOT necessarily need to contain `pure virtual functions`. if the class contains a `protected constructor`, objects of the class type