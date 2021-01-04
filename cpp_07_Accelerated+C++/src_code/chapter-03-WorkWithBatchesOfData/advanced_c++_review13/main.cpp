/*
smart pointers
- unique_ptr
- shared_ptr
- weak_ptr

*/

#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Dog
{
private:
    string name;
public:
    Dog(const string& s): name(s) { cout << "Dog born" << endl; }
    ~Dog() { cout << "Dog destroyed" << endl; }
    void bark(void) const
    { cout << "Dog " << name << " is barking." << endl; }
};

void doSth(unique_ptr<Dog>);


int main()
{
    // raw pointers
    Dog* d1Ptr = new Dog("john"),
         *d2Ptr = d1Ptr;


    // ...

    delete d1Ptr;
    delete d2Ptr;

    // unique pointers
    unique_ptr<Dog> ud1Ptr(new Dog("Ben"));
    // ud1Ptr.reset();
    unique_ptr<Dog> ud2Ptr(ud1Ptr.get());
    // 1. assign ud1Ptr to ud2Ptr
    // 2. ud1Ptr gives up ownership of "Ben" dog.
    // 3. ud2Ptr owns "Ben" dog
    if(!ud1Ptr)
    {
        cout << "ud1Ptr is empty" << endl;
    }
    else cout << "ud1Ptr is not empty" << endl;

    auto aaa = "hello";
    std::cout << aaa << std::endl;

    return 0;
}

void doSth(unique_ptr<Dog> d)
{
    d->bark();
}
