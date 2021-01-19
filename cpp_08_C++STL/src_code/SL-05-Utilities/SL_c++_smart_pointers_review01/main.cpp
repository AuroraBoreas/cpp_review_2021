/*
    smart pointers
    + what?
        - std::shared_ptr
        - std::weak_ptr
        - std::unique_ptr

    + why?
        - avoid memory leak
        - avoid redundancy and complexity
        - enforce thread-safe

    + how?
        - using <memory> header file

*/

#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

int main()
{
    // shared_ptr
    {
        /*
        + pattern:
            std::shared_ptr<T> var(new T(), del);

        + creation:
            - using std::shared_ptr<T> var(new T()) constructor
            - using std::make_shared()
            - variant constructors
            * always create std::shared_ptr from the closest, the moment u need of the source
            * alway not use raw pointer to initialize std::shared_ptr

        + usage:
            - status: using use_count() to check
            - cast: static_shared_cast() -like thing
            - inheritance: std::enable_shared_from_this class

        + cautious:
            - cyclic reference
            - explicit wanna

        + concept:
            -

        */
        // create
        std::shared_ptr<std::string> sp1(new std::string("hello"),
                                         [](std::string* p)
                                         {
                                             std::cout << "delete " << *p << std::endl;
                                         });
        std::shared_ptr<std::string> sp2(new std::string("world"),
                                         [](std::string* p)
                                         {
                                             std::cout << "delete " << *p << std::endl;
                                         });

        // using like ordinary raw pointer
        (*sp1)[0] = 'H';
        (*sp2)[0] = 'W';
        // sp1->replace(0, 1, 'h');

        // pointer arithmetic supported?

        // pointer subscript operator[] supported?

        // put in container
        std::vector<std::shared_ptr<std::string>> v1;
        v1.push_back(sp2);
        v1.push_back(sp2);
        v1.push_back(sp1);
        v1.push_back(sp2);
        v1.push_back(sp1);
        // iterate over the container
        for(auto p: v1)
        {
            std::cout << *p << std::endl;
        }

        // reset std::shared_ptr
        // using reset() method
        // using constructor
        // using assign nullptr
        sp1 = nullptr;
        sp1.reset(); // deleter works

        // check status
        // using bool()
        // comparing to nullptr
        // using get() != nullptr
        if(sp1)
            std::cout << *sp1 << std::endl;
        else
            std::cout << "sp1 is empty" << std::endl;

        if(sp2.get() != nullptr)
            std::cout << *sp2 << std::endl;
        else
            std::cout << "sp2 is empty" << std::endl;

        if(sp1 != nullptr)
            std::cout << *sp1 << std::endl;
        else
            std::cout << "sp1 is empty" << std::endl;

        std::cout << *sp2 << std::endl;

    }

    return 0;
}
