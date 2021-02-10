/*

Modern C++11 review

@ZL, 20210210

*/

#include <iostream>
#include <vector>
#include <initializer_list>
#include <string>
#include <cassert>
#include <type_traits>

class zlVector
{
private:
    std::vector<int> myVec;
public:
    zlVector(const std::initializer_list<int>& v)
    {
        for(auto iter = v.begin(); iter!=v.end(); ++iter)
            myVec.push_back(*iter);
    }
    void display(void) const
    {
        for(auto i : myVec)
            std::cout << i << ' ';
        std::cout << "\n";
    }
};

class Dog
{
private:
    std::string name;
    int age;
public:
    Dog(const std::string& name, int age)
    {
        this->name = name;
        this->age = age;
    }
    void display(void) const
    {
        std::cout << name << ", " << age << std::endl;
    }
};

enum class Apple
{
    amass,
    ascolor,
};

enum class Orange
{
    omass,
    ocolor,
};

class Person
{
private:
    std::string FirstName;
    std::string LastName;
    int age = 1;
public:
    Person(const std::string& fname)
    {
        FirstName = fname;
        LastName = "";
        age = 0;
    }
    Person(const std::string& fname, const std::string& lname, int a)
    : Person(fname)
    {
        LastName = lname;
        age = a;
    }
};

int main()
{
    // initializer list
    {
        std::vector<int> v1 = { 3, 4, 1, 9};
        for(int i=0; i<4; ++i)
            std::cout << v1[i] << " ";
        std::cout << "\n";

        zlVector zlv = { 4, 2, 1, 3, 5};
        zlv.display();
    }

    // uniform initialization, object initializer in C#
    {
        /*

        + priority
            1. -> initializer_list ctor {}
            2. -> ordinary ctor ()
            3. -> aggregate initialization = {}

        */
        // list initializer
        Dog d1 = {"LL", 5};
        // ctor
        Dog d0 = Dog("KK", 4);
        // aggregate initializer
        Dog d2 = Dog{"MM", 6};

        d0.display();
        d1.display();
        d2.display();
    }

    // auto
    {
        // see class zlVector declaration;
    }

    // foreach
    {
        // see class zlVector declaration;
        // note: the class must have begin() and end();
    }

    // nullptr
    {
        int* p = nullptr;   // <-- instead of 0, or NULL(defined value is 0)
        std::cout << p << std::endl;
    }

    // enum class
    {
        Apple a = Apple::amass;
        Orange o = Orange::omass;
//        if(a == o)
//            std::cout << "green apple and big orange are the same mass\n";
//        else
//            std::cout << "green apple and big orange are not the same\n";
    }

    // static_assert
    {

        int i = 123;
        int* myPtr = &i;

        // runtime assert
        assert(myPtr == nullptr);
        // compile time assert
        static_assert(sizeof(int)==4);
    }

    // ctor delegation
    {
        // see class Person;
    }


    return 0;
}
