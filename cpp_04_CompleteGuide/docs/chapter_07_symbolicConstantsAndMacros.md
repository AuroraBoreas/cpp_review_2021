# symbolic constants and macros

- symbolic constants
- macros

## macros

C++ has a simple mechanism for naming constants or sequences of commands, that is for defining macros.

u simply use the preprocessor's #define directive.

```c++

// macro syntax
#define name substitutetext

// note that neither an equals sign nor a semicolon is used,
// as these would become part of the substitute text.

```

merit of macros

1. good readability
2. easy to modify

demerit of macros

- the substitute text is inserted and re-compiled each time the macro is called. 
- for this reason, a macro may inflate the object file each time the macro is called.
- thus, a macro should contain only a few statements to avoid inflation

it is possible to call macros with arguments.
to do so, u must supply the appropriate parameters when defining the macro. the parameters are replaced by valid arguments at runtime.

example

```c++

#define SQUARE(a)   ((a)*(a))
z = SQUARE(x+1);

/*
why ((a)*(a)) but not (a * a)?

this example also shows that u must be careful when using brackets to indicate parameters for macros.

omitting the brackets in the previous example, SQUARE, would cause the expression to be expanded as follows.

- parameters with brackets, z = (x+1) * (x+1)
- omitting brackets of parameters, z = x + 1 * x + 1

outer brackets in the definition ensure that even when the macro is used in a complex expression, the square is calculated before the result can be used for any further calculations.

*/
```

| item          | mechanism                                                                            |
|---------------|--------------------------------------------------------------------------------------|
| macro         | visible to compiler; inflatable in runtime; no check arg types                       |
| function      | compiled independently to executable; caller prg branches to function; check arg type|
| inline func   | lambda                                                                               |



