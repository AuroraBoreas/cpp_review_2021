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

the new version of a virtual method is automatically virtual itself. this means **u can OMIT the `virtual` keyword in the declaration**.

when u redefine a `virtual` function, be aware of the following:

- if the return type is a pointer or reference to the base class, the new version of the `virtual` method can also return a pointer or reference to a derived class (NOTE: not all compilers support this option)
- constructors can NOT have a `virtual` declaration
- a base class method does NOT become `virtual` just because it is declared as `virtual` in a derived class.
  
if u use a different signature or return type of a virtual base class method to define a method in a derived class, this simply creates a new method with the same name. the method will not necessarily be `virtual`.

however, the `virtual` method in the base class will be masked by the method in the derived class. in other words, only the `non-virtual` version of the method is available for a derived class object.

[why] do i need `virtual` method thou?

link: https://stackoverflow.com/questions/2391679/why-do-we-need-virtual-functions-in-c

without `virtual`, u get "early binding", which implementation of the method is used gets decided at compile-time based on the type of the pointer that u call through.

with `virtual`, u get "late binding". which implementation of the method is used gets decided at run-time based on the type of the pointed-to objects - what it was originally constructed as. this is NOT necessarily what u'd think based on the type of the pointer that points to that object.

example:

```c++

using std::cout

class Animal
{
    public:
        void eat() { cout << "Im eating generic food."; }
};

class Cat: public Animal
{
    public:
        void eat() { cout << "Im eating a rat."; }
};

Animal* animal = new Animal;
Cat* cat = new Cat;

animal->eat();  // output: Im eating generic food.
cat->eat();     // output: Im eating a rat.

// BUT

Animal* cat2 = new Cat; // more always fill less
cat2->eat(); // output: Im eating a generic food. this is not working as expect

// conclusion
/*
even thou u assign the subclass object(Cat),
the method being invoked is based on the pointer type(Animal) not the type of object it points to. 

this is why u need "virtual"
*/

```

example:

```c++

using std::cout;

class Animal
{
    public:
        virtual void eat() { cout << "Im eating generic food."; }
};

class Cat: public Animal
{
    public:
        void eat() { cout << "Im eating rat."; }
}

Animal *animal = new Animal, *cat = new Cat;

animal->eat();  // output: Im eating generic food.
cat->eat();     // output: Im eating rat.

```

## destroying dynamically allocated objects

dynamically created objects in a class hierarchy are normally handled by a base class pointer. when such an object reaches the end of its lifetime, the memory occupied by the object MUST be released by a `delete` statement.

example:

```c++

Car *carPtr;
carPtr = new PassCar("500", false, 21, "Geo");
//...
delete carPtr;

```

### destructor calls

when memory is released, the destructor for an object is automatically called. if multiple constructors were called to create the object, the corresponding destructors are called in reverse order. what does this mean for objects in derived classes? **the destructor of the derived class is called first and then the destructor of the base class executed**.

if u use a base class pointer to manage an object, the appropriate `virtual` methods of the derived class are called. however, non-virtual methods will always execute the base class version.