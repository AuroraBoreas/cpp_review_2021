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

`random file access` gives u the option of reading and writing informatino directly at a pre-defined position.

