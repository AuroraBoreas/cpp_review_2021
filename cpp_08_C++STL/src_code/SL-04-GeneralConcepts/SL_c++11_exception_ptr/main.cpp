#include <iostream>
#include <exception>

using namespace std;
std::exception_ptr eptr;

void foo()
{
    try
    {
        cout << 1/0 << endl;
        throw;
    }
    catch(...)
    {
        // save exception for later processing
        eptr = std::current_exception();
    }
}

int main()
{
    cout << "Hello world!" << endl;

    foo();
    return 0;
}
