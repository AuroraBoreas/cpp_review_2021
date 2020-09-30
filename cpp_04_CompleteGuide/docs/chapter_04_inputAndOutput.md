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
