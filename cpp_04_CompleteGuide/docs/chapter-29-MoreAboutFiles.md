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