#include <iostream>
#include <string>

class Base
{
private:
    int m_a, m_b;
    std::string m_name;
public:
    Base(int a, int b, const std::string& name)
    : m_a(a), m_b(b), m_name(name)
    {}

    virtual void print(void) = 0;

};


int main()
{
    // u cant create obj of abs class
    Base b1 = Base(1, 2, "ZL"); // not OK. compiler complains

    return 0;
}
