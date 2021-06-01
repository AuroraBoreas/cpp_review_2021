#include <iostream>

namespace LRvalues
{
    int& func()
    {
        static int x = 10;
        return x;
    }

    int func1(int& x)
    {
        return x;
    }
}

int main()
{
    LRvalues::func() = 30;
    std::cout << LRvalues::func() << std::endl; // 30

    // std::cout << LRvalues::func1(10) << std::endl; // error out. 10 is rvalue; cant be binded to lreference

    return 0;
}
