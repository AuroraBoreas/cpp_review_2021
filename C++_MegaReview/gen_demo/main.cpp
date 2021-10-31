#include <iostream>
#include <functional>

std::function<int (void)> addOne(void);

template<class T, class U>
T plusOne(T a, U b)
{
    return a + (T)b;
};

int main()
{
    std::cout << "Hello world!" << std::endl;

    std::function<int (void)> g = addOne();
    for(int i=0; i<3; ++i)
        std::cout << g() << std::endl;

    std::cout << plusOne<int, int>(2, 3) << std::endl;
    std::cout << plusOne<float, float>(2.1F, 3.1F) << std::endl;
    std::cout << plusOne<double, double>(2.71828, 3.1415926) << std::endl;

    return 0;
}


std::function<int (void)> addOne(void)
{
    static int i = 0;
    return [&]()->int{ return ++i; };
}
