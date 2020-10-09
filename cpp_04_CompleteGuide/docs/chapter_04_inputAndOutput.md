# input and output with streams

during the development of C++ a new class-based input/output system was implemented.

this givae rise to the I/O stream classes, which are now available in a library of their own, the so-called iostream library.

ios class

- manages the connection to the physical data stream that writes your program's data to a file or outputs the data on screen
- contains the basic functions needed for formattting data. A number of flags that determine how character input is interpreted have been defined for this purpose.

## hints

```C++

cout << endl;
cin >> var;

cout << showpos << endl;
cout << noshowpos << endl;

// alternative: for exceptional or old compiler
cout.setf(ios::showpos);
cout.unsetf(ios::showpos);


```

## formatted output of integers

table: manipulators formatting integers

| Manipulater       | Effects                    |
|-------------------|----------------------------|
| oct               | octal base                 |
| hex               | hexadecimal base           |
| dec               | decimal base(by default)   |

| Manipulater       | Effects                    |
|-------------------|----------------------------|
| showpos           | + sign for positive values |
| noshowpos         | (by default)               |
| uppercase         | capitalize ltters in hex   |
| nouppercase       | (by default)               |

## formatted output of floating-point numbers

table: manipulators formatting floating-point numbers

| manipulator          | effects                           |
|----------------------|-----------------------------------|
| showpoint            | ie, 1.                            |
| noshowpoint          | (by default)                      |
| fixed                | output in fixed point notation    |
| scientific           | output in scientific notation     |
| setprecision (int n) | set the precision to n            |

table: methods for precision

| manipulator           | effects                           |
|-----------------------|-----------------------------------|
| int precision (int n) | sets the precision to n           |
| int precision() const | returns the used precision        |

## output in fields

table: element functions for output in fields

| method                | effects                             |
|-----------------------|-------------------------------------|
| int width() const;    | return the mininum field width used |
| int width(int n);     | set the minimum field width to n    |
| int fill() const;     | return the fill character used      |
| int fill(int ch);     | sets the fill character to ch       |

table: manipulators for output in fields

| method                | effects                             |
|-----------------------|-------------------------------------|
| setw(int n)           | set the minimum field width to n    |
| setfill(int ch)       | sets the fill character to ch       |
| left                  | left-align output in fields         |
| right                 | right-align output in fields        |
| internal              | left-align output of sign and ..    |


## input

when reading from standard input, *cin* is buffered by lines.

keyboard input is thus NOT read until confirmed by pressing the **<Return>** key.

this allows the user to press the backspace key and correct any input errors,
provided the return key has not been process.

`>>` operator will normally read the next input field, convert the input by reference to the type of the supplied variable, and write the result to the variable. 

```
any white space characters(such as blanks, tabs, and newlines) are ignored by default
```

for example,

```c++

char ch;
cin >> ch;

// press the following keys
// <Return> <tab> <blank> <X> <return>
cout << ch;
// X
```

for example,

```c++

int i;
cin >> i;

// press 123FF<Return> stores the decimal value 123 in the variable i.
// however, the characters that follow, FF and the newline character, remain
// in the input buffer and will be read first during the next read operation.

cout << i;
// 123

```

for example,

```c++

string city;
cin >> city;

// when reading strings, only one word is read 
// since the first whitespace character will begin a new input field
// input: Lao Kai
cout << city;

// Lao

```

## format input

### inputting integers

```c++

int n;

// u can use hex, oct, and dec manipulators to stipulate that any character
// sequence input is to processed as a hexadecimal, octal,  or decimal number.
cin >> oct >> n;
// input: 10
cout << n;
// 8

// enabling input such as f0a or -F7
cin >> hex >> n;

```

### inputting floating-point numbers

```c++

dobule x;
cin >> x;

// input: 123
// the character input is converted to a double value in this case.
cout << x;

```

what if the input does not match the type of variable defined?

for example,

```c++

int i, j;
cin >> i >> j; // exception

// input: 1A5
// digit 1 will be stored in the variable i.
// the next input field begins with A.
// but since a decimal input type is required,
// the input sequence will not be processed beyond the letter A.
// if, as in our example, no type conversion is performed, the variable is NOT written to and an internal error flag is raised.

```

it normally makes sense to read numerical values individually, 

and clear the input buffer and any error flags that may have been set after each entry.


## reading and writing characters

u can use the methods `cin.get()` and `cout.put()` to read or write single characters.

for example

```c++

char ch;
cin.get(ch);

// if the character is <whitespace> <blank> <newline> <tab>,
// it will still be stored in the ch variable.

// to prevent this from happening you can use
cin >> ch;
// to read the first non-whitespace character.


// cin.get() can also be called w/o any arguments.
// in this case, cin.get() returns the character code of type int.
int c = cin.get();

```

for example

```c++

cout.put('A'); // equivalent to cout << 'A';

```

## read a line

| read input operator | functionality                   |
|---------------------|---------------------------------|
| cin.get();          | read any one character          |
| cin >> var;         | read one word                   |
| getline(cin, text); | read a whole line of text       |

for example,

```c++

// u can specify a different delimiting character by passing the character to the getline() function as a third argument.

getline(cin, s, '.')

// NOTE: the delimiter character is read, but NOT stored in the string.
// any characters subsequent to the first period will remain in the input buffer of the stream

```