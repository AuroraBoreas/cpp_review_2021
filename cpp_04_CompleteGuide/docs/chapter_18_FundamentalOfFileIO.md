# fundamentals of file input and output

when a program is terminated, the program data stored in main memory is lost. to store data permanently, u need to write that data to a file on an external storage medium.

topics:

- sequential file access using file streams
- file streams provide simple and portable file handling techniques.

## files

(401)

### file operations

external mass storage media, such as hard disks, are normally `block-oriented` -- that is, data is transferred in blocks whose size is a multiple of 512 bytes. efficient and easy file management thus implies putting the data u need to store into temporary storage in main memory, in a so-called `file buffer`.

### file positions

**from the viewpoint of a C++ program, a file is simply a `long byte array`**. the structure of the file, using records for example, is entirely the programer's responsibility, allowing for a maximum degree of flexibility.

**every character in a file occupies a byte position**. the first byte occupies position 0, the second byte position 1, and so on. the `current file position` is the position of the byte that will be read or written next. **each byte that is transferred automatically increases the current file position by 1**.

in the case of `sequential access`, the data is read or written byte by byte in a fixed order.

easy access to given data in a file implies being able to set the `current file position` as required. this technique is known as `random file access`.

## file streams

(403)

## creating file streams

(384)

### the file stream classes in the `iostream` library

- `ifstream class` derives from the `istream` and allows file reading
- `ofstream class` derives from the `ostream` and allows file writing
- `fstream class` derives from the `iostream` stream class. it supports both read and write operations for files.

### functionality

- methods for non-formatted writing and reading of single characters and/or data blocks
- the operator `<<` or `>>` for formatted reading and writing from or to files
- methods and manipulators for formatting character sequences
- methods for state queries

### opening a file

u need to open a file before u can manipulate it. to do so, u can

- state the `file name`, which can also contain a path
- define a so-called `file access mode`
  
**if the path is NOT explicitly stated, the file MUST be in the current directory**. the file access mode specifically defines whether read and/or write access to the file is permitted.

any files open when a program terminates are automatically closed.

### file stream definition

u can open a file when u create a file stream -- u simply state the file name to do so. in this case, default values are used for the file access mode.

example:

```c++

#include fstream
using namespace std;

ifstream myfile("text.fle");

/*
since the path was not stated, the file MUST be in the current directory. when a file is opened, the current file position is the beginning of the file.
*/

ofstream yourfile("new.fle");

/*
this statement creates a new file called `new.fle` and
opens the file for writing. BUT be careful! fi the file already exists, it will be truncated to a length of zero bytes, or in other words deleted.

u can create a file stream which does NOT reference a specific file and use the open() method to open a file later.
*/

ofstream yourfile;
yourfile.open("new.fle");

```

## open modes

(386)

| flag            | effects                               |
|-----------------|---------------------------------------|
| `ios::in`       | read mode                             |
| `ios::out`      | write mode, overwrite ofc             |
| `ios::app`      | append mode                           |
| `ios::trunc`    | truncate mode (to zero length ofc)    |
| `ios::ate`      | open and seek to end immediately      |
| `ios::binary`   | binary mode                           |

### default settings when opening a file

the `constructor` and the method `open()` of all stream classes use the following default values:

| class            | default flags              |
|------------------|----------------------------|
| `ifstream`       | `ios::in`                  |
| `ofstream`       | `ios::out | ios::trunc`    |
| `fstream`        | `ios::in | ios::out`       |

### open mode flags

example:

```c++

fstream addresses("address.fle", ios::in | ios::app);

// or

fstream addresses;
addresses.open("address.fle", ios:in | ios::app);

```

### error handling

the state flag `failbit` of the `ios` base class is raised if errors occur when opening a file.

how to get the flag:

- using `fail()` method directly, or
- using `if(!myfile)` indirectly

example:

```c++

if(!myfile) { //... }
// or:
if(myfile.fail()) { //... }

/*
the `failbit` is also set if a read or write error occurs.
if a read operation fails, the end of the current file may have been reached.

to distingush this normal behavior from a read error, u can use the `eof()` method(eof=end-of-file) to query the `eof` bit.
*/

if(myfile.eof()) // at end-of-file?

```

## closing file

(388)

### motivation

why close file always after file manipulation is done?

- data may be lost, if for some reason the program is NOT terminated correctly
- there is a limit to the number of files that a program can open simultaneously

a program that terminates correctly will automatically close any open files before exiting. a file stream destructor will also close a file referenced by a stream. however, if the file is no longer in use before this point, u should close the file explicitly.

[question]

if a program that terminates incorrectly, will any open files be automatically closed before exiting?

answer: NO

explicitly closing file is good practice in real life.

### method `close()` and `is_open()`

example:

```c++

myfile.close()

// or:

if(myfile.is_open())
{ //... }

```

### the `exit()` function

prototype: `void exit(int status)`

example:

```c++
#include <cstdlib>

std::exit(1); // why?

/*(https://www.daniweb.com/programming/software-development/threads/196899/exit-not-declared-in-scope)

The cstdlib header contains the definition for the exit function,
however up until recently this header was generally included by dependency
- often unnecessarily - by other headers.
So you are likely to see tutorials and books that rely on this - and other - header
dependencies that have now been cleaned up.

For example you may just #include <iostream> to use the exit function in gcc 3.4
because iostream includes cstdlib
however in gcc 4.3 this dependency has been removed
so you need to #include <cstdlib> to utilise it.
*/

```


## reading and writing blocks

(390)

the file stream `classes` can use all the `public` operations defined in their base classes. this means u can write formatted or unformatted data to a file or read that data from the file block by block or character by character.

### formatted and unformatted input and output

example:

```c++

double price = 12.34;
ofstream textFile("Test.txt");
textFile << "Price: " << price << " Dollar" << endl;

/*
the file Test.txt will contain a line of text, such as "Price: ..." that exactly matches the screen output.
*/

```

converting binary data to legible text is NOT practicable if u are dealing with large aoumts of data. it makes sense to write the data for a series of measurements to a binary file in the order in which they occur in the program.

to do so, u simply open the file in binary mode and write the data to the file, or read it from the file, block by block.

### transferring data blocks

the `ostream` method `write()` transfers given number of bytes from main memory to a file.

prototype: `ostream& write(const char *buff, int n);`

example:

```c++

if(!fileStream.write("An example", 2))
{
    std::cerr << "Error in writing!" << std::endl;
}

```

using `ostream` method `read()` transfers a data block from a file to a program buffer.

prototype: `istream& read(char *buf, int n);`

the methods `read()` and `write()` are often used for fiels with fixed length records. the block that needs to transferred can contain one or more records. **the buffer in main memory is either a `structure variable` or an `array` with elements beloing to the structure type**. u need to cast the address of this memory area to (char*).

## object persistence

(414)

### storing objects

objects are created during program runtime and cleaned up before the program terminates. to avoid this volatility, u can make an object `presistant`, that is, u can store the object in a file. however, u MUST ensure that the object can be reconstructed, as it was, when read. this means dealing with the following issues:

- objects can contain other objects. u will generally not know how to store a member object
- objects can contain references to other objects.however, it does NOT make sense to store pointer values in a file, as the memory address will change each time u re-launch the program.

**one possible solution** to this issue is to store the data to allow them to be passed to a constructor for the class when read. **another solution** involves providing methods to allow the objects to write their own data members to files or read them from files. this technique is normally preferable since the class can now handle data storage itself, allowing it to write internal status data while simultaneously preventing external access to that data.

### storing account class objects
