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

/*
only the base class destructor for Car was executed. as the PassCar destructor is not called, neither is the destructor called for the data member passCarType, which is additionally defined in the derived class. the data member passCarType is a string, however, and occupies dynamically allocated memory -- this memory will not be released.
*/

```

### destructor calls

when memory is released, the destructor for an object is automatically called. if multiple constructors were called to create the object, the corresponding destructors are called in reverse order. what does this mean for objects in derived classes? **the destructor of the derived class is called first and then the destructor of the base class executed**.

if u use a base class pointer to manage an object, the appropriate `virtual` methods of the derived class are called. however, non-virtual methods will always execute the base class version.

if multiple objects are created dynamically in the derived class, a dangerous situation occurs. more and more unreferenced memory blocks will clutter up the main memory w/o u being able to reallocated them -- this can seriously impact your program's response and even lead to external memory being swapped in.

### `virtual destructor`

this issue can be solved simply by declaring virtual destructors.

a class used as a base class for other classes should always have a virtual destructor defined. even if the base class does NOT need a destructor itself, it should at least contain a dummy destructor, that is, a destructor with an empty function body.

## `virtual method table`

(571)

### static binding

when a non-virtual method is called, the address of the function is known at time of compilation. the address is inserted directly into the machine code. this is also referred to as `static` or `early binding`.

if a virtual method is called via an object's name, the appropriate version of this method is also known at time of compilation. so this is also a case of early binding.

### dynamic binding

however, if a virtual method is called by a pointer or reference, the function that will be executed when the program is run is unknown at time of compilation. the statement

example: `carPtr->display();`

could execute different version of the `display()` method, depending on the object currently referenced by the pointer.

the compiler is therefore forced to create machine code that does NOT form an association with a particular function until the program is run. this is referred to as `late` or `dynamic binding`.

example: `virtual, dynamic binding; non-virtual, static binding;`

### `VMT`

`dynamic binding` is supported internally by `virtual method table`(or `VMT` for short). a VMT is created for each class with at least one virtual method -- that is, an array with the address of the virtual methods in the current class.

each object in polymorphic class contains a VMT pointer, that is, a hidden pointer to the VMT of the corresponding class. `dynamic binding` causes the virtual function call to be executed in two steps.

1. the pointer to the VMT in the referenced object is read
2. the address of the virtual method is read in the VMT

in comparison with `static binding`, `dynamic binding` does have the disadvantage that `VMT`s occupy memory. moreover, program response can be impaced by indirect addressing of virtual methods.

however, this is a small price to pay for the benefit. `dynamic binding` allows u to enhance compiled source code w/o having access the source code.

## dynamic casts

(573)

### safety issues in `downcasting`

downcasts in class hierarchies are unsafe if u use a `C cast` or the `static_cast` operator. if the referenced object does NOT correspond to the type of the derived class, fatal runtime errors can occur.

given that `carPtr` is a pointer to the base class `Car`, which is currently pointing to a `PassCar` type, the statement

example:

```c++

Truck *truckPtr = static_cast<Truck*>(carPtr); // more always fill less.

// will NOT cause a compiler error. but the following statement could cause the program to crash.

truckPtr->setAxles(10);

```

### the `dynamic_cast<>` operator

u can use the cast operator `dynamic_cast<>` to perform safe downcasting in polymorphic classes. at runtime, the operator checks whether the required conversion is valid or not.

syntax: `dynamic_cast<type>(expression)`

if so, the expression `expression` is converted to the target type `type`. the target type must be a pointer or reference to a polymorphic class or a `void` pointer. if it is a pointer type, `expression` must also be a pointer type. if the target type is reference, `expression` must identify an object in memory.

if `dynamic_cast<>` operation failed, it will return a `NULL` pointer.

the `dynamic_cast` can also be used for upcasting. the classes involved do NOT need to polymorphic in this case. however, type checking is NOT performed at runtime. an erroneous upcast is recognized and reported by the compiler.
