#include <iostream>
#include "euro1.h"

using namespace std;

class A
{
    public:
        int a;
};

int main()
{
    Euro e1(9.7), e2(10.1), e3(-e1);
    std::cout << "e1: " << e1.asString() << std::endl;
    std::cout << "e2: " << e2.asString() << std::endl;

    // --- test operator functions ---
    // negative sign
    std::cout << "e3: " << e3.asString() << std::endl;
    // addition
    e1 += 9.79;
    std::cout << "e1+=9.79; e1: " << e1.asString() << std::endl;
    // +=
    e1 += e2;
    std::cout << "e1+=e2; e1: " << e1.asString() << std::endl;
    // -=
    e1 -= e2;
    std::cout << "e1-=e2; e1: " << e1.asString() << std::endl;

    // more
    Euro wholesale(20, 50), retail;
    retail = wholesale;
    retail += 9.49;

    Euro profit(retail - wholesale);
    std::cout << "profit: " << profit.asString() << std::endl;
    profit.print(std::cout);


    // test class A, the behavior of default constructor
    A a1;
    std::cout << "a1:" << a1.a << std::endl;





    return 0;
}
