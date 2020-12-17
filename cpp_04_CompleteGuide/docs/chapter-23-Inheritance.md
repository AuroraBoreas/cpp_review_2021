# inheritance

topics:

- how to define derived classes
- how members are redefined
- how obj are constructed and destroyed, and
- how access control to base classes can be realized

## concept of inheritance

(520)

OOP concepts. pass

- *has* relationship
- *is* relationship

## derived classes

(521)

example:

```c++

class C: public B // `public` keyword here means: all the `public` members in the base class B are publicly available in the derived class C.
{
    private:
        // ...
    public:
        // ...
}

```

restriction keywords:

- public
- private: the methods of the derived class can NOT access the `private` memebers of the base class. why? imanage the consequences if this were NOT so: u would be able to hack access to the base class by simply defining a derived class, thus undermining any protection offered by data encapsulation
- protect

the arrow **↑** means directly derived from.

## members of derived classes

(526)

### name loopup

the following rules apply when searching for the name of a method:

- the compiler looks for the name of the method called in the derived class first
- if the name can NOT be found, the compiler **walks one step up the tree** and looks for a `public` method with that name

hmm, MRO thing here. see <a href="src_code\chapter-23-Inheritance\demo_mro.py">MRO in Python</a>

## obj of derived classes

(533)

## calling methods in the base class

u may be wondering if a base class method can be called for an obj of a derived class, if the method has been redefined in the derived class. this is possible using the scope resolution operator `::`.

example:

```c++

PassCar cabrio("Carrera", true);
cabrio.setNr(1000);
cabrio.setProd("Porsche");
cabrio.disply();
cabrio.Car::display(); // calling base method

```

## protected members

(535)

### access to sheltered members

the private members of a base class are equally inaccessible for the methods and `friend` functions of a **derived class**.

### `protected` members

to allow methods and `friend` functions access to the sheltered members of a base class, an additional level of access control btwn `private` and `public` is introduced. this is achieved by means of `protected declaration`.

a member declared `protected` is sheltered from external access just like a `private` member. that means, a `protected` member is inaccessible for base class objects and any classes derived from the base class. however, in constrast to a `private` member, **methods and `friend` functions of derived classes** can access the member.

Table: member-access-control

| type of access    | meaning                                                                                                                                                                               |
|-------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| `private`         | class memebers declared as `private` can be used only by `member functions` and `friend`(cls or func) of the class.                                                                   |
| `protected`       | class members declared as `protected` can be used by `member functions` and `friend`(cls or function) of the class. additionally, they can be used by classes `derived` from the class. |
| `public`          | class members declared as `public` can be used by any function.                                                                                                                       |

[explanation]

think of a class as a girl. 
she marrid a man. she became a cunt.

- when she is single. `private` means she touches her boobs and virgin by herself. interaction from others are viewed as illegal
- she delivered a son. `protected` means her son touch it.
- easy girl. `public` means anyone can fuck her.
