# manipulating bits

(726)

topics

- bitwise operators
- how to use bit masks
- introduce the definition of bit-fields

## bitwise operators

(727)

skip

## bitwise shift operators

(729)

skip

### applications

shift operators allow u to perform efficient multiplication and division with 2^n. 

**shifting a number n places left(or right), is equivalent to a multiplication (or division) by 2^n**.

example:

```c++

unsigned res, number = 5;
res = number << 3;          // 5 * (2^3) = 40
res = number >> 1;          // 5 / (2^1) = 2
```

## bit masks

(731)

bit positions

example:

```c++

#define MASK 0x20

char c = 'A';
c = c | MASK;

```

### deleting bits

the bitwise AND operator is normally used to delete specific bits. a so-called mask is used to determine which bits to delete.

exmaple: `c = c & 0x7F;`

in the mask `0x7F` the seven **LSB**(least significant bits) are set to 1, and all **MSB**(sinanificant bits)

### setting and inverting bits

skip

Table: delete, set and invert bits

| statement             |   significance                                  |
|-----------------------|-------------------------------------------------|
| `x & MASK`            | delete all bits that have a valye of 0 in MASK  |
| `x | MASK`            | set all bits that have a value of 1 in MASK     |
| `x ^ MASK`            | invert all bits that have a value of 0 in MASK  |
| `(x ^ MASK) ^ MASK`   | double inversion, retore the value of x         |

the order bits are left unchanged.

example:

```c++

char c = 'A';

c = c & '0x7F';

c = 'B';
c = c | '0x20';

c = 'C';
c = c ^ '0xAA';

```

## using bit masks

(733)

computing the parity of an integer

```c++

unsigned int bit0(unsigned int x)
{ return (x & 1); }

int parity(unsigned int n)
{
    unsigned int par = 0;
    for(; n != 0; n>>=1)
        par ^= bit0(n);
    return (par);
}

```

## bit-fields

(735)

header of ATM Cells

representing an ATM Cell

c++ lets u divide a computer word into `bit-fields` and give the `bit-fields` a name. **bit-fields offer major advantages: theri uncluttered structure makes them preferable and less error prone than using masks and bitwise operators to manipulate individual bits.**

## defining bit-fields

bit-fields are defined as data members of a class.

example:

```c++

struct
{
    unsigned bit0_4 : 5;
    unsigned        : 10;
    unsigned bit15  : 1;
} word;

```

significance:

- u can NOT reference nameless bit-fields. they are used to align the subsequent bit-fields at specific bit positons.
- the width of a bit-field can NOT be greater than that of the `computer word`.
- the width 0 has a special significance;
- the subsequent bit-field is positioned on the next word boundary, that is, it begins with the next computer word.

rules:

1. u can NOT use the address operator for bit-fields. u can NOT create arrays of bit-fields. neither restriction applies to a class containing bit-field members, however.
2. the order bitfields are positioned in depends on the machine being used.
