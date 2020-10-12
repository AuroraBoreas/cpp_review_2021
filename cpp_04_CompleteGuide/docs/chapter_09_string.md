# the standard class string

- definition
- various methods of string manipulation: inserting, erasing, searching and replacing, comparing, and concatenating


Objects of class string do not necessarily contain the string terminating character '\0', as is the case with C strings.

## initializing strings

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

## concatenating strings

```c++

string a("hello "), b("there!");

a + b;  // works
a + "world!";   // works

"hallo " + "world!"; // exception


a += b; // works

```

## comparing strings

```c++

string a("hello"),
       b("world!");

a <= b;
a == b;
...

```

## inserting and erasing in strings

syntax: string.insert(postion, string);

```c++

string s1("hello !");
s1.insert(6, "world");

// more

string s2("somebody");
s1.insert(6, s2, 0, 3);

```

syntax: string.erase(position, qty);

```c++

string s("hello world!");
s.erase(4, 6);


// or erase(postion) removes from position to end
string s("winter-story");
s.erase(6);

// or erase() w/o any argument removes entire string
string s("hello world!");
s.erase();

```

## search and replace in strings

replace example

```c++

string s1("There they go again!"),
       s2("Bob and bill");

s1.replace(6, 4, s2);

// or s1.replace(s1_startposition, s1_endposition, s2, s2_startposition, s2_endposition)

string s1("Here comes Mike!"),
       s2("my love?");
s1.replace(11, 4, s2, 0, 7);

```

search example

```c++

string youth("bill is so young, so young");
int first = youth.find("young");
int last  = youth.rfind("young");

string s1("There they go again!"),
       s2("Bob and Bill");
int pos = s1.find("they");
if(pos != string::npos)
{
    s1.replace(pos, 2, s2);
}

```
