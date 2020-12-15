# Containers

(770)

this chapter describes standard class templates used to represent containers for more efficient management of obj collections. these include

- sequences, such as lists and double-ended-queues
- containers adapters, such as stacks, queues, and priority queues
- associative containers, such as sets and maps and
- bitsets

topics:

- how to manage containers
- look at sample applications

## containers types

(771)

sequence and associative containers

### what is a container?

skip.

Ref to containers in Python

### Sequences

skip

### Associative containers and bitsets

there are so-called `bitsets`, which represent bit sequence of a given length and provide bitwise operators, with which bits can be manipulated.

## sequences

(773)

table: operations for sequences

| class Templates                                   | Time needed to insert or remove an obj    |
|---------------------------------------------------|-------------------------------------------|
| `vector<class T, class Allocator= allocator<T>>`  | at the end: constant.                     |
|                                                   | at the beginning or in the middle: linear |
| `list<class T, class Allocator= allocator<T>>`    | in all position: constant.                |
| `deque<class T, class Allocator= allocator<T>>`   | at the beginning or end: constant         |
|                                                   | in the middle: linear                     |

wait, wtf is `class Allocator`?

an obj of class `allocation` is the default allocator obj specified in the constructors for several container class templates in the C++ standard library.

table: container adapters

| class template                                    | insertion         | deletion              |
|---------------------------------------------------|-------------------|-----------------------|
| `stack<class T, class Container= dequeue<T>>`     | at the end        | at the end            |
| `queue<class T, class Container= dequeue<T>>`     | at the end        | at the beginning      |
| `Priority_queue<class T, class Container= vector<T>, Compare= less<T>`| priority based | at the beginning|

table: sequences and header files

| container                 | header file           |
|---------------------------|-----------------------|
| `vector<T, Allocator>`    | `<vector>`            |
| `list<T, Allocator>`      | `<list>`              |
| `deque<T, Allocator>`     | `<deque>`             |
| `stack<T, Container>`     | `<stack>`             |
| `queue<T, Container>`     | `<queue>`             |
| `priority_queue<T, Container, Compare>` | `queue`  |

### representing sequences

the Containers Library defines so-called `container classes` representing containers. these are class templates parameterized by the type T of the obj to be managed.

three basic class templates are defined for sequences.

- vector<T, Allocator>
- list<T, Allocator>
- deque<T, Allocator>

the second template parameter is used for any storage allocation to be performed. the storage management is represented by so-called `allocator class`, which is parameterized by an obj of type T. it enables dynamic memory allocation for obj of type T. the default value of the template parameter is the "standard allocator" `class allocator<T>` that uses the `new` and `delete` operators to allocate and release memory.

### adapter classes

the basic sequence classes are used to construct so-called "adapater classes". an adapter class expects a sequence as a template arg and stores the sequence in a `protected` data member.

## iterators

(775)

iterating lists

```c++

// main.cpp

#include <list>
#include <iostream>
using namespace std;

typedef list<int> INTLIST;

int display(const INTLIST& c)
{
    int z = 0;
    list<int>::const_iterator pos;
    for(pos = c.begin(); pos != c.end(); pos++, z++)
    {
        cout << *pos << endl;
    }
    cout << endl;

    return z;
}

```

iterating vectors

```c++
// main.cpp

#include <vector>
#include <iostream>
using namespace std;

typedef vector<Account> AccVec;

void display(const AccVec& v)
{
    AccVec::const_iterator pos;
    for(pos=v.begin(); pos<v.end(); pos++)
        pos->display();
    cout << endl;
}

```

### positioning and iterating in containers

each obj in a container occupies that specific position where it was stored. to allow u to work with the obj in a container, the positions of the obj in the container MUST be accessible. there MUST therefore be at least one mechanism that follows:

- read and /or write access to the obj at any given position and
- moving from the position of one obj to the position of the next obj in the container

this situation should be familier from your experience of working with pointers.

iterators were instroduced in C++ to provide a uniform model for positioning and iteration in containers. **an iterator can thus be regards as an abstraction of a pointer**.

### iterator types

two types of iterators are important in this context:

1. **bidiretional iterators**, which can be shifted up by the increment operator ++ and down with the decrement operator --, and use the operator * and -> to provide write or read access to obj
2. **random access iterators**, which are bidirectional iterators that can additionally perform random positioning. the subscript operator[] was overloaded for this purpose, and the operations defined for pointer arithmetic, such as addition/subtraction of integers or comparison of iterators, are defined.

### iterator classes

the types `iterator` and `const_iterator` are defined in all the above classes to represent iterators. an iterator belonging to one of these classes can reference constant or non-constant obj.

the methods `begin()` and `end()` are also defined. the `begin()` method accesses the first position and `end()` accesses the position *after* the last container obj.

containers that belong to adapter classes offer only restricted access to the beginning or end. u can NOT use iterators to walk throu them.

## declaring sequences

(777)

the derived container class `sortVec<T, Compare>`

```c++
// sortVec.h

#include <vector> // for class template verctor<T>
#include <functional> // for comparator class less<T>
using namespace std;

template<class T, class Compare = less<T>>
class SortVec: public Vector<T>
{
    public:
        SortVec(){};
        SortVec(int n, const T& x = T());
        
        void insert(const T& obj);
        int  search(const T& obj);
        void merge(const SortVec<T>& v);
}

```

### constructors of `vector`, `list`, `deque`

the container classes `vector`, `list` and `deque` define three constructors and a copy constructor with which sequences can be created.

### constructors for adapter classes

only a default constructor and the copy constructor are defined for adapter classes.

## inserting in sequences

(779)

inserting methods

| methods                                            | effect                                |
|--------------------------------------------------- |---------------------------------------|
| `void push_back(const T& x);`                      | add x at the end of the seq           |
| `void push_front(const T& x);`                     | add x before the first element of seq |
| `iterator insert(iterator pos, const T& x = T());` | insert x after position pos and ..    |
| `size_type insert(...);`                           | insert n copies of x afte pos and ..  |
| `void insert(...);`                                | insert all elements from ...          |

