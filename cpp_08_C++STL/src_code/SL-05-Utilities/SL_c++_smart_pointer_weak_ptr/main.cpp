#include <iostream> // for std::cin, std::cout, std::endl
#include <memory>   // for shared_ptr, weak_ptr, unique_ptr
#include <string>   // for std::string
#include <vector>   // for std::vector
#include <stdexcept>    // for throw
#include <cstdlib>  // for std::cerr

//class Person    // version 1
//{
//public:
//    std::string m_name;
//    std::shared_ptr<Person> m_mother;
//    std::shared_ptr<Person> m_father;
//    std::vector<std::shared_ptr<Person>> kids;  // using shared_ptr
//
//    // cyclic reference...
//    Person(const std::string& n,
//           std::shared_ptr<Person> m = nullptr,
//           std::shared_ptr<Person> f = nullptr)
//    : m_name(n), m_mother(m), m_father(f){}
//
//    ~Person()
//    {
//        std::cout << "delete " << m_name << std::endl;
//    }
//};

class Person    // version 2
{
public:
    std::string m_name;
    std::shared_ptr<Person> m_mother;
    std::shared_ptr<Person> m_father;
    std::vector<std::weak_ptr<Person>> kids;    // using weak_ptr

    // cyclic reference...
    Person(const std::string& n,
           std::shared_ptr<Person> m = nullptr,
           std::shared_ptr<Person> f = nullptr)
    : m_name(n), m_mother(m), m_father(f){}

    ~Person()
    {
        std::cout << "delete " << m_name << std::endl;
    }
};


std::shared_ptr<Person> initFamily(const std::string& name)
{
    std::shared_ptr<Person> mom(new Person(name + "'s mom"));
    std::shared_ptr<Person> dad(new Person(name + "'s dad"));
    std::shared_ptr<Person> kid(new Person(name, mom, dad));

    mom->kids.push_back(kid);
    dad->kids.push_back(kid);

    return kid;
}



int main()
{
    // weak_ptr
    {
        /*
        + what: shared_ptr but w/o ownership to the address of an obj.

        + when: cyclic reference, or only share but not owning etc.

        + how:
            default constructor
            copy constructor
            only a constructor taking shared_ptr

            u can't user operator * and -> to access a referenced obj of a weak_ptr directly;
            instead, u have to create a shared_ptr out of it.



        + using weak_ptr.lock()-> to access member of an obj

        + check status of weak_ptr exists
            using expire() is faster than user_count();
            explicitly convert weak_ptr to shared_ptr;
            using use_count();

        +

        +

        */

        std::shared_ptr<Person> p = initFamily("nico");

        std::cout << "nico's family exists" << std::endl;
        std::cout << "- nico is shared " << p.use_count() << " times" << std::endl;
        std::cout << "- name of 1st kid of nico's mom: "
                  << p->m_mother->kids[0].lock()->m_name
                  << std::endl;

        p = initFamily("jim");
        std::cout << "jim's family exists" << std::endl;

    }

    // check if weak_ptr exists
    {
        std::cout << "\ncheck weak_ptr status\n" << std::endl;
        try
        {
            std::shared_ptr<std::string> sp(new std::string("hi"));
            std::weak_ptr<std::string> wp = sp;
            sp.reset();

            std::cout << wp.use_count() << std::endl;
            std::cout << std::boolalpha << wp.expired() << std::endl;
            std::shared_ptr<std::string> p(wp); // create a shared_ptr from a expired weak_ptr, throws std::bad_weak_ptr
        }
        catch(const std::exception& e)
        {
            std::cerr << "exception: " << e.what() << std::endl;
        }
    }



    return 0;
}
