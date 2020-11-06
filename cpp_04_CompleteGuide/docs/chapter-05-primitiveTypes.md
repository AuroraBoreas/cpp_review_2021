# operators for fundamental types

basic of basic


## binary arithmetic operators

binary opertion pattern

```c++

a + b

// a : left operand
// + : operator
// b : right operand

```

| operator      | significance          |
|---------------|-----------------------|
| +             | addition              |
| -             | subtraction           |
| *             | multiplication        |
| /             | division              |
| %             | remainder             |


## unary arithmetic operators

### table: unary arithmetic operators

| operator      | significance          |
|---------------|-----------------------|
| +   -         | unary sign operators  |
| ++            | increment operator    |
| --            | decrement operator    |

### table: precedence of arithmetic operators

| precedence    | Operator              | grouping          |
|---------------|-----------------------|-------------------|
| High          | ++ -- (postfix)       | Left to Right     |
|　↑            | ++ -- (prefix)        | Right to Left     |
|　¦            | +  - (sign)           | Right to Left     |
|　¦            | *   /   %             | Left to Right     |
|　↓            | + (addition)          | Left to Right     |
|  Low          | - (subtraction)       | Left to Right     |

### sign operator

```c++

int n = -5;
cout << -n;
// 5

```

### increment / decrement operators

given that *i* is a variable, both `i++` (postfix notation) and `++i` (prefix notation) raise the vale of *i* by 1. in both cases the operation i = i + 1 is performed.

however, prefix ++ and postfix ++ are two different operators.

the difference becomes apparent when u look at the value of the expression;

- `++i`, *i* is incremented first and the new value of *i* is then applied
- `i++`, the original value of *i* is applied before *i* is incremented.
