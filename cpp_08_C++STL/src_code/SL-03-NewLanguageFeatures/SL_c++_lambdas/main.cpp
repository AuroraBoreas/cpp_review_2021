#include <iostream>

using namespace std;

auto f = [](int x, int y)->bool { return x < y; };

int main()
{
    // assign to a var then call
    std::cout << f(3, 4) << std::endl;
    // call lambda function directly
    []{ std::cout << "hello lambda" << std::endl; }();
    // captures(access to outer scope)
    int x = 11, y = 12;
    auto g = [x, &y]{ std::cout << "x: " << x << std::endl;
                      std::cout << "y: " << y << std::endl;
                      ++y;
                    };
    x = y = 77;
    g();
    g();
    std::cout << "final y: " << y << std::endl;

//    std::cout << [&](int x, int y){ std::cout << "x: " << x << std::endl; std::cout << "y: " << y << std::endl; ++x; ++y; }(a, b);

    int id = 0;
    auto h = [id]() mutable { std::cout << "id: " << id << std::endl;
                              ++id;
                            };
    id = 42;
    h();
    h();
    h();
    std::cout << "final id: " << id << std::endl;

    return 0;
}
