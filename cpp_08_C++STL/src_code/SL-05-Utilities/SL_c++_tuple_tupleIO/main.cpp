/*

why this print out is not working?

the code is exactly copy-paste from the book..

(75)

*/

#include <iostream>
#include <tuple>
#include <string>
#include "printtuple.hpp"

int main()
{
    std::tuple<int, float, std::string> t1{ 77, 3.14, "hello world" };
    std::cout << "io: " << t1 << std::end;; // why not work?

    return 0;
}
