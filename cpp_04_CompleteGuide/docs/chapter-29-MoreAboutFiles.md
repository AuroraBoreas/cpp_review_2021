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

on accessing the `fstrm` stream an exception is thrown if either one of the flags `ios::failbit` or `ios::badbit` is raised. the operation that caused the errror is then terminated and the state flags are cleared by a call to `clear(rdstate());`.

the exception thrown here is of a standard exception class, `failure`. this type is defined as `public` element in the `ios` base class and comprises the virtual method `what()` that returns a C string containing the cause of the error. the exception handler will normally send the string to standard error output.

u can call `exceptions()` w/o any arg to discover the stage flags in a status-word of a stream that can cause an exception to be thrown. if a bit is set in the return value of the `exceptions()` method, an appropriate exception will be thrown whenever this error occurs.

example:

```c++

iostate except = fstrm.exceptions();
if(except & ios::eofbit) ...

```

this statement uses a bitwise `AND` operation to ascertain whether an exception is thrown when end-of-file is reached.

## persistence of polymorphic objects

(669)

```c++

// account.h

enum TypeId { Account, DEP_ACC, SAV_ACC };

class Account
{
    private: // data member
    public:  //constructor, access methods...
        virtual TypeId getTypeId() const { return ACCOUNT; }
        virtual ostream& write(ostream& fs) const;
        virtual istream& read(istream& fs); 
};

class DepAcc: public Account
{
    TypeId getTypeId() const { return DEP_ACC; }
    ostream& write(ostream& fs) const;
    istream& read(istream& fs);
};

class SavAcc: public Account
{
    TypeId getTypeId() const { return SAV_ACC; }
    ostream& write(ostream& fs) const;
    istream& read(istream& fs);
};


// account.cpp

#include "account.h"

ostream& DepAcc::write(ostream& os) const
{
    if(!Account::write(os))
        return os;
    os.write((char*)&limit, sizeof(limit));
    os.write((char*)&deb, sizeof(deb));
    return os;
}

istream& DepAcc::read(istream& is)
{
    if(!Account::read(is))
        return is;
    is.read((char*)&limit, sizeof(limit));
    is.read((char*)&deb, sizeof(deb));
    return is;
}

```

### storing polymorphic objects

imagine u wanna make the obj of a polymorphic class hierarchy persistent, that is, store them in a file. u need to ensure that an obj can be reconstructed precisely when it is read. this gives rise to the fact that obj in polymorphic class hierarchies contain virtual methods. so it is not simply a case of making the data members of an obj into records and writing them to a file.

**to allow the class to assume control over object storage, u need methods that allow the object to write its own data members to a file**. the methods can have a virtual definition within the class hierarchy. thus, if pointers are used to reference objects, the appropriate read/write operation for each obj will be called.

### storing objects of the `Account` hierarchy

the opposite page shows the Account class, with wichi u should already be familiar. **virtual file I/O** methods have now been added. the implementation of the `read()` and `write()` methods was discussed earlier in chapter 18.

the derived classes DepAcc and SavAcc also contain definitions of the `read()` and `write()` methods that read only their "own" objects and write them to files. the implementation first calls the appropriate base class method. if no errors occur, it is simply a question of transferring the additional data members of the derived classes to or from a file.

at present, no type information will be written to file or read from file. this task will be performed by a special class whose features are used for file management.

## persistence of polymorphic objects(continued)

(671)

```c++
// account.h; (continued)

#include "exceptio.h"

class AccFile
{
    private:
        fstream f;
        string name;
    public:
        AccFile(const string& s)    throw(OpenError);
        ~AccFile(){ f.close(); }
        long append(Account& acc)   throw(WriteError);
        Account* retrieve(long pos) throw(ReadError);
};

long AccFile::append(Account& acc) throw(WriteError)
{
    f.seekp(0L, ios::end);
    long pos = f.tellp();

    if(!f)
        throw WriteError(name);
    
    TypeId id = acc.getTypeId();
    f.write((char*)&id, sizeof(id));

    if(!f)
        throw WriteError(name);
    else
        acc.write(f);
    
    if(!f)
        throw WriteError(name);
    else
        return pos;
}

```

### a scenario

imagine u wanna save the data fro various account types, including current and savings accounts to a file. **since the objects u need to save belong to different types, u MUST save both the data members and the type of object**. this is the only way to ensure that an object will be correctly reconstructed when read.

the methods in the class u are going to define should throw exception if errors occur. the exception type thrown by a method is stated in the exception specification.

### the `AccFile` class

the `AccFile` class, which is used fro random access to a file with account data, is defined above. the data members are an `fstream` type file stream and a string used for storing the file name.

the cnostructors saves the file name and opens a given file for reading and appending at end-of-file. if the file can NOT be opened, the constructor throws an `OpenError` class exception.

the `append()` method writes an account passed to it as an arg at end-of-file and returns the position where the account was written into the file.

in order to get the current type of the arg, the virtual method `getTypeId()` is called. Depending on this type the `append()` method will write the appropriate type field to the file and then call the virtual method `write()`, allowing the current object to write itself to the file. if a write error occurs, the method will throw a `WriteError` type exception.

the `retrieve()` method first reads the type identifier and then determines the type of object it needs to allocate memory for. the data from the file is then transferred to the dynamically allocated object by a call to the virtual method `read()`. here too, an exception will be thrown if a stream access error occurs.

## application: index files

(673)

```c++

// index.cpp: (continued)

void IndexFile::insert(long k, long n) throw(ReadError, WriteError)
{
    IndexEntry entry;
    int size = entry.recordSize();

    index.clear();
    index.seekg(0. ios::end);
    long nr = index.tellg();

    if(!index) throw ReadError(name);

    nr -=size;
    bool found = false;
    while(nr>=0 && !found)
    {
        if(!entry.read_at(index, nr))
            throw ReadError(name);
        if(k<entry.getKey())
        {
            entry.write_at(index, nr+size);
            nr -=size;
        }
        else
        {
            found = true;
        }
    }

    entry.setKey(k); entry.setPos(n);
    entry.write_at(index, nr+size);

    if(!index)
        throw WriteError(name);
}

```

it makes sense to organize data sequentially in files if u need to walk through all the records regularly. this is particularly true for files used to salary data or phone bills.

however, **most application need to provide quick access to specific data**. for example, a user would definitely prefer to be able to locate an account quickly by reference to an account number, rather than searching through a file from top to bottom. index files can mean a real performance boost in cases like this.

### index files

an `index file` comprises a so-called `primary file` containing the live data, and an index. the `index` consists of pairs of keys and record positions for the primary file. a key stored in the index will identify a record in the primary file. this situation can be more easily explained by the following graphic.

(graphic on P.674)

the index is stored by reference to the keys for speed of access, allowing u to perform a binary search to locate the position of a record.

### inserting into the index

we can use the `IndexFile` class definitino to represent an index. the `insert()` method, which correctly inserts a new record into sorted index, is defined opposite.

the read pointer is first set to end-of-file for insertions. if the current position is 0, that is, the file is empty, the entry is inserted at offset 0. in all other cases, any entries whose keys are greater than the new key are shifted down to make room for the new entry.

## implementing an index file

(675)

representing the index file

```c++

// index.h: defined the class IndexFile

class IndexFileSystem: public AccFile, public IndexFile
{
    private:
        string name;
    public:
        IndexFileSystem(const string s)
        : AccFile(s + ".prim"), IndexFile(s + ".ind")
        { name = s; }
        void insert (Account& acc)
        {
            if(search(acc.getNr()) == -1)
            {
                long pos = append(acc);
                if(pos != -1)
                    IndexFile::insert(acc.getNr(), pos);
            }
        }
        Account* retrieve(long key)
        {
            long pos = search(key);
            if(pos == -1)
                return NULL;
            else
            {
                IndexEntry entry;
                IndexFile::retrieve(entry, pos);
                return (AccFile::retrieve(entry.getPos()));
            }
        }
};

```

### index file for account management

since an index file consists of a primary file and an index, it makes sense to derive the class used to represent an index file from the classes of the primary file and the index file.

the `IndexFileSystem` class, which is derived from the two previously defined classes `AccFile` and `IndexFile`, is defined on the opposite page. the only data member is a string for the file name. the constructor expects a file name as an argument and composes names for the primary file and the index by adding by adding a suitable suffix. Base initializers are then used to open the corresponding files.

it is NOT necessary to define a destructor, since files are automatically closed when the base class destructors are called.

### inserting and retrieving records

the `insert()` method das defined to insert new records. it first calls the `search()` method to check whether the account number already exists in the index. if not, a new record is appended to the end of the primary file using the `append()` method. then the key and the address of the record are inserted into the index.

the `IndexFileSystem` class also contains the `retrieve()` method, which is used to retrieve records from the primary files. the key, key, which is passed to the method, is used by the `search()` method to look up the address of the required record in the index. then the record is retrieved from the primary file by the `AccFile` class `retrieve()` method.

only the `retrieve()` methods for the `IndexFile` and `AccFile` classes and the `search()` method, which performs a binary search in the index, are needed to complete the index file implementation. it's your job to implement these three methods as your next exercise! (wow, that's harsh)

using a sorted file to implement an index has the disadvantage that records need to be shifted to make room to insert new records. as shifting is time-consuming, an index is normally represented by a tree, which needs less reorganization.
