#include <iostream>
#include <functional>

using namespace std;

std::function<int(int, int)> returnLambda()
{
    return [](int x, int y){ return x * y; };
}

int main()
{
    auto f = returnLambda();
    std::cout << f(6, 7) << std::endl;

    return 0;
}
