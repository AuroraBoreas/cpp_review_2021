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