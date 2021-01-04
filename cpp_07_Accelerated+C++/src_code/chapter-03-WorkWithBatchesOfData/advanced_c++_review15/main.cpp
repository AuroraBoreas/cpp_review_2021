/*
compiler generated function
+ assign operator
    - what: cls_name& operator=(const cls_name& cn);
    - when: when compiler needs it

+ copy constructor
    - what: cls_name(const cls_name& cn);
    - when: when compiler needs it

+ default constructor
    (constructor w/o providing args)
    - what: cls_name();
    - when: when compiler needs it

+ default destructor
    - what: ~cls_name(){};
    - when: when compiler needs it

how to disable them?
- put them into private

why disable them?
- because they are implicit, sometimes they are causing trouble

*/
#include <iostream>
#include <string>
using namespace std;

class Dog
{
private:
    string name;
public:
    Dog(const string& s): name(s) { cout << "Dog " << name << " born" << endl; }
    Dog() { cout << "Dog " << " default constructor" << endl; }
    Dog& operator=(const Dog& d);
    Dog(const Dog& d);
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
