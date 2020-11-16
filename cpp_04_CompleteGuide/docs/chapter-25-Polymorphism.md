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

## virtual methods

(567)

### declaring virtual methods

the `virtual` keyword is used to declare a virtual method in a base class.

example:

```c++
virtual void display() const;
```

the definition of a virtual method is no difference from the definition of any other member function.

a virtual method does NOT need to be redefined in the derived class. the derived class then inherits the virtual method of the base class.

### redefinition

however, it is common practice for the derived class to define its own version of the virtual method, which is thus modified to suit the special features of the derived class.

creating a proprietary version of a virtual method means redefining that method. the redefinition in the derived class must have:

1. the same signature and
2. the same return type
   
as the virtual method in the base class.

