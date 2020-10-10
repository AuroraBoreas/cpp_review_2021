# the standard class string

- definition
- various methods of string manipulation: inserting, erasing, searching and replacing, comparing, and concatenating


Objects of class string do not necessarily contain the string terminating character '\0', as is the case with C strings.

## initialization

sample:

```c++

#include <iostream>
#include <string>

using namespace std;

string s("hello world"),
       line(50, '*');


/*
link: https://stackoverflow.com/questions/27063811/c11-string50-x-versus-string50-x

When you do string { 50, 'x' } you're essentially initializing the string with a list of characters.

On the other hand, string(50, 'x') calls a 2 argument constructor, which is defined to repeat the character x 50 times. 

The reason why string { 50, 'x' } doesn't pick the constructor is that it could be ambiguous. What if you had a three parameter constructor as well? If the type has an initializer_list constructor, it will be picked when you use { ... } for initialization.
*/
```