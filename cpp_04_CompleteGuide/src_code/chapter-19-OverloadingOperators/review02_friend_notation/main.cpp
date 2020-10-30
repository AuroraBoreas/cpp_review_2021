#include <iostream>
#include "euro.h"

using namespace std;

int main()
{
    const int _size(4);
    Euro arr[_size] = {
                        //Euro, // not working. why? dont know its an obj or a class name..
                        Euro(0.1),
                        Euro(10, 1),
                        Euro(99.99),
                        Euro(101.57),
                      };

    for(int i=0; i < _size; ++i)
    {
        std::cout << "Euro obj " << (i+1) << " : ";
        arr[i].print(std::cout);
    }

    // * * * test overload operators * * *
    Euro e1,
         e2(10, 10);

    e1 += e1;
    e1.print(std::cout);

    e1 = e1 + e2;
    e1.print(std::cout);

    e1 = e1 - e2;
    e1.print(std::cout);

    e1 += e2;
    e1.print(std::cout);

    e1 -= e2;
    e1.print(std::cout);

    e1 = e1 + 99.00;    // works. but why? type conversion.
    e1.print(std::cout);

    //e1 = 99.00 + e1;
    /* not working. why? implicit type conversion failed.
    how to fix?
    - global op ol. writing one global op ol -> resolve two: a+b, b+a
                                             -> BUT can NOT coexist with member method op ol with same operators thou..
    - write one more b+a etc. -> not work as class member methods..

    */
    //e1.print(std::cout);
    e1 = 99.00 + e1; // should pass compilation now. lets go
    e1.print(std::cout);

    // --- friend op ol ---
    e1 = e1 * 3.1;
    e1.print(std::cout);
    e2 = 0.3 * e1;
    e2.print(std::cout);
    e2 = e2/9.9;
    e2.print(std::cout);

    Euro e3(10,0);
    e3 = 200.0/e3;
    e3.print(std::cout);

    return 0;
}
