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

### insert methods

the following methods are defined in the container classes `vector`, `deque` and `list`.

- push_back()    insert at end
- insert()       insert after a given position

additionally, the following method is available in the `list` and `deque` classes

- push_front()   insert at beginning

this method is not defined in the `vector` class.

the `insert()` method is overloaded in various versions, allowing u to insert a single obj, multiple copies of an obj, or obj copies from another container. given two containers `v` and `w` the following

example: `w.insert(--w.begin(), v.begin(), v.end());`

### runtime behavior

the **dissimilar runtime behavior** for methods can be ascribed to the implementation of various container classes.

### insertion in adapter classes

there is only one insertion method for adapter classes: `push()`. in stacks and queues, `push()` appends an obj with a constant runtime. insertion of obj into `priority queue` depends on the priority of the obj and runtime is linear.

## accessing obj

(781)

method `search()` of container class `sortVec`

```c++
// sortVec.h

template<class T, class Compare>
class SortVec<T, Compare>::search(const T& obj)
{
    int first = 0; last = end() - begin() - 1, mid;
    while(first < last)
    {
        mid = (first + last + 1) / 2; 
        if(obj < (*this)[mid]>) // search the left half
        {
            last = mid - 1;
        }
        else
            first = mid; // search the right half
    }

    if(obj == (*this)[first])
        return first;
    else
        return size();
}

```

### the `front()` and `back()` methods

access to individual obj in the container classes `vector`, `deque` and `list` can be performed by the following methods

- `front()`     for access to the first element and
- `back()`      for access to the last element


both methods return a reference to the obj in question.

example:

```c+

double z = v.front();
v.front() = 1.9;

```

this saves the first obj in container `v` in teh variable `z` and then overwrites the obj by 1.9.

### access via indices

the subscript operator[] is overloaded in the vector and deque classes to permit the use of indices for access to the obj in a container. an index is a positive integer of the type `size_type`.

example: `v[20] = 11.2;` 

when u use the subscript operator, u MUST ensure that the index does NOT exceed the valid range. u can use the access method `at()` to throw an exception if an index is out of range.

example: `v.at(20) = 11.2;`

the `at()` method throws an exception of the standard error class `out_of_range` of an error occurs.

## length and capacity

(783)

method `merge()` of container class `SortVec`

```c++

// sortVec.h
// merge method definition

template<class T, class Compare>
class SortVec<T, Compare>::merge(const SortVec<T, Compare>& v)
{
    SortVec temp;
    SortVec::iterator pos = begin();
    int n1 = 0, n2 = 0;
    // copy the smallest obj into vector temp:
    while(n1< size() && n2 < v.size())
    {
        if(pos[n1] <= v[n2])
            temp.push_back(pos[n1++]);
        else
            temp.push_back(v[n2++]);
    }

    while(n1 < size())
    {
        temp.push_back(pos[n1++]);
    }

    while(n2 < size())
    {
        temp.push_back(v[n2++]);
    }

    *this = temp;
}

```

## deleting in sequences

(785)

a priority queue

```c++
// prior_t.cpp

#include <queue>
#include <string>
#include <iostream>

using namespace std;

class Parcel
{
    private:
        unsigned int prio;
        string info;
    public:
        Parcel(unsigned int p, const string& s)
        : prio(p), info(s) {}
        friend bool operator<(const Parcel& x, const Parcel& y)
        { return (x.prio < y.prio); }
        friend ostream& operator<<(ostream& os, const Parcel& x)
        {
            os << x.prio << " " << x.info << endl; return os;
        }
};

int main()
{
    priority_queue<Parcel> pq;
    pq.push(Parcel(7, "Bob")); // insert
    pq.push(Parcel(1, "Peter"));
    pq.push(Parcel(4, "Susan"));

    while(!pq.empty())
    {
        cout << pq.top() << endl;
        pq.pop();
    }

    return 0;
}

```

### deletion methods

the following methods are available for deleting obj in the container classes `vector`, `deque` and `list`:

- pop_back()    deletes the last obj in the container
- erase()       deletes the obj at a given pos, or deletes all obj in a given range
- clear()       deletes all obj in a container

the following method is additionally defined in the `deque` and `list` classes.

- pop_front()   deletes the first obj in the container
  
this method does NOT have a return value, just like the `pop_back()` method.

## list operations

(787)

sample program

```c++

// list_t.cpp

#include <list>
#include <cstdlib>
#include <iostream>
using namespace std;

typedef list<int> INTLIST;

int display(const INTLIST& c);

int main()
{
    INTLIST ls, sls;
    int i;
    for(i=1; i<=3; ++i)
    {
        ls.push_back(rand()%10);
    }

    ls.push_back(ls.front());

    ls.reverse();
    
    ls.sort();

    for(i=1; i<=3; ++i)
    {
        sls.push_back(rand()%10);
    }

    INTLIST::iterator pos = ls.end();

    ls.splice(--pos, sls, sls.begin());

    display(sls);

    ls.sort();
    sls.sort();
    ls.merge(sls);
    ls.unique();

    display(ls);


    return 0;
}

int display(const INTLIST& c)
{
    list<int>::const_iterator pos;
    for(pos=c.begin(); pos != c.end(); ++pos)
    {
        cout << *pos << endl;
    }
    return 0;
}

```

### splice operations

`splice operation` insert the obj from one list container at a given position in another list container and remove them from the original container. u can **transfer** either a whole container or just part of a container.

## associative containers

(789)

sequences store obj in linear order. searching for a given obj will thus require a linear runtime. if u have only a few obj to deal with, this will NOT cause any  significant delay. however, it is a major disadvantage in large collections of obj.

### represeting sets and maps

associative containers with different classes that represent sets and maps allow u to optimize runtime. they manage obj in so-called `heap`, that is in trees with a minimum height.

## sets and multisets

(791)

sample sets and multisets

```c++

// set_t.cpp

#include <set>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

typedef set<int> IntSet;
typedef IntSet::iterator SetIter;

typedef multiset<int> IntMultiSet;
typedef IntMultiSet::iterator MultiSetIter;

int main()
{
    IntSet lotto;
    SetIter pos;

    srand((unsigned)time(NULL));
    while(lotto.size() < 5)
        lotto.insert(rand()%50);
    
    cout << "these are your lotto numbers: " << endl;
    for(pos=lotto.begin(); pos != lotto.end(); ++pos)
        cout << *pos << "   ";
    cout << "\n\n";

    IntMultiSet ms;
    MultiSetIter mpos;
    for(int i=0; i<10; ++i)
        me.insert(rand()%10);

    cout << "And now 10 random numbers "
         << " between 0 and 10: : << endl;
    
    for(mpos=ms.begin(); mpos != ms.end(); ++mpos)
        cout << *mpos << "  ";
    cout << "\n";

    return 0;
}

```

sets and multisets are used for efficient management of obj: collections with sortable keys, that is, insertion, deletion, and search operations can be performed with logarithmic runtimes. keys are always parts of obj, thus, keys are data members whose relationships to one another MUST be defined in the corresponding class. a lesser than relationship is normally defined for this purpose, that is, the operator`<` will be overloaded for the class.

### declaring sets and multisets

the container classes `set` and `multiset` have two constructors each for creating containers. u can use the default constructor to create sets and multisets with a length of 0. the second constructor inserts obj from a range of iterators into the new set or multiset.

example:

```c++
#include "account.h"
#include <set>

using std::set;

typedef set<Account> AccountSet;
AccountSet mySet(first, last);

```

here, [first, last) is a range of iterators in an existing container whose obj are of `Account` type.

the copy constructor is also defined, and this allows u to use an existing container of the same type to initialize a new container.

### inserting and deleting

the `insert()` method is available for insertion. this allows for insertion of individual obj or multiple obj from a given range of iterators.

example:

```c++

mySet.insert(Account(1234, "May, Tom", 100));


mySet.erase(mySet.begin());

mySet.erase(mySet.begin(), mySet.end());

```

## maps and multimaps

(793)

using `multimaps`

```c++
// mulmap_t.cpp

#include <map>
#include <string>
#include <iostream>

using namespace std;

typedef multimap<int, string> MULTI_MAP;
typedef MULTI_MAP::const_iterator ITERATOR;

inline void display(const MULTI_MAP& m)
{
    ITERATOR pos;
    cout << endl;
    for(pos=m.begin(); pos != m.end(); ++pos)
        cout << pos->first << " " << pos->second << endl;
    cout << endl;
}

int main()
{
    MULTI_MAP mm;
    mm.insert(pair<int, string>(7, "ZL"));
    mm.insert(pair<int, string>(3, "SCY"));
    mm.insert(pair<int, string>(3, "LL"));

    display(mm);

    ITERATOR pos;
    pos = mm.find(3);
    if(pos != mm.end())
        cout << pos->first << " " << pos->second << endl;
    cout << endl;

    int key = 3;
    cout << "there are " << mm.count(key) << " obj with key " << key << endl; 

    return 0;
}

```

### representing pairs of Keys/Objects

maps and multimaps store pairs of sorted keys and objects.

the c++ standard library contains the class template `pair<const Key, T>` with two `public` data members `first` and `second`, a default constructor, and a copy constructor to represent key/obj pairs.

### using maps and multimaps

the container classes `map` and `multimap` contain constructors with the same fucntionality as the `set` and `multiset` classes.

## bitsets

(795)

representing raster images with bitmaps

```c++

// bitmap.h

#include <bitset>
#include <stdexcept>

using namespace std;

template<int N>
class Bitmap: public bitset<N>
{
    private:
        int lines, cols;
        int ax, ay;
        int ai;
    public:
        Bitmap(int l, int c);
        void move(int x, int y);
        void draw(int x, int y);
};

template<int N>
Bitmap<N>::Bitmap(int l, int c)
{
    if(l*c <= N)
    {
        reset();    // set all bits to 0
        lines = l; cols = c;
        ax = 0; ay = 0; ai = 0;
    }
    else throw invalid_argument("Invalid argument \n");
}

template<int N>
Bitmap<N>::draw(int x, int y)
{
    if(x>=0 && x < lines && y>=0 && y < cols)
    {
        int savex = x, savey = y;
        
        if(ax > x)
        {
            int temp = ax; ax = x; x = temp;
            temp = ay; ay = y; y = temp;
        }

        int dx = x - ax, dy = y - ay;
        int xinc = 1, yinc;

        if(dy<0)
        { yinc = -1; dy = -dy; }
        else yinc = 1;

        int count = dx + dy;
        int d = (dx - dy) / 2;

        while(count-- > 0)
        {
            ai = ax * cols + ay;
            set(ai);
            if(d<0)
            { ay += yinc; d += dx; }
            else
            { ax += xinc; d -= dy; }
        }

        ax = savex; ay = savey;
        ai = ax * cols + ay;
    }
    else throw invalid_argument("Invalid argument \n");
}

// TBD

```

### declaring bitsets

a `bitset` stores a bit sequence of a given length. this allows storage of mass bit coded data, such as raster images, with minimum memory used.

the container class `bitset<N>` provides the functionality needed to manage bitsets. the template parameter N is the length of bitsets, that is the maximum number of bits stored.

u can use the default constructor to create a bitset with no initial values. however, u can also use a given bit-pattern to initialize a bitset. the bit-pattern is either defined as an `unsigned long` vlaue or as a string.

example:

```c++

string s = "1010101010";
bitset<1024> b(s);

```

the string s can contain only the '0' or '1' characters.

1. **the last character** in the string will be the first bit value(0 or 1) at bit position 0,

2. **the second to the last character** in the string is the bit value at position 1, and so on.

3. the remaining bits are padded with 0 up to a length of N.


## bitsets(continued)

(797)

### manipulating bits

the container class `bitset<N>` provides the following methods.

- `get()` method for reading individual bits
- `set()` method for writing individual bits
- `set()` method w/o any args, *all* the bits in the bitset are set to 1.
- `reset()` method deletes all the bits.
- `flip()` method inverts all bits.
- subscript `[]` operator references bits at specific coordinates, btwn 0 and N-1
- bitwise operators also works
  
### the Bresenham algorithm

skip
