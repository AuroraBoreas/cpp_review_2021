#include <iostream>

using namespace std;

int main()
{
    // cast
    {
      /*

        + concept
            - cast or type conversion is a basis of language
            - it enables conversion btwn different types(primitive types or even user-defined-type, like cls, struct)
            - why: to simulate stuff in real life..
                for example:
                int a = 3; float b = 3.14;
                a + b = ?;
                a < b ?;
                ...;

                w/o unifying types of a and b, we dont know how to do these operations.
                irl, we do "type conversion" subconsciously

                for example:
                a = 3.00;   // convert a from int to float with 2 bit precisons
                // then
                a + b = 3.00 + 3.14 = 6.14;
                a < b = 3.00 < 3.14 = true;
                ...;

            we need a standard or protocol to do type conversion over universe

        + category
            - implicit type conversion(always widening)
            - explicit type conversion

        + type capacity
            - C
            - S
            - I
            - L
            - F
            - D

        + behavior or pattern
            - downcasting
            - upcasting

        + approach
            - (C-style)var;
            - dynamic_cast<T>(var); // for pointers only
            - static_cast<T>(var);  // any
            - const_cast<T>(var);   // remove or add const kw
            - reinterpret_cast<T>(var); // for pointers

      */
      int a = 3; float b = 3.14;
      std::cout << "a + b = " << (a + b) << std::endl;



    }
    return 0;
}
