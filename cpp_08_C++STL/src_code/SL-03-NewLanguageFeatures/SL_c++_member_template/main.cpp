#include <iostream>

using namespace std;

template<typename T>
class MyClass
{
    private:
        T value;
    public:
        void assign(const MyClass<T>& x) // x MUST have same type as *this
        {
            value = x.value;
        }
};

template<typename T>
class MyClass2
{
    private:
        T value;
    public:
        template<typename X>                // member template
        void assign(const MyClass2<X>& x)    // allow different template types
        {
            value = x.getValue();   // u can't access value directly, thus
        }
        T getValue() const
        {
            return value;
        }
};

inline void f()
{
    MyClass2<double> d;
    MyClass2<int> i;
    d.assign(d);
    d.assign(i);
}

int main()
{
    MyClass<double> d;
    MyClass<int> i;

    d.assign(d);
    // d.assign(i); // not OK.


    return 0;
}
