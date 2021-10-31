#include "A.h"

int main()
{
    A a = A();
    B b = B();
    a.do_this(&b);
    b.do_that(&a);

    std::cin.get();

    return 0;
}
