# functions and classes

functions

```C++

return_type function_name(arg_type arg1, arg_type arg2, ...)
{
    // body;
}

void function_name(void)
{
    // do sth;
}

```

## using header files

P68

pay attention to the following points when using header files:

- header file should generally be included at the start of a program before any other declarations
- u can only name one header per **#include** directive
- the file name must be enclosed in angled brackets**<...>** or double quotes **" ... "**


## searching for header files

by default, header files comes with compiler will tend to be stored in a folder of their own
-- normally called **include**

by convention, using the angled brackets **<...>** to import.

by convention, import your own header files in the current project folder, using

```C++

#include "project.h"
```

the compiler will then search the current folder.



## standard header files

table: std <font color="blue">C++</font> header files

|             |             |               |           |
|-------------|-------------|---------------|-----------|
| algorithm   | ios         | map           | stack     |
| bitset      | iosfwd      | memory        | stdexcept |
| complex     | iostream    | new           | streambuf |
| dequeue     | istream     | numeric       | string    |
| exception   | iterator    | ostream       | typeinfo  |
| fstream     | limits      | queue         | utility   |
| functional  | list        | set           | valarray  |
| iomanip     | ioscale     | sstream       | vector    |

table: std <font color="blue">C</font> header files

|             |             |               |           |
|-------------|-------------|---------------|-----------|
| assert.h    | limits.h    | stdarg.h      | time.h    |
| ctype.h     | locale.h    | stddef.h      | wchar.h   |
| errno.h     | math.h      | stdio.h       | wctype.h  |
| float.h     | setjmp.h    | stdlib.h      |           |
| iso646.h    | signal.h    | string.h      |           |