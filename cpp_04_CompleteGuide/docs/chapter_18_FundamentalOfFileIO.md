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




## closing file

(388)

## reading and writing blocks

(390)

## object persistence

(392)