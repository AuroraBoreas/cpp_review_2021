// cpp_02_branchless.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>

using std::default_random_engine;
using std::uniform_int_distribution;

int smaller(int a, int b);
int smaller_branchless(int a, int b);

int main() 
{
    std::cout << "Hello World!\n";
    default_random_engine e;
    uniform_int_distribution<unsigned> u(0, 100);

    for (int i = 1; i < 10; i++)
    {
        int x = u(e);
        int y = u(e);

        std::cout << "if/else" << std::endl;
        std::cout << "x = " << x << ","
            << "y = " << y << ","
            << smaller(x, y)
            << " is smaller" << std::endl;

        std::cout << "branchless" << std::endl;
        std::cout << "x = " << x << ","
            << "y = " << y << ","
            << smaller_branchless(x, y)
            << " is smaller" << std::endl;
    }

    int t;
    std::cin >> t;
    return 0;
}

int smaller(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int smaller_branchless(int a, int b)
{
    return a * (a < b) + b * (b <= a);
}
