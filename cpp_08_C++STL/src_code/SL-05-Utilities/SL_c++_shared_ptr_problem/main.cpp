#include <iostream>
#include <memory> // for shared_ptr, weak_ptr, unique_ptr
#include <vector>
#include <string>
#include <atomic>

//class Person // version 01
//{
//public:
//    std::string m_name;
//    std::shared_ptr<Person> m_mother;
//    std::shared_ptr<Person> m_father;
//    std::vector<std::weak_ptr<Person>> m_kids;
//
//    // constructor
//    Person(const std::string n,
//           std::shared_ptr<Person> m = nullptr,
//           std::shared_ptr<Person> f = nullptr)
//    : m_name(n), m_mother(m), m_father(f){}
//
//    // destructor
//    ~Person()
//    {
//        std::cout << "delete " << m_name << std::endl;
//    }
//
//    void setParentsAndTheirKids(std::shared_ptr<Person> m = nullptr,
//                                std::shared_ptr<Person> f = nullptr)
//    {
//        m_mother = m;
//        m_father = f;
//        if(m != nullptr)
//        {
//            m->m_kids.push_back(std::shared_ptr<Person>(this)); // ERROR, but compiles
//        }
//        if(f != nullptr)
//        {
//            f->m_kids.push_back(std::shared_ptr<Person>(this)); // ERROR, but compiles
//        }
//    }
//
//};

class Person: public std::enable_shared_from_this<Person>
{
public:
    std::string m_name;
    std::shared_ptr<Person> m_mother;
    std::shared_ptr<Person> m_father;
    std::vector<std::weak_ptr<Person>> m_kids;

    // constructor
    Person(const std::string n,
           std::shared_ptr<Person> m = nullptr,
           std::shared_ptr<Person> f = nullptr)
    : m_name(n), m_mother(m), m_father(f){}

    // destructor
    ~Person()
    {
        std::cout << "delete " << m_name << std::endl;
    }

    void setParentsAndTheirKids(std::shared_ptr<Person> m = nullptr,
                                std::shared_ptr<Person> f = nullptr)
    {
        m_mother = m;
        m_father = f;
        if(m != nullptr)
        {
            m->m_kids.push_back(shared_from_this()); // OK
        }
        if(f != nullptr)
        {
            f->m_kids.push_back(shared_from_this()); // OK
        }
    }

};

struct X
{
    int a;
};

std::shared_ptr<X> global;

void foo()
{
    std::shared_ptr<X> local{new X};
    //...;
    std::atomic_store(&global, local);
}

int main()
{
    // problem 01
    {
        int* p = new int(42);
        // std::shared_ptr<int> p1(p); // not good
        // std::shared_ptr<int> p2(p); // not OK, but compiles
        // always directly initialize a smart pointer the moment u create the obj with its resource:
        std::shared_ptr<int> p3(new int);
        std::shared_ptr<int> p4(p3); // OK
    }

    // member function list of shared_ptr
    {
        std::cout << "\n std::get_delete<T>(sp) \n";

        auto del = [](int* p){ delete p; };

        std::shared_ptr<int> p(new int, del);
        decltype(del)* pd = std::get_deleter<decltype(del)>(p);
        std::cout << *pd << std::endl;

    }

    // lifetime
    {
        // as programmer, u must ensure that obj X "owns" its member a during same lifetime at least
        std::shared_ptr<X> p1(new X);
        std::shared_ptr<int> p2(p1, &p1->a);

    }

    // static_cast<T*>(ptr) is undefined behavior against shared_ptr
    {
        // using static_pointer_cast<T>(sp) instead;
        std::shared_ptr<void> sp(new int);
        //...;
        std::shared_ptr<int>(static_cast<int*>(sp.get())); // ERROR
        std::static_pointer_cast<int*>(sp);

    }

    // thread-safe shared_ptr interface
    {
        // in general, shared_ptr is not thread-safe
        foo();
    }

    return 0;
}
