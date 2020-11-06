# control flow

- loops, `while`, `do-while` and `for`
- branches, `if-else`, `switch-case`
- jumps with `goto`, `continue` and `break`


## building blocks

### while loop pattern

```c++

while(expression)
{
    statement   // loop body
}
```

### for loop pattern

```c++

for(expression1; expression2; expression3)
{
    statement   // loop body
}

```

any of the three expressions in a `for` statement can be omitted, however, u must type at least two semicolons.

the shortest loop header is therefore:

```c++
for(;;)
{
    statement
}
```

infinite for loop,

```c++
for(; expression; )
{
    statement
}
```

## the comma operator

u can use the comma operator to include several expressions where a single expression is syntactically correct.

for example, several variables can be initialized in the loop header of a for statement.

```c++
// syntax
expression1, expression2 [, expression3 ...]

```

the expressions separated by commas are evaluated from left to right.

example as follows

```c++
int x, i, limit;
for(i=0, limit=8; i < limit; i +=2)
{
    x = i * i, cout << setw(10) << x;
}
```

<font color="blue">the comma operator has the lowest precedence of all operators -- even lower than the assignment operators</font>. this means u can leave out the parentheses in the above example.

### do-while statement

```c++

do
{
    statement
} while(expression);

```

### why it works? `if(cin >> x)`

```c++

int x;
if(cin >> x){};

/*
explanation:

cin is an object of istream class.
x is disclaimed as int type.

cin returns the reference of input word(delimiter is \0, aka null), ignores whitespace characters.

cin reads any word(delimiter is \0), then it converts the word to the type of the variable to store.

if converts successfully, conversion stat is true.
if failed, conversion stat is false.

conclusion:
(cin >> x)
has ability to read keyboard input by word (delimiter \0);
has ability to proceed with conversion to the type of x;
has ability to return conversion stat.
*/
```

## conditional operator

```c++

//syntax
expression? expression1 : expression2
```

## switch-case

switch-case syntax

```c++

switch(expression)
{
    case const1: [ statement ]
                 [ break; ]
    case const2: [ statement ]
                 [ break; ]
    .
    .
    .
    [ default: statement ]
}

```

example

```c++

int command = menu(); // the function menu() reads a command

switch(command)
{
    case 'a':
    case 'A':
                action1();
                break;
    case 'b':
    case 'B':
                action2();
                break;
    default:
                cout << '\a' << flush; // beep on invalid input
}

```

## break

same mechnism as break statement in Python

## continue

same mechnism as continue statement in Python

## goto

same mechnism as goto statement in VB

