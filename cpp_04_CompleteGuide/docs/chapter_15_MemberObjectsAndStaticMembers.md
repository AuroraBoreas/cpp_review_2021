# member objects and static members

the major topics discussed in this chapter are

- member objects and how they are initialized
- data members that are created once only for all the objects in a class

also, this chapter describes constant members and enumerated types.

## member objects

### "has-A" relationship

(320)

if a class contains a data member whose type is of a different class, the relationship between the classes is referred to as a `"Has-A" relationship`.

for ease of reading, the constructors were defined separately, rather than as `inline`.

### calling constructors

the `order of the constructor calls` is significant when an object containing members objects is initialized and multiple constructor calls are to be executed.

first, the member objects are created and initialized; this then allows the constructor to create the whole object.

## initializing member objects

(322)

calling default constructors to create member objects reaises several issues:

- a member object is initialized first with default value. correct values are assigned later. this addtional action can impact your program's performance.
- constant objects or references can NOT be declared as member objects since it is impossible to assign values to them later.
- classes that do NOT have a default constructor definition can NOT be used as types for member ojects.

when defining a constructor, u can use `member initializers` to ensure general and efficient use of member objects.

[expriments]

as the book does not show any real example to prove the conclusion above.

I tried to build two simple classes to demonstrate if possible, but unfortunately it didn't work as expected.

btw, i found out how to convert any type to string thou..

```c++

#include <sstream>
#include <string>

std::string& convert_int_to_string(int a, int b, int c)
{
    std::stringstream tmp_iostream;
    tmp_iostream << a << ":" << b << ":" << c;
    static std::string str;
    tmp_iostream >> str;
    return str;
}

```

## NEW implementation syntax for member initializers

a member initializer contains the name of the data member, followed by the initial values in the parentheses.

example:

```c++

time(hr, min, sec); // member initializer

```

multiple member initializers are sperated by commas. a list of member initializers defined in this way follows the constructor header and is separated from the header by a colon.

example:

```c++

Result::Result( /* Parameters */ )
: val(w), time(hr, min, sec);
{ /* Function block */ }

```

this ensure that a suitable constructor will be called for data members with `member initializers` and **avoids calls to the default constructor with subsequent assignments**. u can also use member initializers for data members belonging to fundamental types.

the argument names of the member initializers are normally constructor parameters. this helps pass the values used to create an object to the right member object.

NOTE:

member initializers can ONLY be stated in a `constructor definition`. the `constructor declaration` remains unchanged.

## constant member objects

if a class conatains data members that need to keep their intial values, u can define these members as `const`. For example, you could set the time for a measurement once and not change this time subsequently.

since the `const` member object cannot be modified by a later assignment, the correct constructor must be called to initialize the object. in other words, when u define a constructor for a class, u MUST aslo define a member initializer for each const member object.

## static data members

(325)

### class-specific data

every object has its own characteristics. this means that the data members of two different objects will be stored at different memory addresses.

(review)

#### aesmr

- auto
- extern
- static
- mutable
- register

#### solid

- single responsibility principle
- open close principle
- lovski substitution principle
- interface segretation principle
- dependency inversion principle

#### acid

- atomic
- consistency
- isolation
- durability

#### PSR

- pattern
- search
- result

#### AAA

- arrange
- act
- assert

#### AAOF

- against regression
- against refactoring
- one-button
- fast result

->white-box vs black-box

(326)

however, sometimes it is useful to keep some common data that can be accessed by all the objects belongs to a class, for example:

- **figures** such as exchange rates, interest rates or time limits which have the same value for every object
- **status information**, such at the number of objects, current minimum or maximum threhold values, or pointers to some objects; for example, a pointer to an active window in a window class.

this kind of data needs to be stored **once only**, no matter how objects exist. since a programmer will also need to manage the data from within the class, it should be represented within the class rather than globally. **static data members** can be used for this purpose. in contrast to normal data members, static data members occur only once in memory.

Table: const, static of data members in a class

| items          | normal     | const                     | static                       |
|----------------|------------|---------------------------|------------------------------|
| declaration    | n/a        | `const` prefix            | `static` prefix              |
| initializer    | any        | once. cannot change later | once only.                   |
| why?           | n/a        | think about `const var`   | think about `static` keyword |

### declaration and initialization

static data members occupy memory space even if no objects of the class in question have been craeted. just like member functions, which occur only once, static data members MUST be defined and initialized in an external source file. the `range operator ::` is then used to relate the data members to the class.

example:

```c++

double Result::min = 0.0; // definition

```

as the example illustrates, the `static` keyword is NOT used during definition. Static data members and member functions belonging to the same class are normally defined in one source file.

[some pattern]

`declaration -> definition/implementation -> initialization`

## accessing `static` data members

(327)

### static data members and encapsulation

the normal rules for data encapsulation also apply to `static` data members. a `static` data member declared as `public` is therefore directly accessible to any object.

example:

```c++

class Result
{
    private:
        // data members
    public:
        static double min;
        static double max;
        static void setMinMax(double w);
}

```

if the `static` data members *min* and *max* in the *Result* class are declared `public` rather `private`, and given that *temperature* is an object belonging to the class, the following statement

example: `cout << temperature.max;` using dot operator

example: `cout << Result::max;`  using range operator

this syntax is preferable to the previous exmaple, since it clearly shows that a static data member exists independently of any objects.

### static member fucntions

(328)


