/*

SL_c++_auxiliary functions

P134

*/

#include <iostream>
#include <algorithm>
#include <string>
#include <memory>

using namespace std;

inline bool int_ptr_less(int* a, int* b)
{
    return (*a < *b);
}

void SwapNumbers(int& a, int& b)
{
    int tmp = b;
    b = a;
    a = tmp;
}

int& Add(int& a, int& b)
{
    static int tmp = a + b;
    return tmp;
}

class MyClass
{
private:
    int* m_x;
    int* m_y;
public:
    MyClass(int* x, int* y)
    : m_x(x), m_y(y)
    {}
    void increment(void)
    {
        m_x++; m_y++;
    }
    void decrement(void)
    {
        m_x--; m_y--;
    }
    void display(void) const
    {
        std::cout << "x = " << m_x << ", y = " << m_y << std::endl;
    }
};

struct Person
{
    std::string m_name;
    int m_age;

    Person(const std::string& name = "noname", int age = 1)
    : m_name(name), m_age(age)
    {}

    void display(void) const
    {
        std::cout << "name: " << m_name << ", age: " << m_age << std::endl;
        std::cout << std::endl;
    }
};

void sendAPerson(Person& p)
{
    p.m_age = 99;

    p = Person("nikki", 99); // this is final
}

void sendAPerson(Person* p)
{
    p->m_age = 999; // only this is changed
    p = new Person("nikki", 999); // no effect on arg p
}

int main()
{
    // processing the min and max
    {
        /*
        + header file: <algorithm>

        + operation                 effect
        min(a, b)
        min(a, b, cmp)

        min(initlist)
        min(initlist, cmp)

        max(a, b)
        max(a, b, cmp)

        max(initlist)
        max(initlist, cmp)

        minmax(a, b)
        minmax(a, b, cmp)
        minmax(initlist)
        minmax(initlist, cmp)

        + definition
            namespace std
            {
                template<typename T>
                const t& min(const T& a, const T& b);

                template<typename T>
                T min(initializer_list<T> initlist);

                ...

            + note: definitions of min() and max() require that both types math
                - but explicitly qualified type of template args works

            }

        */

        int x = 17,
            y = 42,
            z = 33;
        int *px = &x,
            *py = &y,
            *pz = &z;

        // max()
        int* pmax = std::max(px, py, int_ptr_less);
        std::cout << *pmax << std::endl;

        // minmax()
        std::pair<int*, int*> extremes = std::minmax({px, py, pz}, int_ptr_less);
        std::cout << *extremes.first << " " << *extremes.second << std::endl;

        // explicitly qualified template args
        int i = 6;
        long j = 3L;
        // std::max(i, j); // not OK
        std::max<long>(i, j); // OK
    }

    // swapping two values, P137
    {
        /*

        + definition
            namespace std
            {
                // ... is used to provide an exception specification
                template<typename T>
                inline void swap(T&a, T&b) ...
                {
                    T tmp(std::move(a)); // rvalue ref, unconditionally move
                    a = std::move(b);    // rvalue ref
                    b = std::move(tmp);
                }

                // overload for arrays
                template<typename T, size_t N>
                void swap(T(&a)[N], T(&b)[N]) noexcept(noexcept(swap(*a, *b)));
            }

        */

        int x = 6, y = 42;
        std::swap(x, y);
        std::cout << x << ", " << y << std::endl;

    }

    // string is mutable in C++
    {

        std::string s1 = "Zhang Liang";

        s1[0] = 'S';

        std::cout << s1 << std::endl;

    }

    // ref as args, or return_value
    {
        int x = 12,
            y = 42;

        std::cout << "before: x = " << x << ", y = " << y << std::endl;
        SwapNumbers(x, y);
        std::cout << "after: x = " << x << ", y = " << y << std::endl;

        std::cout << Add(x, y) << std::endl;
    }

    // classes are always reference types in C++?
    {
        int x = 2, y = 3;
        MyClass* a = new MyClass(&x, &y);
        std::shared_ptr<MyClass> b(a);
        std::cout << "before increment: " << std::endl;
        a->display();
        b->display();
        std::cout << "after increment: " << std::endl;
        a->increment();
        a->display();
        b->display();
        delete a;
    }

    // passing by ref or pointer
    {
        Person p1 = Person("ZL", 35);
        std::cout << "before passing by ref\n";
        p1.display();
        sendAPerson(p1);
        std::cout << "after passing by ref\n";
        p1.display();

        Person* ptr = new Person("ZL", 35);
        std::cout << "before passing by ptr\n";
        ptr->display();
        sendAPerson(ptr);
        std::cout << "after passing by ptr\n";
        ptr->display();
    }

    return 0;
}
