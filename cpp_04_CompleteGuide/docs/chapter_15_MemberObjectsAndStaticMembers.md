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
| initializer    | any        | once. cannot change later | once only. can be changable  |
| why?           | n/a        | think about `const var`   | think about `static` keyword |

### declaration and initialization

`static` data members occupy memory space even if no objects of the class in question have been craeted. just like member functions, which occur only once, `static` data members MUST be defined and initialized in an external source file. the `range operator ::` is then used to relate the data members to the class.

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

ofc, u can use class methods to access a `static` data member with a `private` declaration. however, normal methods can be used for class objects only. since `static` data members are independent of any objects, access to them should also be independent of any object. static member functions are sued for this purpose.

for example, u can call a static member function for a class even though no objects exist in that class.

example:

```c++
// result.h

class Result
{
    private:
        static double min;
        static double max;
    public:
        // static setter
        static void setMin(double min);
        static void setMax(double max);
        // static getter
        static double getMin(void); // within class
        static double getMax(void); // within class
}

```

example: 

```c++

#include "result.h"

Result temperature;
temperature.setMax(43.4); // equivalent calls:
Result::setMax(43.4);

```

(328)

**calling a static member function does NOT bind the function to any class object**. the `this` pointer is therefore unavailable, in contrast to normal member functions. this also means that **static member functions can NOT access data members and methods that are NOT static themselves**.

## enumeration

sample program

```c++
// main.cpp

#include <iostream>

using namespace std;

class Lights
{
    public:
        enum State { off, red, green, amber };
    private:
        State state;
    public:
        Lights(State s = off) : state(s) {}
        State getState() const { return state; }
        void setState(State s)
        {
            switch(s)
            {
                case off:   cout << "    OFF    "; break;
                case red:   cout << "    RED    "; break;
                case green: cout << "    GREEN  "; break;
                case amber: cout << "    AMBER  "; break;
                default:    return;
            }
            state = s;
        }
};

int main()
{
    cout << "Some statements with objects "
         << "of type Lights!\n";
    Lights A1, A2(Lights::red);
    Lights::State as;
    as = A2.getState();
    if(as == Lights::red)
    {
        A1.setState(Lights::red);
        A2.setState(Lights::amber);
    }
    cout << endl;

    return 0;
}

```

### definition

an enumeration is a user-definable, **integral** type. an enumeration is defined using the `enum` keyword. a range of values and a name for these values are also defined at the same time.

example: 

```c++

enum Shape {Line, Rectangle, Ellipse};

```

the first constant has a value of 0, and each subsequent constant has a value that is one higher than its predecessor.

however, u can also define the values of the constants explicitly.

example:

```c++

enum Bound { Lower = -100, Upper = 100 };

```

u can leave out the type name, if u only need to define the constants.

example:

```c++

enum { OFF, OUT = 0, ON, IN = 1};

```

this statement defines the constants *OFF* and *OUT*, setting their value to 0, and the constants *ON* and *IN* with a value of 1. the value for *OFF* and *ON* are implicit.

### class-specific constants

enumeration can be used to define integral symbolic constants in a simple way.

Table:`enum` vs `#define`

| items     | `#define`            | `enum`                    |
|-----------|----------------------|---------------------------|
| do what?  | replace text string  | enum constants are part of a declaration and thus have a valid range. this allows u to define constants that are visible within a namespace or class only.|

## copy constructor

the copy constructor creates a copy of an existing object. the paramter is thus a read-only reference to the object that needs to be copied. the copy constructor in *Article* class is thus declared as follows:

declaration of copy constructor:

```c++

Article(const Article&);

```

the default copy constructor simple transfers the data members to the new object.


## exercise

`static` data members can't be initialized via `member initializers`, since it does not make sense according to the definition of `static` data member.

const method works with const args;

static method works with static data members only; 

```c++
// article.h

#include <iostream>
#include <string>

class Article
{
    private:
        long nr;
        std::string name;
        double salesPrice;
        static int countObj; // static data members can not be initialized through member initializers
    public:
        // constructors
        Article(long, const std::string&, double);
        // copy constructor
        Article(const Article&);
        // destructor
        ~Article();
        // getter
        long getNumber(void)       const { return nr; }
        std::string getName(void)  const { return name; } // const means return_value can not be modified. this is thus cannot return reference of name..
        double getSalesPrice(void) const { return salesPrice; }
        static int getCount(void)        { return countObj; }
        // setter
        void setNumber(long n)              { nr = n; }
        void setName(const std::string& s)  { name = (s.size() > 0)? s : "no name"; } // must prefix `const`. why? see constructor arguments.
        void setSalesPrice(double sp)       { salesPrice = (sp > 0.0)? sp : 0.0; }
        // print
        void print(void) const;
};

```

```c++
// article.cpp

#include <iostream>
#include <string>
#include "article.h"

// data members
int Article::countObj = 0;

// constructors
Article::Article(long n, const std::string& s, double sp)
: nr(n), name(s), salesPrice(sp)
{
    //nr = n; name = s; salesPrice = sp;
    ++countObj;
    std::cout << "An article \"" << name
              << "\" is created. \n"
              << "This is the " << countObj << ". article!"
              << std::endl;
}
// copy constructor
Article::Article(const Article& anArticle)
: nr(anArticle.nr), name(anArticle.name), salesPrice(anArticle.salesPrice)
{
    ++countObj;
    std::cout << "A copy of the article \"" << name
              << "\" is generated.\n"
              << "This is the " << countObj << ". article!"
              << std::endl;
}
// destructor
Article::~Article()
{
    std::cout << "The article \"" << name
              << "\" is destroyed.\n"
              << "There are still " << --countObj << " articles!"
              << std::endl;
}

// other method
void Article::print() const
{
    std::cout << "article number: " << nr         << '\n'
              << "article name  : " << name       << '\n'
              << "sales price   : " << salesPrice << std::endl;
}

```