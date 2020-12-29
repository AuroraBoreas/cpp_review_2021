/*
const and functions

- when to use const with functions? and why?
- overloadable? when?

*/

#include <iostream>
#include <string>
using std::string;
using std::cout; using std::endl;

class Dog
{
    private:
        mutable string name;
    public:
        Dog(const string& s): name(s) {}
        const string& getName(void) { return name; }
        const void display(void) const
        {
            cout << "Dog's name is " << name << endl;
        }

        void display(int i) const
        {
            name += " meow"; // OK
            cout << "Dog method output i " << i << endl;
        }
//
//        void display(const int i) const
//        {
//            cout << "overloaded Dog method output i " << i << endl;
//        }
//
//        void display(const int& i) const
//        {
//            cout << "overloaded Dog method output i " << i << endl;
//        }
};



int main()
{
    Dog d("Mikey");

    d.display(1);
    d.display(2);
    d.display();

    return 0;
}
