# more about files

(658)

topics

1. random access to files based on file streams
2. options for querying file state
3. exception handling for files.

also

- how to make objects in polymorphic classes persistent, that is, how to save them in files.
- include simple index files and hash tables.

## opening a file for random access

(659)

combined open modes for read and write access

| open mode                         | effects                                                   | Must the file exist? |
|-----------------------------------|-----------------------------------------------------------|----------------------|
| `ios::in | ios::out`              | open the file for input and output                        | yes                  |
| `ios::in | ios::out | ios::trunc` | open the file for input and output.                       | no                   |
|                                   | if the file already exists, it will be truncated.         |                      |
| `ios::in | ios::out | ios::app`   | open the file for input and output.                       | no                   |
|                                   | if the file does NOT exist, it will be created.           |                      |
|                                   | before each writing access, a seek to end is performed.   |                      |

### random file access

so far we have only looked at `sequential file access`. if u need access to specific information in such a file, u have to walk through the file from top to tail, and now records are always appended at the end of the file.

`random file access` gives u the option of reading and writing informatino directly at a pre-defined position. to be able to do this, u need to change the current file position explicitly, that is, u need to point the `get`/`put` pointer to the next byte to be manipulated. after pointing the pointer, u can revert to using the read and write operations that u are already familiar with.

### open mode

one prerequisite of `random file access` is that the position of the records in the file can be precisely identified. this implies opening the file in binary mode to avoid having to transfer additional escape characters to the file.

example:

```c++

ios::openmode mode = ios::in | ios::out | ios::app | ios::binary;
fstream fstr("account.fle", mode);

```

this statement opens the file "account.fle" in binary mode for reading and `appending at end-of-file`. the file will be created if it did NOT previously exist. `random read access` to this file is possible, but for write operations new records will be appended at the end of the file.

to enable random read and write access to a file, the file can be opened as follows:

example:

```c++

ios::openmode mode = ios::in | ios::out | ios::binary;
fstream fstr("account.fle", mode);

```

however, this technique can only be used for existing files. if the file does NOT exist, u can use the `ios::trunc` flag to create it.

## positioning for random access

(661)

table: the three access points in a file.

| access point            | position flag     | file          |
|-------------------------|-------------------|---------------|
| beginning of the file   | `ios::beg`        |     .         |
| current position        | `ios::cur`        |     .         |
| end of file             | `ios::end`        |     .         |

### discovering and changing the current position

the file stream classes comprise methods to discover and change the current position in a file. the `tellp()` and `tellg()` methods return the current position of the `put` or `get` pointers as a long value.

example: `long rpos = myfile.tellg();`

this statement queries the current position of the `read pointer` in the `myfile` stream. the current position is always returned as a byte offset relative to the begining of the file.

the current file position can be modified using the `seekp()` or `seekg()` method.
the position is stated as a byte offset, relative to either the beginning or end of the file, or relative to the current position in the file.

### positioning flags

three `ios::seekdir` type positioning flags are defined in the `ios` class for this purpose; these are `ios::beg`, `ios::cur`, and `ios::end`.

imagine u wanna write the obj `acc` to the file "account.fle" at offset pos. u can use the following statements to do so:

example:

```c++

ofstream fstr("accout.fle", ios::out | ios::binary);
fstr.seekp(pos, ios::begin);
acc.write(fstr);

```

this calles the `write()` method in the `Account` class, which allows an obj to write its own data members to a file.

if u do NOT specify a positioning flag, the position will be assumed to be relative to the beginning of the file. the statement used to position the write pointer in the last example can therefore be formulated as follows:

example: `fstr.seekp(pos);`

the byte offset can also be negative for calls to the methods `seekp()` and `seekg()`. however, u can NOT position the read/write pointer before the beginning of the file.

in constrast, it is possible to place the pointer at a position after the end of the file and then perform a write operation, which will create a gap with unknown content in the file. **this only makes sense if all the empty slots in the file are of an equal length, as they can be overwritten later**.

## positioning for random file access(continued)

(663)

representing an index entry

```c++

#ifndef INDEX_H_INCLUDED
#define INDEX_H_INCLUDED

class IndexEntry
{
    private:
        long key;
        long recNr;
    public:
        // constructor
        IndexEntry(long k=0L, long n=0L)
        {
            key = k; recNr = n;
        }
        // destructor, getter, setter, repr
        // more, file io
        int recordSize(void) const
        {
            return sizeof(key) + sizeof(recNr);
        }
        fstream& write(fstream& ind) const;
        fstream& read(fstream& ind);
        fstream& write_at(fstream& ind, long pos) const
        {
            ind.seekp(pos);
            ind.write((char*)&key, sizeof(key));
            ind.write((char*)&recNr, sizeof(recNr));
            return ind;
        }
        fstream& read_at(fstream& ind, long pos)
        {
            ind.seekg(pos);
            ind.read((char*)&key, sizeof(key));
            ind.read((char*)&recNr, sizeof(recNr));
            return ind;
        }
};

#endif // INDEX_H_INCLUDED

```

### using positioning methods

the following statements are commonly used for random positioning

`seakg(0L);` and `seekp(0L, ios::end);`

they set the current position to the beginning or end of a file. **u should be aware that the first arg is 0L to indicate that `long type` is required**.

if u need to determine the length of a file, u can point the `get` pointer to the end of the file and then query the position of the pointer.

example:

```c++

fstr.seekg(0L, ios::end);
unsigned long cout = fstr.tellg();

```

the `count` variable will then contain the number of bytes occupied by the file.

**these positioning methods are useful for files opened in binary mode**. however, it does NOT make much sense to use them for text files or particularly for devices. **in text mode, conversions of LF <=> CR/LF prevent the methods from working correctly**. (???)


[what does the `g` stand for in `gcount`, `seekg`, `tellg`?]

link: https://stackoverflow.com/questions/53608590/what-does-the-g-stand-for-in-gcount-tellg-and-seekg

explanation:

in streams supporting both read and write, u actually have two positions, one for read(i.e. "get" denoted by "g") and one for write(i.e. "put" denoted by a "p").

and that's why u have a `seekp`(inherited from `basic_ostream`), and a `seekg`(inherited from `basic_istream`).

side note: the lang C has - in constrast to C++ - only one such function `fseek` for both pointers; there it is necessary to re-position the pointer when switching from read to write and vice versa. to avoid this, C++ offers separate functions for read and write, respectively.

### determining positions in a file

the position of records in a file is easy to compute if all the records in the file are the same length. Given that size is the length of a record

`0L, size, 2*size, ...`

are the positions of the first, second, third records, and so on.

if u are working with variable length records, u can NOT exactly compute their postions. to enable random access u therefore need to store the positions of the records in a separate structure, a so-called `index`.

the index stores pairs of keys and record positions, so-called `index entries` in a file. a key, a social security number, or custom id, for example, MUST uniquely identify a record. if the index is sorted, the position that correlates to the required key can be quickly found using the binary search algorithm.

### the `IndexEntry` class

the `IndexEntry` class, used to represent an index entry. the class comprises methods for reading and writing an index entry at the current file position or at any given position. the appropriate file stream is passed as an arg to the method.

## file state

(665)

representing an index

```c++

#ifndef INDEX_H_INCLUDED
#define INDEX_H_INCLUDED

// index.h (continued)
// adds the definition of an index

class IndexFile
{
    private:
        fstream index;
        string  name;
    public:
        // constructor
        IndexFile(const string& file)
        {
            ios::openmode mode = ios::in | ios::out | ios::binary;
            index.open(file.c_tr(), mode);
            if(!index) // if the file does NOT exist
            {
                index.clear();
                mode |= ios::trunc;
                index.open(file.c_str(), mode);
                if(!index)
                    return;
            }
            else
                name = file;
        }
        // destructor
        ~IndexFile() { index.close(); }
        // methods
        void insert(long key, long pos);
        long search(long key);
        void retrieve(IndexEntry& entry, long pos);
};

#endif // INDEX_H_INCLUDED

```

### state flags

a file stream can assume various states, for example, when it reaches the end of a file and can NOT continue reading. a file operation can also fail if a file can NOT be opened, or if a block is not transferred correctly.

the `ios` class uses `state flags` to define the various states a file can assume. each state flag corresponds to a single bit in a `status-word`, which is represented by the `iostate` type in the `ios` class. the following exists:

| flags             | meaning                                               |
|-------------------|-------------------------------------------------------|
| `ios::eofbit`     | end of file reached                                   |
| `ios::failbit`    | last read or write operation failed                   |
| `ios::badbit`     | an irrecoverable error occurred                       |
| `ios::goodbit`    | the stream is ok, e.g. no other state flag is set.    |

the "flags" `ios::goodbit` is an exception to the rule since it is NOT represented by a single bit, but by the value 0 if no other flag have been set. in other words **a `status-word` has the value `ios::goodbit` if everything is fine!**

### discovering and changing the state

there are multiple methods for discovering and modifying the status of a stream. a method exists for each state flag; there are `eof()`, `fail()`, `bad()` and `goood()`. they return `true` when the corresponding flag has been raised. this means u can discover the end of a file with the following statement:

example: `if(fstr.eof()) ...;`

the status-word of a stream can be read using the `rdstate()` method. individual flags can then be queried by a simple comparison:

example: `if(myfile.rdstate() == ios::badbit) ...;`

the `clear()` method is available for clearing the status-word. if u call `clear()` w/o any arg, all the state flags are cleared. an arg of the `iostate` type passed to `clear()` automatically becomes the new status-word for the stream.

### the `IndexFile` class

pass

## exception handling for files

(667)

defining yoru own exception classes

```c++

// exception.h

#ifndef EXCEPTION_H_INCLUDED
#define EXCEPTION_H_INCLUDED

class FileError
{
    private:
        string filename;
    public:
        FileError(const string& file): filename(file){}
        string getName(void) const { return filename; }
};

class OpenError: public FileError
{
    public:
        OpenError(const string& file): FileError(file){}
};

class ReadError:public FileError
{
    public:
        ReadError(const string& file): FileError(file){}
};

class WriteError:public FileError
{
    public:
        WriteError(const string& file): FileError(file){}
};

#endif // EXCEPTION_H_INCLUDED

```

### implementing your own exception handling

(668)

u can exploit the error tracking options that state flags give u to implement your own exception handling for files. for example, a method that reads records from a file can throw an exception when the state flag `ios::eof` is raised, that is, when the end of the file is reached.

### standard exception handling for streams

C++ also provides standard exception handling for streams. u can use the `exceptions()` method to specify the flags in the status-word of a stream that will cause exceptions to be thrown.

the `exceptions()` method is defined in the `ios` stream base class. the method expects one or multiple state flags separated by the `|` sign. an exception is then thrown for the flags specified.

example:

```c+

ifstream ifstrm("account.fle");
fstrm.exceptions(ios::failbit | ios::badbit);

```