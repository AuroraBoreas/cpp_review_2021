#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

//class IntVector // version 0: looks ugly
//{
//    std::vector<int> v;
//public:
//    IntVector() { v = {1, 2, 3, 4, 5}; }
//    // member access
//    int getItem(int index)
//    {
//        if(index >=0 && index < v.size())
//            return v[index];
//        else
//        {
//            throw std::out_of_range("index out of range error");
//            return -1;
//        }
//    }
//
//    void setItem(int index, int x)
//    {
//        if(index >=0 && index < v.size())
//            v[index] = x;
//        else
//        {
//            throw std::out_of_range("index out of range error");
//        }
//    }
//};

class IntVector // version 0: looks ugly
{
    std::vector<int> v;
public:
    IntVector() { v = {1, 2, 3, 4, 5}; }
    // member access
    int& operator[](int index)
    {
        if(index >=0 && index < v.size())
            return v[index];
    }
    const int& operator[](int index) const
    {
        if(index >=0 && index < v.size())
            return v[index];
    }
};

int main()
{
    IntVector v;

    // v.setItem(0, 42);
    // std::cout << v.getItem(0) << std::endl;

    std::cout << v[0] << std::endl;
    v[0] = 42;
    std::cout << v[0] << std::endl;
    return 0;
}
