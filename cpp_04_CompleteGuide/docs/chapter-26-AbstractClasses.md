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

an abstract class does NOT necessarily need to contain `pure virtual functions`. if the class contains a `protected constructor`, objects of the class type can NOT be created. this constructor can only be called then by methods in derived classes. a constructor of this type normally acts as base initializer, when an object of a derived class type is created.

(can u give me an example? why do u need it?)

link: https://stackoverflow.com/questions/1057221/what-are-practical-uses-of-a-protected-constructor

protected constructor, makes sense when a class is (intended as) an abstract class, a protected constructor is exactly right. in this situation, u do NOT want obj to be initialized from the class but ONLY use it to inherit from.

there are other uses cases, like when a certain set of construction parameters should be limited to derived classes.

## pointers and references to abstract classes

(591)

**although u can NOT define objects for abstract classes, u can declare pointers and references to abstract classes**.

example: `Coworker *felPtr, &coRef;`

### references to `abstract base classes`

**references to base classes are often used as parameters in functions**.

example:

```c++

Coworker(const Coworker&);

```

the copy-constructor expects an obj belonging to a derived class, since the basic class is abstract.

the assignment in the `Coworker` class has a reference as a parameter and returns a reference to the abstract class.

### pointers to abstract base classes

pointers to base classes are generally used to address dynamically allocated objects. if the base class is abstract, u can ONLY allocate memory for objects belonging to derived, concrete classes.

example:

```c++

Coworker* felPtr;
felPtr = new Laborer("Young, Neil", 45., 40);
cout << felPtr->income();

```

since the `income()` method is virtual, a corresponding function found in the derived class `Laborer` is executed.

### polymorphic interface

defining pure virtual methods also determines interfaces for general operations, although the interfaces still need to implemented in the derived classes. **if a derived class contains its own definition of a virtual method, this version will also be executed if an object is referenced by a base class pointer or reference**. abstract classes are therefore also referred to as `polymorphic interface` to derived classes.

## virtual assignment

(593)

### virtual operator functions

operator functions implemented as methods can also be `virtual`. in this case, u can ensure that the right version of an operator will be executed when using a pointer or reference to a base class to address a derived class object.

one example of this is the operator function of an assignment. if the function declaration is NOT virtual, and if function is called via a base class pointer, ONLY the base data of the object is overwritten. any additional data members of the derived class remain unchanged. (aha, more always fill less)

[why was it weird to me?]

in previous chapter-19 overloaing operators, i clearly remember what/why/how to do operator overloading. but, in this chapter-26, it steps further to discuss operator overloading in derived classes.

as u know, the derived classes and hierarchies are caveat when using type converstion (esp. downcasting, upcasting).

### `using virtual assignment`

the assignment was declared virtual in the `Coworker` base class. the derived classes `Laborer` and `Employee` both contain their own version. thus, in the following

example:

```c++

void cpy(Coworker& a, const Coworker& b)
{ a = b; }

```

the assignment of the `Employee` class is executed, if an obj of this class type is the first argument passed to it. if the obj is a `Laborer` type, the assignment of this `Laborer` class is performed.

in the case of the `cpy()` function, u can therefore assign two obj of any class, including classes derived at a later stage, w/o having to modify the function itself! however, u definitly need to define a version of the assigment for each derived class.

### redefining the standard assignment

when u define a new version for a virtual method in a derived class, this implies using the signature of the original method. since the standard assigment of a dervied class has a signature of its own, it it *NOT* virtual. the standard assignment for the `Laborer` class has the following protoype:

example: `Laborer& operator=(const Laborer&);`

the type `const Laborer&` is different from the `const Coworker&` type of the parameter in the virtual operator function of the base class. the standard assignment thus **masks** the virtual assignment in the base class. this gives rise to two issues:

1. the virtual operator function for the assignment MUST be defined for every derived class
2. to ensure that the standard assignment is also available, the standard assignment MUST also be redefined in every derived class.

## application: inhomogeneous lists

(595)

### terminology

an `inhomogeneous list` is a linear list whose elements can be of different types. if the data u need to store consists of obj in a class hierarchy, one list element could contain an obj belonging to the base class, whereas another could contain an obj of a derived class.

due to implicit `type conversion` in class hierarchies, u can use the base class pointers to manage the list elements, that is, u can manage the elements in a linked list.

### representing List elements

to separate the management of list elements from the informatino contained in the list, we have defined an abstract class called `Cell` as a base class for all list elements. the class contains a pointer of type `Cell*` as the data member used to link list elements. since `Cell` type obj are NOT be created, the constructor in the `Cell` class has a `protected` declaration.

the `Cell` class does NOT contain any data that might need to be output. however, each class derived from `Cell` contains data that need to be displayed. for this reason, `Cell` contains a declaration of the pure virtual method `display()`, which can be modified for multiple derivations.

the class `BaseEl` and `DerivedEl`, which are derived from `Cell`, represent list elements used for storing information. to keep things simple, the `BaseEl` class contains only a name, and the `DerivedEl` class additionally contains a commment. the `public` declaration section contains a constructor and access method declarations. in addition, a suitable version of the `display()` method is defined. both classes are thus concrete classes.

## implementation an inhomogeneous list

(597)

### the `inhomeList` class

