# multiple inheritance

(608)

topics:

1. how new classes are created by multiple inheritance and
2. explians their uses.
3. besides introducing u to creating and destroying objects in multiple-derived classes, virtual base classes are depicted to avoid ambiguity in multiple inheritance.

## multiple-derived classes

(609)

a class can contain NOT just one but several different base classes. in this case, the class is derived from multiple base classes in a process known as `multiple inheritance`.

```c++

#ifndef HOME_H
#define HOME_H

class Car
{
    private:
        // ...
    public:
        // ...
};

class Home
{
    private:
        // ...
    public:
        // ...
};

class MotorHome: public Car, public Home
{
    private:
        // ...
    protected:
        // ...
    public:
        // ...
};

#endif // HOME_H

```

### the multiple-derived class `MotorHome`

pass

### accessibility of Base Classes

when defining a multiple-derived class, the accessibility, `private`, `protected` or `public`, must be defined separately for each base class. 

example:

```c++

class MotorHome: public Car, protected Home
{ ... };

// if the keyworkd is omitted, the base class will default to `private`
class MotorHome: public Car, Home
{ ... };

```

this statement defines the `public` base class `Car` and the `private` base class `Home`. this makes all the `public` members in `Home` `private` members of the derived class.

in multiple inheritance each `public` base class establishes an `is relationship`. this is similar to simple inheritance. if the `MotoHome` class inherits two `public` base classes, a motor-home is a special kind of motor vehicle and a special kind of home.

## multiple indirect base classes

(611)

```c++

class SUV:public PassCar, public Van
{ ... };

```

### multiple indentical base classes

when multiple-derived classes are defined, **a direct base class can NOT be inherited more than once**. the following statement

example:

```c++

class B: public A, public A // Error
{ ... };

```

a class can be derived from several classes that have a common base class, however. this class is then referred to as a `multiple indirect base class`.

### ambiguity

an obj of the SUV class thus contains the members of `Car` *twice*. access to members of the `Car` class results in ambiguity.

example:

```c++

SUV mySUV(...)
cout << mySUV.getProd(); // Error

```

both the base classes `PassCar` and `Van` contain a method called `getProd()`, which they both inherited from the `Car` class. in this case, the compiler can NOT decide which method is meant.

ambiguity in the context of multiple inheritance is also possible when *several* base classes contain members with identical names. if both the `Home` class and `Car` class contain a method called `getNr()`, the `getNr()` method can NOT be correctly identified in the following statement.

example:

```c++

MotorHome motorHome(...);
motoHome.getNr(); // Error

```

**to resolve ambiguity of this kind, u can use the `scope resolution operator` to determine which base class is meant**.

example:

```c++

cout << motorHome.Home::getNr(); 
cout << mySUV.PassCar::getProd();

```

## virtual base classes

(613)

```c++

class PassCar:public virtual Car
{ ... };

class Van:public virtual Car
{ ... };

```

### issues

**u will NOT normally want a class created by multiple inheritance to contain multiple instances of an indirect base class**. why should a station wagon contain two version of the manufacturer's name or the chassis number for example? so u minght be asking yourself whether u can define multiple-derived classes that will contain only one instance of an indirect base class.

c++ uses `virtual base classes` to do this. an obj in a multiple-derived class contains only one instance of the members in a virtual base class.

### declaration

a direct base class is declared `virtual` when a derived class is defined. u can use the `virtual` keyword, which directly precedes the name of the base class.

a virtual base class takes effect in cases of multiple inheritance. the following defintion

example:

```c++

class SUV:public PassCar, public Van
{ ... };

```

ensures that the SUV class only contains one instance of the virtual base class `Car`. an obj `my` of the `SUV` class gets sufficient memory for only one `Car` class sub-obj. more specifically, the statement

example:

```c++

cout << "Producer: " << mySUV.getProd(); // OK

```

does NOT cause ambiguity.

the following items are IMPORTANT with respect to `virtual` base classes.

- a virtual base class stays virtual even if further derivations are built. each class derived from `PassCar` also has the `Car` class as a `virtual` base class.
- u can NOT change the declaration of an indirect base class to `virtual`.

u MUST therefore decide what classes are to be declared `virtual` when u design the class hierarchy. later modifications will require modifications to the source code of any derived classes.

## constructor calls

(615)

### building an inheritance grah

```c++

class Base1
{ ... };

class Base2
{ ... };

class Base3
{ ... };

class multiDerived: public Base1, public Base2, public Base3
{ ... };

```

### initialization

when an obj is created in a simply-derived class, the sub-obj of the base classes are created first on all levels of the class hierarchy. the sub-obj whose class is nearer to the top of the inheritance graph is created first.

the order of the constructor calls is "top down" and follows the inheritance graph. the activation order used for the constructors in simple inheritance has been generalized for multiple inheritance.

### inheritance graph

again, the inheritance graph, also called `sub-object lattice`, has an important job to do. when a derived class is defined, the following rules apply:

- in cases of multiple inheritance, base classes are enter into the inheritance graph **from left to right** in the order in which they were stated when the class was defined.

if the class hierarchy does NOT contain any virtual base classes, the following applies to the activation order of the constructors.

- the base class constructors are executed first, top-down and from left to right on each level.
- finally, the constructor belonging to the current class, which is at the bottom of the inheritance graph, is executed.

### base initializers

the constructor for the class **at the bottom end of the inheritance graph** uses base initializers to pass the values to the direct and indirect base classes. if the base initializer definition is missing in a constructor definition, the default constructor of the base class is automatically executed.

initial values are thus passed to the base class constructors **"bottom up"**.

## initializing virtual base classes

(617)

```c++

class SUV: public PassCar, public Van
{
    private:
        // ...
    public:
        SUV( ... ): Car( ... )
        {
            // ...
        }
        void display() const
        {
            PassCar::display();
            Van::display();
            // ...
        }
};

```

### constructor calls in virtual base classes

when an obj is created for a multiple-derived class, the constructors of the base classes are called first. however, if there is one virtual base class in the class hierarchy, **the virtual base class constructor** is executed `before` a constructor of a non-virtual base class is called.

the constructor of the virtual base class nearest the top of the inheritance graph is executed first. **this does NOT necessarily mean the top level of the class hierarchy, since a virtual base class can be derived from a non-virtual base class**.

### base initializer

u may be wondering what args are used to call the constructor of a virtual base class. a base initializer of the direct-derived class or any other derivation could be reponsible. the following applies:

for the purpose of initialization, it does NOT matter whether a class derived directly from `Car` contains a base initializer or not.