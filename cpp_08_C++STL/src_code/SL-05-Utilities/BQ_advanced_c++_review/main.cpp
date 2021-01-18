#include <iostream>
#include <vector>
#include <string>

class BigVector
{
    std::vector<int> v;
    mutable int counter;
public:
    // constructor
    BigVector(){ v = {1,2,3}; counter = 0; }
    // access op
    int& operator[](int index)  // write-only
    {
        counter++;
        return v[index];
    }
    const int& operator[](int index) const  // read-only
    {
        counter++;  // not OK.
        return v[index];
    }
    const int getCounter(void) const { return counter; }
};

//class Dog
//{
//
//};
//
//// is equal to
//class Dog
//{
//public:
//    Dog(){}; // default constructor
//    Dog(const Dog&){}; // copy constructor
//    Dog& operator=(const Dog&){}; // copy assignment constructor
//    ~Dog(){}; // default destructor
//};

//class Dog
//{
//    std::string m_name;
//    unsigned int m_age;
//public:
//    Dog(const std::string& name="noname", const unsigned age=1)
//    : m_name(name), m_age(age){ std::cout << m_name << " is born." << std::endl; }
//    // default constructor is therefor not generated in this case
//    Dog(const Dog& d) = delete;
//    // copy constructor is not generated as programmer declared already.
//    // even though it is deleted
//    Dog& operator=(const Dog& d) = delete;
//    // copy assignment operator is not generated as the same reason
//    ~Dog(){ std::cout << m_name << " is destroyed." << std::endl; }
//};

class Dog
{
    std::string m_name;
    unsigned int m_age;
public:
    Dog(const std::string& name="noname", const unsigned age=1)
    : m_name(name), m_age(age){ std::cout << m_name << " is born." << std::endl; }
    // default constructor is therefor not generated in this case
    Dog(const Dog& d) = delete;
    // copy constructor is not generated as programmer declared already.
    // even though it is deleted
    Dog& operator=(const Dog& d) = delete;
    // copy assignment operator is not generated as the same reason
    ~Dog(){ std::cout << m_name << " is destroyed." << std::endl; }

    // print
    // return_value is const
    // |
    // |                               the function itself promises not to change data members
    // |                               |
    const std::string& getName(void) const
    {
        // m_age++; // not OK
        return m_name;
    }
};


int main()
{
    // logic constness and bitwise constness
    {
        BigVector v1;
        v1[0] = 42;  // write
        std::cout << v1.getCounter() << std::endl;
        std::cout << v1[0] << std::endl;
        std::cout << v1.getCounter() << std::endl;

    }

    // compiler generated funcs
    {
        Dog d1; // OK. using default constructor
        Dog d2("Henry", 3); // OK
        Dog d3; // OK as well
        // d3 = d2; // not OK. as copy assignment operator is deleted
        // d3(d2); // not OK too. as copy constructor is deleted too
    }

    // constness
    {
        // V
        int i = 42; // i can be changed w/e
        i = 11; // OK
        const int j = 11; // i can't be changed except using const_cast<T>() to remove constness
        // j = 42; // not OK
        // P
        int k = 3;
        int* ptr1 = &k; // regular pointer to int k
        *ptr1++;    // OK
        ptr1++;     // OK. but be aware that ptr1++ point to undefined memory address
        std::cout << k << std::endl;

        const int* ptr2 = &k;
        ptr2++;     // OK
        *ptr2++;    // OK
        std::cout << k << std::endl;

        const int* const ptr3 = &k;
        int const* const ptr4 = &k;

        // Ref
        const int& refk = k;    // alias of k
        std::cout << refk << std::endl;

    };

    // const with functions

    {
        Dog d4;
        std::cout << d4.getName() << std::endl;
    }

    return 0;
}
