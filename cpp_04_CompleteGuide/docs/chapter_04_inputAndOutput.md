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

inputting integers

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

inputting floating-point numbers

```c++


```