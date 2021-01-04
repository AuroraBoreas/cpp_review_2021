/*

namespace

- what is namespace?
referring to "LGEB". element vs environment
deeper question: how does compiler find var/func/cls...?

under the hood
C++ koenig searching mechanism

- why namespace?
segregation

- how to use namespace?
interface: what is an interface of a cls?
rule of hidden names

- practice to follow:
1. function works on cls should be in the same namespace of the cls
2. function

*/

#include <iostream>

using namespace std;

namespace demo
{
    class A
    {
        public:
            virtual void print(void) = 0;
            virtual void call(void) = 0;
    };

    struct X{};

    void display(X x){};

}

namespace subDemo
{
    class B{};
}

int main()
{
    demo::A* aPtr;

    return 0;
}
