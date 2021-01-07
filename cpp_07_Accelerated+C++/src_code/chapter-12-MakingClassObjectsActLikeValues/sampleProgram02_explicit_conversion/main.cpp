#include <iostream>

using namespace std;

struct A
{
    A(int i){}
    A(int i, int j){}
    operator bool() const { return true; }
};

struct B
{
    explicit B(int i){}
    explicit B(int i, int j){}
    explicit operator bool() const { return true; }
};

int main()
{
    cout << "test" << endl;
    A a1 = 1;
    A a2(2);
    A a3{3, 4};
    A a4 = {4, 5};
    A a5 = (A)1;
    if(a1);
    bool na1 = a1;
    bool na2 = static_cast<bool>(a1);


    return 0;
}
