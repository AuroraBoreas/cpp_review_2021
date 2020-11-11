# type conversion in class hierarchies

(550)

topics:

- type conversion within class hierarchies
- explicit type casting in class hierarchies, upcasting and downcasting

## converting to base classes

(551)

### implicit conversion

example:

```c++

#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED

#include <string>
#include <iostream>
using namespace std;

class Car
{
    private:
        string producer;
        int    nr;
    public:
        Car(const string& p, int n)
        { produce = p; nr = n; }
        // getter
        const string& getProd(void) const { return producer; }
        int getNr(void)             const { return nr; }
        // setter
        void setProd(const string& p) { producer = p; }
        void setNr(int n)             { nr = n; }
        // repr
        void display(void) const
        {
            cout << "\n------------------------\n"
                 << "\nProducer:    " << producer
                 << "\nNumber  :    " << nr;
        }
};

class PassCar
{
    private:
        string passCarType;
        bool   sunRoof;
    public:
        PassCar(const string& tp, bool b, const string& p="", int n=0L)
        : Car(p, n), passCarType(tp), sunRoof(b) {}
        // getter
        const string& getCarType(void) const { return passCarType; }
        bool  getSunRoof(void)         const { return sunRoof; }
        // setter
        void setCarType(const string& s) { passCarType = s; }
        void setSunRoof(bool b)          { sunRoof = b; }
        // repr
        void display(void) const
        {
            cout << "\n------------------------\n"
                 << "\nProducer:    " << getProd()
                 << "\nNumber  :    " << getNr()
                 << "\nCarType :    " << passCarType
                 << "\nSun Roof:    ";
            if(sunRoof)
                cout << "yes " << endl;
            else
                cout << "no  " << endl;
        }
};

#endif // CAR_H_INCLUDED

```

```c++

#include "car.h"

bool compare(Car&, Car&);

int main()
{
    PassCar beetle("new bettle", false, 3421, "VW"),
            miata("Miata", true, 2512, "Mazda");
    bool res = compare(beetle, miata);
    // ...
    return 0;
}

bool compare(Car& a, Car& b)
{
    // ...
}

```

if a class is derived from another class by `public` inheritance, the derived class assumes the characteristics and features of the base class. objects of the derived class type then become `special` obj of the base class, just like an automobile is a special type of vehicle.

u can utilize that `is` relationship when handing objects. it is possible to assign an obj of a derived class to an obj of the base class. this causes an `implicit type conversino` to a base class type.

the base class thus becomes a generic term for multiple special cases. given that the class `PassCar` and `Truck` were derived from the `Car` class, objects of the `PassCar` or `Truck` type can always be managed like objects of `Car` type.

## type conversions in assignments

(553)

### effect of an assignment

```c++

Car auto;
PassCar bmw("520i", true, 4325, "Bayerische Motorenwerke);

auto = bmw;

```

### assignment to a base class object

an object belonging to a derived class type can be assigned to an object of a base class.

in fact that u can assign an object belonging to a derived calss to a base class object assumes that more will always fill less. the object on the right of the assignment operator will always contain a member object of the type on the left of the operator.

### assignment to derived class objects

this is NOT the case when u attempt to assign to base class object to an object of a derived class. the assignment

example:

```c++
bmw = auto; // Error! less can NOT fill more.

```

an assignment in reverse order is only possible if u have **defined an assignment of this type** or **a copy constructor with a parameter of the type "reference to base class"**. both would be able to supply default valeus for the additional data members of the derived classes.

## converting reference and pointers

(555)

### effect of a pointer assignment

```c++
PassCar cabrio("Spitfire", true, 1001, "Triump");
Car* carPtr = &cabrio;
carPtr = &cabrio; // wtf?

```

### converting to base class pointers

this `is` relationship btwn a derived class and a base class is also apparent when references and pointers are used. a pointer of the type "pointer to base class", or `base class pointer` for short, can reference an object of a derived class type.

the following rule applied for access to the reference object:

`a base class pointer can only access the public interface of the base class`

```c++

PassCar cabrio("Spitfire", true, 1001, "Triump");
Car* carPtr = &cabrio;
carPtr = &cabrio;          // wtf?

carPtr->display();         // OK
carPtr->setSunRoof(false); // Error

PassCar auto;

auto = *carPtr;             // Error

```

### conversions in Reference to base classes

a similar situation arises when u are working with references. a reference of the type "reference to base class" can point to an object of a derived class. the reference will address only the generic part of the object in this case

example:

```c++

Car& carRef = carbrio;
carRef.display();          // OK. output base members
carRef.setSunRoof(true);   // Error
PassCar auto;
auto = carRef;             // Error

```

## explicit type conversions

(556)

### `upcasts` and `downcasts`

type conversinos that walk up a class hierarchy, or `upcasts`, are always possible and safe. `upcasting` is performed implicitly for this reason.

type conversions that **involve walking down the tree**, or `downcasts`, can only be performed explicitly by means of a cast construction. the cast operator(`type`), which was avaiable in C, or the `static_cast< >` operator are available for this task, and equivalent in this case.

### explicit cast constructions

example:

```c++

PassCar cabrio("Spitfire", true, 1001, "Triump");
Car* carPtr = &cabrio;  // base class pointer to the derived obj
((PassCar*) carPtr)->display();

```

the operator `static_cast< >` conforms the following

syntax: `static_cast<type>(expression)`

and converts the expression to the target type type.

example:

```c++

((PassCar*)carPtr)->display();
// or
static_cast<PassCar*>(carPtr)->display();

```

no parentheses are required here as the operators `static_cast<>` and `->` are of equal precedence. they are read from left to right.

after downcasting a pointer or a reference, the entire public interface of the derived class is accessible.

### downcast safety issues

type conversions from top to bottom needs to be performed with greate care. downcasting is only safe when the object referenced by the base class pointer really is a derived class type. this also applies to references to base classes.

to allow safe downcasting C++ introduces the concept of `dynamic casting`. this technique is available for polymorphic classes.

