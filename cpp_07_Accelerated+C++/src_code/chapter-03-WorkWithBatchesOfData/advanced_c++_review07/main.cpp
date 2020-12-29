#include <iostream>
#include <string>
using namespace std;

class Dog
{
private:
    string name;
public:
    Dog(const string& s): name(s){}
    operator string(void) const
    {
        return name;
    }
};

int main()
{
    Dog d("meow");

    cout << string(d) << endl;

    return 0;
}
