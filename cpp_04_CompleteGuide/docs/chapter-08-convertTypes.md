# converting arithmetic types

C++ allows you to mix arithmetic types in a single expression — in other words, the operands of an operator can belong to different types

- implicit type conversions
- explicit type conversions

## implicit type conversions

integer promotions

```c++

bool                             -> int;
char, signed char, unsigned char -> int;
short                            -> int;



unsigned short -> int; // if int equals long
unsigned short -> unsigned int; // if int equals short

```

type hierarchy

```

long double
|
double
|
float
|
unsigned long
|
long
|
unsigned int
|
int

```

samples

```c++

short size(512); double res, x=1.5;
res = size / 10 * x; // short -> int - > double. NOTE: (size / 10) is int
```

The compiler automatically performs implicit type conversion, where a common type, which allows the operation in question to be performed, is assigned for the values of both operands.

You can generally assume that the “smaller” type will be converted to the “larger” type.

The assignment operator is an exception to this rule and will be discussed separately.

### integer promotion

Integer promotion is first performed for any expression:

- `bool`, `char`, `signed char`, `unsigned char`, and `short` are converted to `int`
- `unsigned short` is also converted to `int` if the `int` type is greater than `short`, and to `unsigned int` in all other cases.

This type conversion is performed so as to preserve the original values. 

The boolean value false is converted to 0 and true is converted to 1.

Thus, C++ will always use `int` type values or greater when performing calculations.

example

```c++

char c('c');
c < 'a';

```

### usual arithmetic type conversions

Usual arithmetic type conversions are performed for all binary operators and the conditional operator ?: provided the operands belong to an arithmetic type, 

the only exceptions being the assignment operator and the logical operators `&&` and `||`.

Two different cases can occur during type conversion in assignments:

1. If the type of the variable is larger than the type of the value to be assigned, the type of the value must be promoted. The rules for usual arithmetic type conversions are applied in this case (see Example 1).
2. If the type of the value to be assigned is larger, this type must be “demoted.” The following procedures are followed depending on individual circumstances

## explicit type conversion

syntax: `(type) expression`

example:

```c++
int a(1), b = 4;
double res;
res = (double)a / b;

// or

res = dynamic_cast<double>a / b;

```
