# fundamental types, constants, variables

## integer types

Table: integer types

| Type                      | Size          | Range of values(decimal)   |
|---------------------------|---------------|----------------------------|
| char                      | 1 byte        | -128 to +127 or 0 to 255   |
| unsigned char             | 1 byte        |                 0 to 255   |
| signed char               | 1 byte        | -128 to +127               |
| int                       | 2 byte resp.  | -32768 to +32767 resp.     |
|                           | 4 byte        | -2147483648 to +2147483647 |
| unsigned int              | 2 byte resp.  | 0 to 65535 resp.           |
|                           | 4 byte        | 0 to 4294967295            |
| short                     | 2 byte        | -32768 to +32767           |
| unsigned short            | 2 byte        | 0 to 65535                 |
| long                      | 4 byte        | -2147483648 to +2147483647 |
| unsigned long             | 4 byte        | 0 to 4294967295            |


NOTE: char <= short <= int <= long

## floatint-point types

Table: floating-points

| Type                      | Size          | Range of values(decimal)   |
|---------------------------|---------------|----------------------------|
| float                     | 4 byte        | -3.4E+38                   |
| double                    | 8 byte        | -1.7E+308                  |
| long double               | 10 byte       | –1.1E+4932                 |


## base

| base  | constant      | rules                                           |
|-------|---------------|-------------------------------------------------|
| 10    |  decimal      | first digital is 1~9                            |
| 8     |  oct          | first digital is 0, second digital is 1~7       |
| 16    |  hexadecimal  | first two digitals are 0x or 0X, third is 0~F   |


## literals(字面量)

what is literal?

字面量即“一眼看上去是什么就是什么”。大多数IDE(包括C/C++)默认十进制，默认将x进制->十进制。

为什么?
IDE必须有统一的stdout标准

why do you call it constant?

`int a = 10`

对于变量a而言，10是常量(constant)


## keywords in C++

Table: C++ keywords
|            |              |                  |             |          |
|------------|--------------|------------------|-------------|----------|
| asm        | do           | inline           | short       | typeid   |
| auto       | double       | int              | signed      | typename |
| bool       | dynamic_cast | long             | sized       | union    |
| break      | else         | mutable          | static      | unsigned |
| case       | enum         | namespace        | static_cast | using    |
| catch      | explicit     | new              | struct      | virtual  |
| char       | extern       | operator         | switch      | void     |
| class      | false        | private          | template    | volatile |
| const      | float        | protected        | this        | wchar_t  |
| const_cast | for          | public           | throw       | while    |
| continue   | friend       | register         | true        |          |
| default    | goto         | reinterpret_cast | try         |          |
| delete     | if           | return           | typedel     |          |


## how to declare and initialie variable in C++

two approaches as follows.

```C++

type_name variable_name = value;

// or 

type_name variable_name(value);

```