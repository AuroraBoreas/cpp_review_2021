/*

*/

#include <iostream>

using namespace std;

class Dog0
{};
// is equivalent to

class Dog1 //
{
public:
    Dog1(){};    // default constructor is somehow tricky.
    // constructor with user-providing-parameters are default constructor :pS
    Dog1(const Dog1&){};
    Dog1& operator=(const Dog1&){};
    ~Dog1(){};
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
