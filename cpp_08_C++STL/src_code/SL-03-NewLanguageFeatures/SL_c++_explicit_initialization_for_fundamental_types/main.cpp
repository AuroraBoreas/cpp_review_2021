#include <iostream>

using namespace std;

template<typename T>
void f()
{
    T x = T();
    // ...
}

int main()
{
    int i; // undefined value
    i = 1;
    int j = int(); // zero
    int k{}; // zero



    return 0;
}
