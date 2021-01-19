#include <iostream>
#include <memory> // for std::unique_ptr
#include <string> // for std::string

class A
{
public:
    A(int x=1, int y=1)
    {
        // ...;
    }
};

/*

the following function is the source of trouble.
- may forget to delete ptr
- during operator, exceptions cause program to terminate then `delete ptr;` statement is not executed

*/
//void f()    // version 01
//{
//    A* ptr = new A;
//    //...; operation
//    delete ptr;
//}

/*
the following version 02 f()
tries to avoid memory leak using try...catch...

it works, but its code gets more complicated and redundant.
*/
//void f()    // version 02
//{
//    A* ptr = new A;
//    try
//    {
//        // ...; operation
//    }
//    catch(...)
//    {
//        delete ptr;
//        throw;
//    }
//
//    delete ptr;
//}

/*
version 03 f()
*/
void f()
{
    std::unique_ptr<A> ptr(new A);
    // ...; operation
}

//class B // version 01, possible memory leak
//{
//private:
//    A* ptr1;
//    A* ptr2;
//public:
//    // parameterized constructor
//    B(int val1, int val2)
//    : ptr1(new A(val1)), ptr2(new A(val2)){}
//    // copy constructor
//    B(const B& b)
//    : ptr1(new A(*b.ptr1)), ptr2(new A(*b.ptr2)){}
//    // copy assignment operator
//    B& operator=(const B& b)
//    {
//        *ptr1 = *b.ptr1;
//        *ptr2 = *b.ptr2;
//        return *this;
//    }
//
//    ~B() { delete ptr1; delete ptr2; }
//
//};

class B // version 02, using unique_ptr to avoid possible memory leak
{
private:
    std::unique_ptr<A> ptr1;
    std::unique_ptr<A> ptr2;
public:
    B(int val1, int val2)
    : ptr1(new A(val1)), ptr2(new A(val2)){}
    B(const B& b)
    : ptr1(new A(*b.ptr1)), ptr2(new A(*b.ptr2)){}
    B& operator=(const B& b)
    {
        *ptr1 = *b.ptr1;
        *ptr2 = *b.ptr2;
        return *this;
    }
    // no destructor necessary
};

int main()
{
    // unique_ptr basic
    {
        /*
        purpose of class unique_ptr
        - Acquire some resources
        - Perform some operations
        - Free the acquired resources
        */

        // create a unique_ptr
        std::unique_ptr<std::string> p1(new std::string("SCY"));
        // unique_ptr has much same interface as an ordinary pointer
        (*p1)[0] = 'N';
        p1->append(" love U");
        std::cout << *p1 << std::endl;
        // differs with shared_ptr, pointer arithmetic are not supported
        // u MUST initialize the unique_ptr directly
        // std::unique_ptr<int> p2 = new int; // ERROR. disallowed
        std::unique_ptr<int> p3(new int); // OK
        // unique_ptr can be empty
        std::unique_ptr<std::string> p4; // empty. nullptr
        // assign nullptr
        // or reset() to make unique_ptr empty
        p4 = nullptr;
        p4.reset();

        // using release() to give up ownership of an obj
        std::unique_ptr<std::string> p5(new std::string("SCY"));
        // ...; operation
        std::string* p6 = p5.release(); // p5 gives up ownership, p6 yields ownership

        // check whether a unique_ptr owns an obj
        // by calling bool()
        // or comparing with nullptr
        // or unique_ptr.get()
        if(p5)
        {
            std::cout << *p5 << std::endl;
        }
        else
            std::cout << "p5 is empty" << std::endl;

        if(p5 != nullptr)
            std::cout << *p5 << std::endl;
        else
            std::cout << "p5 is empty" << std::endl;

        if(p5.get() != nullptr)
            std::cout << *p5 << std::endl;
        else
            std::cout << "p5 is empty" << std::endl;

    }

    // unique_ptr ownership transferring
    // using std::move(). it is eviction the previous owner out of house
    // using unique_ptr.release()
    {
        std::string* p1 = new std::string("halo");
        std::unique_ptr<std::string> p2(p1);
        // std::unique_ptr<std::string> p3(p1); // not OK. compiles. runtime error..
        // as a programmer, u have to handle it by yourself.

        // u can't copy or assign a unique_ptr if u use the ordinary copy semantics
        // using std::move() instead
        std::unique_ptr<std::string> p4(std::move(p2));
        if(p2)
            std::cout << *p2 << std::endl;
        else
            std::cout << "p2 is empty" << std::endl;

    }

    // unique_ptr as member
    {
        // see class B version 01 vs version 02
    }

    // dealing with arrays
    // (105)
    {

    }

    return 0;
}
