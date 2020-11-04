# dynamic members

(498)

topics: how to implement classes containing pointers to dynamically allocated memory.

- your own copy constructor definition and
- overloading the assignment operator

## members of varying length

(499)

### `dynamic members`

u can exploit the potential of dynamic memory allocation to leverage existing classes and create data members of variable length. depending on the amount of data an application program really has to handle, memory is allocated as required while the application is running.

in order to do this, the class needs a pointer to the dynamically allocated memory that contains the actual data.

data members of this kind are also known as `dynamic members` of a class.

## classes with a dynamic member

(501)

the next question u need to ask when designing a class to represent arrays is what methods are necessary and useful. u can enhance `FloatArr` class step by step by optimizting existing methods or adding new methods.

### constructors

it should be possible to create an obj of the `FloatArr` class with a given length and store a `float` value in the obj, if needed. a constructor that expects an `int` value as an arg is declared for this purpose.

`FloatArr(int n=256);`

the number 256 is that default arg for the length of the array. this provides for a default constructor(nah, a parameterized constructor with default args..) that create an array with 256 empty array elements.

`FloatArr(int n, int val);`

allows u to define an array where the given value is stored in each array element. in this case, u need to state the length of the array.

example:

`FloatArr arr(100, 0.0F);`

## creating and destroying obj

(503)

the memory for the array elements is NOT contained in a `FloatArr` obj and must be allocated dynamically by the constructor. the obj itself only occupies the memory required for the data member `arrPtr`, `max` and `cnt`. thus, `sizeof(FloatArr)` is a constant value that defaults to 12 bytes for 32 bit computers.

## implementing methods

(505)

### read and write access using the subscript operator

example:

```c++

FloatArr v(5, 0.0F);
v[2] = 2.2F;
for(int i=0; i < v.length(); ++i)
    cout << v[i];

```

the operator allows both read and write access to the array elements and can NOT be used for constant obj for this reason.

however, u will need to support read-only access to constant objects.

the second, read-only version only supports read access to the array elements and is automatically called by the compiler when accessing constant obj.

the implementation of these versions is identical.

## copy constructor

(507)

### stanadard copy constructor

simply copying the data members would serve no useful purpose for objects containing dynamic members. this would merely copy the pointer, meaning that the pointers of several different obj would reference the same place in memory.

this scenario would obviously mean trouble. imagine releasing memory allocated for an obj dynamically. the pointer for the second obj would reference a memory area that no longer existed!

## assignment

(509)

### default assignment