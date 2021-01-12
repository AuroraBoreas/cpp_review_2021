#include <iostream>
#include <memory>
#include <future>

using namespace std;

void func(int x, int y){ std::cout << (x + y) << std::endl; };

auto l = [](int x, int y){ std::cout << (x + y) << std::endl; };

class C
{
    public:
        void operator()(int x, int y) const { std::cout << (x + y) << std::endl; };
        void memfunc(int x, int y) const { std::cout << (x + y) << std::endl; };
};


int main()
{
    C c;
    std::shared_ptr<C> sp(new C);

    // bind() uses callable obj to bind args
    std::bind(func, 77, 33)();    // calls: func(77, 33)
    std::bind(l, 77, 33)();       // calls l(77, 33)
    std::bind(C(), 77, 33)();     // calls C::operator()(77, 33)
    std::bind(&C::memfunc, c, 77, 33)();    // calls c.memfunc(77, 33)
    std::bind(&C::memfunc, sp, 77, 33)();   // calls sp->memfunc(77, 33)

    std::cout << "async\n";
    // async() uses callable obj to start(background) tasks
    auto x1 = std::async(func, 42, 77);   // calls func(42, 77)
    auto x2 = std::async(l, 42, 77);
    auto x3 = std::async(c, 42, 77);
    auto x4 = std::async(&C::memfunc, &c, 42, 77);
    auto x5 = std::async(&C::memfunc, sp, 42, 77);
    x1.wait();
    x2.wait();
    x3.wait();
    x4.wait();
    x5.wait();

    return 0;
}
