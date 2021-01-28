#include <iostream>
#include <functional>
#include <vector>

using namespace std;

template<typename T>
void foo(T val)
{ cout << val << endl; }


class MyClass{};

void func(int x, int y)
{ cout << "from func: x = " << x << ", y= " << y << endl; }

class C
{
public:
    void memFunc(int x, int y) const
    {
        cout << "from memFunc: x = " << x << ", y= " << y << endl;
    }
};

int main()
{
    // reference_wrapper<> cls, (P132)
    {
        /*
        std::ref(); implicit conversion to T&;
        std::cref(); implicit conversion to const T&;

        */
        int x = 42;
        foo(std::ref(x)); // int&
        foo(std::cref(x)); // const int&

        /*

        reference_wrapper allows u to use references as first-class obj,
        such as element type in arrays or STL containers:


        */
//        std::vector<MyClass&> coll; // error out
        std::vector<std::reference_wrapper<MyClass>> coll; // OK
    }

    // std::function<> cls, (P133)
    {
        /*
        + usage: provides polymorphic wrappers that generalize the notion of a function pointer.

        + purpose: this class allows u to use callable obj
                    (function,
                     function members,
                     function obj,
                     and lambda) as first-class obj

        */

        std::vector<std::function<void(int, int)>> tasks;
        tasks.push_back(func);
        tasks.push_back([](int x, int y)
                        {
                            cout << "from lambda: x = " << x << ", y= " << y << endl;
                        });

        // call each task:
        for(std::function<void(int, int)> f: tasks)
        {
            f(33, 66);
        }

        // member functions in cls
        std::function<void(const C&, int, int)> mf;
        mf = &C::memFunc;
        mf(C(), 42, 77);

    }

    return 0;
}
