#include <iostream>
#include <fstream>
#include <cstdlib> // why?
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

inline void openError(const char *file)
{
    std::cerr << "Error on opening the file " << file << std::endl;
    std::exit(1); // ends program closing all opened files
}

void copy(std::istream& is, std::ostream& os);

int main(int argc, char* argv[])
{
    if(argc < 2 || argc > 3)
    {
        std::cerr << "Call: fcopy1 source [ destination ]" << std::endl;
        return 1; // or: exit(1);
    }

    std::ifstream infile(argv[1]);   // open 1st file
    if(!infile.is_open())
        openError(argv[1]);
    if(argc == 2)                    // just one source file
        copy(infile, std::cout);
    else
    {
        std::ofstream outfile(argv[2]);
        if(!outfile.is_open())
            openError(argv[2]);
        copy(infile, outfile);
        outfile.close();    // unnecessary
    }
    infile.close();         // unnecessary

    return 0;
}

void copy(std::istream& is, std::ostream& os)
{
    char c;
    while(is.get(c))
        os.put(c);
}
