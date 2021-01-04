/*

normal cls vs composition cls

+ normal cls: AEIP
    - abstraction
    - encapsulation
    - inheritance
    - polymorphism

+ composition cls
    - naming is important for software engineers.
    - common activities -> segregation
    - other inheritance

*/

#include <iostream>
#include <string>

using namespace std;

class Activity
{
    public:
        virtual void bark(void) const = 0;
        virtual void call(void) const = 0;
};

class BaseDog: public Activity
{
    public:
        BaseDog(){ cout << "Base Dog born" << endl; }
        ~BaseDog(){ cout << "Base Dog destroyed" << endl; }
        void bark(void) const
        {
            cout << "Base Dog is barking" << endl;
        }
        void call(void) const
        {
            cout << "Base Dog is calling" << endl;
        }
};

class YellowDog: public Activity
{
public:
    YellowDog(){ cout << "Yellow Dog born" << endl; }
    ~YellowDog(){ cout << "Yellow Dog destroyed" << endl; }
    void bark(void) const
    {
        cout << "Yellow Dog is barking" << endl;
    }
    void call(void) const
    {
        cout << "Yellow Dog is calling" << endl;
    }
};

class GreenDog: public Activity
{
public:
    GreenDog(){ cout << "Green Dog born" << endl; }
    ~GreenDog(){ cout << "Green Dog destroyed" << endl; }
    void bark(void) const
    {
        cout << "Green Dog is barking" << endl;
    }
    void call(void) const
    {
        cout << "Green Dog is calling" << endl;
    }
};

class SuperiorDog: public BaseDog
{
public:
    SuperiorDog(){ cout << "Superior Dog born" << endl; }
    ~SuperiorDog(){ cout << "Superior Dog destroyed" << endl; }
    void bark(void) const
    {
        cout << "Superior Dog is barking" << endl;
    }
    void call(void) const
    {
        cout << "Superior Dog is calling" << endl;
    }
};

int main()
{
    // BaseDog d1(); // not OK. its a function with return_type BaseDog..
    // or
    BaseDog d1 = BaseDog();
    d1.bark();

    YellowDog* d2 = new YellowDog();
    d2->call();

    delete d2;

    return 0;
}
