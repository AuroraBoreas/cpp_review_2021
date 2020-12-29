/*
virtual constructor -- Clone()

when to use?
polymorphic copying

or using copy constructor and copy assignment operator

*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Dog
{
    private:
        string name;
    public:
        Dog(const string& s): name(s) {}
        const string& getName(void) const { return name; }
        void display(void) const
        {
            cout << "Dog's name " << name << endl;
        }
        virtual Dog* clone(void)
        {
            return new Dog(*this);
        }
};

class YellowDog: public Dog
{
    public:
        YellowDog(const string& s): Dog(s){}
        void display(void) const
        {
            cout << "Yellow dog's name " << getName() << endl;
        }
        virtual YellowDog* clone(void)
        {
            return new YellowDog(*this);
        }
};


int main()
{
    vector<Dog> VecDog;
    VecDog.push_back(YellowDog("Meow")); // upcasting
    cout << VecDog.back().getName() << endl;
    VecDog.back().display();

    return 0;
}
