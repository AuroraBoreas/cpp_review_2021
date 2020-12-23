#include <iostream>

using namespace std;

struct sm
{

public:
    int a;
    int b;
    sm()
    {
        a = 1;
        b = 2;
    }
    void display(void) const
    {
        std::cout << "struct enter the chat" << std::endl;
    }
};

int main()
{
    sm mytm;
    std::cout << mytm.a << std::endl;
    std::cout << mytm.b << std::endl;

    mytm.display();

    return 0;
}
