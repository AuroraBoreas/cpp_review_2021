#include <iostream>
#include <vector>

using namespace std;

//class BigArray // version 0
//{
//    std::vector<int> v;
//    int accessCounter;
//public:
//    BigArray(){ v={1, 2, 3}; }
//    const int& operator[](int index) const    // read-only subscript op []
//    {
//        accessCounter++;    // not OK. check version 1 to see how enable it
//        return v[index];    // OK. bitwise change
//    }
//
//    int& operator[](int index)  // write-only subscript op []
//    {
//        return v[index];
//    }
//};

class BigArray // version 1
{
    std::vector<int> v;
    mutable int accessCounter;
public:
    BigArray(){ v={1, 2, 3}; accessCounter = 0; }
    const int& operator[](int index) const    // read-only subscript op []
    {
        accessCounter++;    // OK. because data member accessCounter is mutable now.
        return v[index];    // OK. bitwise change
    }

    int& operator[](int index)  // write-only subscript op []
    {
        accessCounter++;
        return v[index];
    }
    void displayCounter(void) const
    {
        std::cout << accessCounter << std::endl;
    }
};

int main()
{
    BigArray ba1;
    ba1[0] = 42;
    std::cout << ba1[0] << std::endl;
    ba1.displayCounter();

    return 0;
}
