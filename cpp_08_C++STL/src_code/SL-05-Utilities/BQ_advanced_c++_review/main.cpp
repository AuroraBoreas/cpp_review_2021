#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cctype>
#include <tuple>
#include <utility>
#include <memory>

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

void message_error(char*), message(char*),
     message_up(char*), message_low(char*),
     (*funcPtr[])(char*) = { message_error, message, message_up, message_low };


int main()
{
    // logic constness and bitwise constness
    {
        std::cout << std::endl;
        BigVector v1;
        v1[0] = 42;  // write
        std::cout << v1.getCounter() << std::endl;
        std::cout << v1[0] << std::endl;
        std::cout << v1.getCounter() << std::endl;

    }

    // compiler generated funcs
    {
        std::cout << std::endl;
        Dog d1; // OK. using default constructor
        Dog d2("Henry", 3); // OK
        Dog d3; // OK as well
        // d3 = d2; // not OK. as copy assignment operator is deleted
        // d3(d2); // not OK too. as copy constructor is deleted too
    }

    // constness
    {
        std::cout << std::endl;
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

    // var interpreting methods
    {
        std::cout << std::endl;
        char prompt[] = "Please enter your choice "
                        "btwn (1-3), quit with -1: ";
        char msg[] = "bonjour tout le monde";
        char err[] = "error out";

        int i;
        std::cout << prompt << std::endl;
        while(std::cin >> i && i != -1)
        {
            if(i<0 || i>3)
            {
                (*funcPtr[0])(err);
                std::cerr << "index out of range" << std::endl;
                break;
            }
            else
            {
                (*funcPtr[i])(msg);
            }
            std::cout << prompt << std::endl;
        }
    }

    // pair
    {
        /*
            pair<> class template
        - what:
            binds two elements together, and treats it as one

            ```c++
            namespace std
            {
                template<typename T, typename U>
                class pair
                {
                    ...
                    // not explicit keyword constrains these constructors.
                    public:
                        pair(const T& x, const U& y);
                        pair& operator=(const pair& p);

                        pair(T&& x, U&& y);
                        pair&& operator=(T&& x, U&& y);
                }
            }

            ```

        - why:
            two as one
        - how:
            using pair<> class constructor;
            using std::make_pair() function;
        - extract values from a pair?
            using std::get<index>(p)
            using std::make_pair(std::ref(x), std::ref(y)) = p;
            using std::tie(x, y) = p; // generated Ref x, y automatically
        */

        std::pair<int, float> p1{42, 3.14};
        std::cout << std::get<0>(p1) << std::endl; // 42
        std::cout << std::endl;

        auto p2 = std::make_pair<char, std::string>('c', "hello world!");
        char c; std::string s;
        std::make_pair(std::ref(c), std::ref(s)) = p2;
        std::cout << c << ", " << s << std::endl;
        std::tie(c, s) = p2;
        std::cout << c << ", " << s << std::endl;

    }

    // tuple
    {
        /*
            tuple
        - what:
            tuple is an extended concept of pair<> class template.

            ```c++
            namespace std
            {
                template<typename... Args>
                class tuple
                {
                    ...

                    // explicit keyword constrains constructor. implicit conversion included initializer_list is not allowed
                    public:
                        explicit tuple(const Args&...);
                        explicit tuple(Args&&...);
                }

            }

            ```
        - why:
            why not?
        - how:
            similar with pair<> class template,
            using std::tuple<T>();
            using std::make_tuple<T>();
        - how to extract values from a tuple
            same as pair<> class template,
        - additional methods
            using std::tuple_element<tupletype>::value to get size;
            using std::tuple_element<index, tupletype>::type to get type;
            using std::tuple_cat() to combine;

        */

        std::tuple<char, short, int, long, float, double, std::string> t1{ 'a', 11, 42, 999L, 3.14f, 2.718281828, "hello" };
        auto t2 = std::tuple_cat(std::make_pair(42, 3.14),
                       std::make_tuple(2.718, "hello world"));
    }

    // smart pointers
    {
        /*
            smart pointers
        - shared_ptr
            what: auto track all pointers to the same obj;
                  auto delete when no one point to the same obj any more;
            ownership: many to one

            - weak_ptr, bad_weak_ptr etc are also provided

        - unique_ptr
            what: exact one and only one pointer to an obj
            ownership: one to one

        - comparing with "raw" pointers


        */
        int i = 42;
        // shared_ptr<int*> p(new obj());
        std::shared_ptr<int> p1(new int(42));
        std::shared_ptr<int> p2(new int(11));

        //
        std::cout << *p1 << std::endl;


    }



    return 0;
}

void message_error(char* s)
{
    std::cerr << s << std::endl; // display error message
}

void message(char* s)
{
    std::cout << s << std::endl;
}

void message_up(char* s)
{
    char c;
    for(; *s != '\0'; ++s)
        c = std::toupper(*s); std::cout.put(c);
}

void message_low(char* s)
{
    char c;
    for(; *s != '\0'; ++s)
        c = std::tolower(*s); std::cout.put(c);
}
