#include <iostream>
#include <stdlib.h>
#include "square.h"

int main(int argc, char* argv[])
{
    // never trust user 01
    if(argc!=2)
    {
        std::cerr << "argument must be 2!\n"
                     "example: square 1000\n";
        return -1;
    }

    // never trust user 02
    unsigned n = std::atoi(argv[1]);

    VecInt v1, v2;

    populateVecInt(n, v1, v2);
    display(std::cout, v1, v2);

    return 0;
}

