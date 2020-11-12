# polymorphism

(564)

topics:

- how to develop and manage polymorphic classes
- defining virtual functions
- dynamic downcasting in polymorphic class hierarchies

## concept of polymorphism

(565)

example:

```c++
// classes with virtual methods:
Base:
    base class with virtual method display()

Derived1, Derived2:
    derived from Base with its own redefinitions
    of method display()

Base class pointer and objects:
    Base* basePtr;
    Derived1 angular;
    Derived2 round;

// classing virtual methods

when a virtual method is called, the corresponding versino of the method is executed for the object currently referenced.

basePtr = &angular;
basePtr->display();

basePtr = &round;
basePtr->display();

```

### issues

if the special feature of derived class objects are insignificant, u can simply concern yourself with the base members. this is the case when dynamic allocated objects are inserted into a data structure or deleted from the structure.(?)

it makes sense to use pointer or reference to the base class in this case -- no matter what type of concrete object u are dealing with. however, u can only access the common base members of these objects.

however, u should be able to activate the special features of a derived class when

- the object is accessed by a pointer or reference to the base class and
- the concrete object type will not be known until the program is executed.

### traditional approach

traditional programming languages solved this issue by adding a **type field** both to the base class and to the derived classes. the type field stored the type of the current class. a function that manages objects via the base class pointer could query the concrete type in a switch statement and call the appropriate method.

**this solution has a disadvantage**; adding derived classes at a later stage also meant adding a case label and recompiling.

### object-oriented approach

the approach adopted by object-orient languages is `polymorphism`(Greek for multi-form). in C++, `virtual methods` are used to implement polymorphic classes. calling a virtual method makes the compiler execute a version of the method `suitable` for the object in question, when the object is accessed by a pointer or a reference to the base class.