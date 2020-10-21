# arrays

topics:

- how to define and use arrays
- one-dimemsional and multidimentional arrays
- C strings and
- class arrays

## Defining arrays

(343)

### definition

an `array` contains multiple objects of `identical types` **stored sequentially in memory**.

an `array` is also referred to as a `vector`.

syntax: `type array_name[count];`

example: 

```c++

float arr[10];

```

[understanding]

this statement defines the array *arr* with 10 elements of float type. the object *arr* itself is of a `derived type`, an "array of float elements" or "float array".

an array always occupies a *contiguous* memory space.

### index for array elements

`subscript operator []` is used to access individual array elements. in c++ an index always begins at *zero*.

**no error message is issued if the index exceeds the valid index range**. u can define a class to perform range checking for indices.

### initialization list

arrays can be initialized when u defined them.

locally defined arrays are created on the stack at program runtime. u should therefore be aware of the following issues when defining arrays:

- arrays that occupy a large amount of memory should be defined as `global` or `static`
- unless they are initialized, the elements of a local array will NOT necessarily have a definite value. values are normally assigned by means of a loop.

u can NOT assign a vector to another vector. however, u can overload the assignment operator within a class designed to represent arrays.

## C strings

(347)

### initializing

syntax: `char array_name[count] = "hello world!";`

### `char` arrays

arrays whose elements are of `char` type are often used as data communicatino buffers.

example:

```c++

char buffer[10*512]; // 5 Kbyte buffer

```

when u define an array, u can use a string constant to initialize the array.

example:

```c++

char name[] = "Hugo";
// is equivalent to
char name[] = { 'H', 'u', 'g', 'o', '\0' };

```

in the C language, strings are usually represented as `char` vectors with a `terminating null character '\0'`. in c++, strings of this type are referred to as C strings to distinguish then from objects of the string class.

### c string and the string class

cstrings are simple `char` arrays. which means the functionality of the `string` class is NOT available for them. thus, for example, **assignments and comparisons are NOT defined**.

example:

```c++

char str1[20], str2[20] = "A string";
str1 = str2; // exception
strcpy(str1, str2); // OK!

```

example:

```c++

char name[20];
cin >> setw(20) >> name;

```

[explanation]

I/O streams are overloaded for `char` arrays.

input and output are as easily achieved as with `string` class objects. however, the program MUST make sure not to overrun the end of the `char` array when reading data into the array. u can use the `width()` method or the `setw()` manipulator for this purpose.

```c++

#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

char header[] = "\n    *** C string ***   \n\n";

int main()
{
    char hello[] = "hello ", name[20], message[80];
    cout << header;
    cin >> setw(20) >> name; // 19 characters, setw(20) statement is a MUST, or user input may overflow > 20;
    strcpy(hello, name); // append name to hello
    cout << "what your message today?" << endl;
    cin.getline(message, 80); // max characters are 79 because it's cstring.
    if(strlen(message) > 0)
    {
        for(int i=0; message[i] != '\0'; ++i)
            cout << message[i] << ' ';
        cout << endl;
    }

    return 0;
}

```

[NOTE]

C strings are preferable to the `string` class if only a few operations are needed and u want to avoid unnecessary overheads.

## class arrays

(349)

array elements can also be objects of a class type. the array is know as a `class array` in this case. when u declare an array of this type, u only need to state the type of the array elements.

example:

```c++

Result temperatureTab[24];

```

**as the statement doest NOT initialize the array explicitly, the default constructor is automatically called for each array element.**

[NOTE]
`class arrays` can only be defined w/o explicit initialization **if a default constructor exists for the class**.

## explicit initialization

a `class array` is initialized as usual by an `initialization list`. the list contains a constructor call for each array element.

example:

```c++

Result temperatureTab[24] =
{
    Result(-2.5, 0, 30, 30),
    Result(3.5),
    4.5,
    Result(temp1),
    temp2
};


```

