/*
C++, meta review

@ZL, 20210523

*/ 
#include "meta.h" 

namespace VarNS
{
    char x1 = 'a';
    short x2(69.96);
    int x3{42.24};
    long x4 = long(1234567890L);

    const float x5 = float{2.718281828F};
    static double x6 = 3.1415926;
    constexpr long double x7 = 3e8;

    extern bool x8 = true;

    template<class T>
    T pi = 3.1415926831319123120312192839128312;

    inline void const_correctness(void)
    {
        const int i = 69;
        int j = 42;

        const int* ptr1 = &i;
        int const *ptr2 = &i;

        int* const ptr3 = &j;
        const int* const ptr4 = &i;

        // ! exception: const T& var_name can accept rvalue
        const int& k = 69;
    }

} // namespace VarNS

namespace FuncNS
{
    // regular
    constexpr inline int fibonacci(int n)
    {
        return n < 2? 1 : fibonacci(n-1) + fibonacci(n-1);
    }
    constexpr int factorial(int n) noexcept
    {
        return n < 2? 1 : n * factorial(n-1);
    }

    // lambda
    const auto lambda = [](int n)->int{
        std::cout << "lambda says hello" << std::endl;
        return n * n;
    };

    // function pointer
    typedef void (*func_ptr)(char*);

    void message(char*), message_err(char*),
         message_low(char*), message_up(char*);

    void message(char* s)
    { std::cout << s << std::endl; }

    void message_err(char* s)
    { std::cerr << s << std::endl; }

    void message_low(char* s)
    {
        char c;
        for(; *s = '\0'; ++s)
        {
            c = std::tolower(*s); std::cout.put(c);
        }
        std::cout << '\n';
    }

    void message_up(char* s)
    {
        char c;
        for(; *s = '\0'; ++s)
        {
            c = std::toupper(*s); std::cout.put(c);
        }
        std::cout << '\n';
    }

    template<typename T, typename U>
    T sum(T x, U y)
    {
        return x + static_cast<T>(y);
    }

    // ByVal
    void addOne(int n)
    { n++; }
    // ByRef
    void plusOne(int& n)
    { ++n; }
    // ByPtr
    void addOne(int* p)
    { *p++; }

    class Animal
    {
        private:
            std::string m_name = "dummy";
            int m_age = 3;
        public:
            Animal(const std::string& name= "", const int age= 1)
            { m_name = name; m_age = age; }

            virtual ~Animal(){}
            
            const std::string& Name(void)
            { return m_name; }

            // ^ useless const
            // const std::string Name(void)
            // { return m_name; }

            // ^ args are changeable
            void hello(std::string& name)
            { std::cout << m_name << " says hello to " << name << std::endl; }

            // ^ args are not changeable
            void hello(const std::string& name)
            { std::cout << m_name << " says hello(no-const) to " << name << std::endl; }

            // ^ function itself is const; function wont change private members;
            void hello(std::string& name) const
            { std::cout << m_name << " says hello(const) to " << name << std::endl; }
    };
    
} // namespace FuncNS

namespace StatementNS
{
    inline void arithmetic(void) noexcept
    {
        int x{69}, y(42);

        std::cout << "x = " << x << ", y = " << y << "; x + y : " << (x + y) << std::endl;
        std::cout << "x = " << x << ", y = " << y << "; x - y : " << (x - y) << std::endl;
        std::cout << "x = " << x << ", y = " << y << "; x * y : " << (x * y) << std::endl;
        std::cout << "x = " << x << ", y = " << y << "; x / y : " << (x / y) << std::endl;
        std::cout << "x = " << x << ", y = " << y << "; x % y : " << (x % y) << std::endl;

        std::cout << "(postfix)++; x = " << x++ << std::endl; // 69; x = 70
        std::cout << "++(prefix); x = " << ++x << std::endl; // 71; x = 71
        std::cout << "(postfix)--; x = " << x-- << std::endl; // 71; x = 70
        std::cout << "--(prefix); x = " << --x << std::endl; // 69; x = 69
    }

    inline void relational(void) noexcept
    {
        int x{69}, y(42);

        std::cout << "x = " << x << ", y = " << y << "; x == y : " << (x == y) << std::endl;
        std::cout << "x = " << x << ", y = " << y << "; x != y : " << (x != y) << std::endl;
        std::cout << "x = " << x << ", y = " << y << "; x < y : " << (x < y) << std::endl;
        std::cout << "x = " << x << ", y = " << y << "; x <= y : " << (x <= y) << std::endl;
        std::cout << "x = " << x << ", y = " << y << "; x > y : " << (x > y) << std::endl;
        std::cout << "x = " << x << ", y = " << y << "; x >= y : " << (x >= y) << std::endl;
    }

    inline void logic(void) noexcept
    {
        int x{69}, y(42);

        std::cout << "x = " << x << ", y = " << y << "; !x : " << (!x) << std::endl;
        std::cout << "x = " << x << ", y = " << y << "; x && y : " << (x && y) << std::endl;
        std::cout << "x = " << x << ", y = " << y << "; x || y : " << (x || y) << std::endl;
    }

    inline void access(void) noexcept
    {
        FuncNS::Animal* cat = new FuncNS::Animal("kitty", 3);

        std::cout << (*cat).Name() << std::endl;
        cat->hello("TS");

        delete cat;
    }

    inline void bitwise(void) noexcept
    {
        int x{69}, y(42);

        std::cout << "x = " << x << ", y = " << y << "; ~x : " << (~x) << std::endl;
        int x1 = x << 2;
        std::cout << "x = " << x << ", y = " << y << "; x << 2 : " << (x1) << std::endl;
        x1 = x >> 2;
        std::cout << "x = " << x << ", y = " << y << "; x >> 2 : " << (x1) << std::endl;

        std::cout << "x = " << x << ", y = " << y << "; x & y : " << (x & y) << std::endl;
        std::cout << "x = " << x << ", y = " << y << "; x | y : " << (x | y) << std::endl;
        std::cout << "x = " << x << ", y = " << y << "; x ^ y : " << (x ^ y) << std::endl;
    }

    inline void assign(void) noexcept
    {
        int x1 = 69; // copy assignment operator
        int x2(42); // copy ctor
        int x3{32}; // list initialization
        int x4 = int(42); // ctor
        int x5 = int{42}; // list initialization

        std::cout << "copy assignment operator=, x1 = " << x1 << std::endl;
        std::cout << "copy ctor(), x2 = " << x2 << std::endl;
        std::cout << "list initialization, x3 = " << x3 << std::endl;
        std::cout << "ctor(), x4 = " << x4 << std::endl;
        std::cout << "list initialization, x5 = " << x5 << std::endl; 
    }

    inline void cast(void) noexcept
    {
        const int i = 10;
        int& j = const_cast<int&>(i);
        std::cout << "const_cast<>(), j = " << ++j << std::endl;

        const float f = (float)i;
        std::cout << "C-style cast, f = " << f << std::endl;

        const double& d = reinterpret_cast<double&>(j);
        std::cout << "reinterpret_cast, d = " << d << std::endl;

        class A {};
        class B: public A {};
        class C: public B {};

        C* pc = new C();
        B* pb = dynamic_cast<B*>(pc);
        A* pa = dynamic_cast<A*>(pc);

        delete pc;

        double n = static_cast<double>(69);
        std::cout << "static_cast, n = " << std::setprecision(2) << n << std::endl;
    }

    inline void opforstorage(void) noexcept
    {
        FuncNS::Animal *dog = new FuncNS::Animal{"doggy", 2};
        
        dog->hello("TS");

        delete dog;
    }

    inline void opforother(void) noexcept
    {
        std::cout << "skip this" << std::endl;
    }

} // namespace StatementNS

namespace ControlflowNS
{
    constexpr inline bool isLeapYear(int year) noexcept
    {
        return (year%4 == 0 && year%100 != 0)||(year%400 == 0);
    }

    constexpr inline bool setDate(int y, int m, int d) noexcept
    {
        if(y < 0) { return false; }
        if(m < 0 || m > 12) { return false; }
        if(d < 0 || d > 31) { return false; }

        switch (m)
        {
            case 2: if(isLeapYear(y))
                    { if(d > 29) { return false; } }
                    else
                    { if(d > 28) { return false; } }
                    break;
            case 4:
            case 6:
            case 9:
            case 11: if(d > 31) { return false; }
        }
        return true;
    }

    inline void zeroDivision(int a, int b)
    {
        double rv = 0.0;
        try
        {
            rv = (double)a / b;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            throw;
        }
        std::cout << rv << std::endl;
    }

} // namespace ControlflowNS

namespace LoopNS
{

    inline void array_notation()
    {
        int arr[] = {1, 2, 3, 4, 5, 6, 7};

        std::cout << "\n--- address ---" << std::endl;
        for(int i=0; i<7; ++i)
        {
            std::cout << *(arr + i) << ' ';
        }
        std::cout << std::endl;

        std::cout << "\n--- address ---" << std::endl;
        for(int i=0; i<7; ++i)
        {
            std::cout << i << ' ' << arr[i] << std::endl;
        }

        std::cout << "\n--- address ---" << std::endl;
        for(int i=0, *ptr = arr; i<7; ++i)
        {
            std::cout << *ptr << ' ';
            ptr++;
        }
        std::cout << std::endl;
    }

    inline void whileloop(void)
    {
        int arr[] = {1, 2, 3, 4, 5, 6, 7};

        std::cout << "\n--- while ---" << std::endl;
        int i = 0;
        while(i < 7)
        {
            std::cout << i << ' ' << arr[i];
            i++;
        }

        i = 7;
        std::cout << "\n--- do...while ---" << std::endl;
        do
        {
            std::cout << i << ' ' << arr[i];
            --i;
        } while(i >= 0);
        
        std::cout << std::endl;

    }

} // namespace LoopNS

namespace ClassNS
{
    class Person
    {
        private:
            std::string m_name;
            int m_age;
        
        public:
            Person()
            { m_name="noname"; m_age=0; }

            Person(const std::string& name, int age)
            {
                this->m_name = name; this->m_age = age;
            }

            Person& operator=(Person& p)
            {
                std::swap(m_name, p.Name());
                std::swap(m_age, p.Age());
                return *this;
            }

            Person(const Person& p)
            : m_name(p.m_name), m_age(p.m_age) {}

            virtual ~Person(){}

            std::string& Name(void) { return m_name; }
            int& Age(void)          { return m_age; }
            void Name(const std::string& val) { m_name = val; }
            void Age(int val)                 { m_age = val; }

            virtual std::string ToString(void) const
            {
                std::stringstream ss;
                ss << "\nname : " << m_name
                   << "\nage  : " << m_age;

                return ss.str();
            }

            friend std::ostream& operator<<(std::ostream& os, const Person& p)
            {
                os << p.ToString(); return os;
            }

            bool operator==(const Person& p) const
            {
                return this->ToString() == p.ToString();
            }

            // virtual void hello(const std::string& name) = 0;
    };

    class Teacher: public Person
    {
        private:
            std::string m_subject;

        public:
            Teacher(const std::string& name, int age, const std::string& subject)
            : Person(name, age)
            {
                m_subject = subject;
            }

            std::string ToString(void) const override
            {
                std::stringstream ss;
                ss << Person::ToString() << "\nsubject : " << m_subject;
                return ss.str();
            }
    };

    class Student: public Person
    {
        private:
            bool m_sex;
        public:
            Student(const std::string name, int age, bool sex)
            : Person(name, age)
            { m_sex = sex; }

            std::string ToString(void) const override
            {
                std::stringstream ss;
                ss << Person::ToString() << "\nsex : ";
                std::string s;
                s = m_sex ? "male" : "female";
                ss << s;                 
                return ss.str();
            }
    };
    
} // namespace ClassNS

namespace DataStructureNS
{
    // seq
    inline void std_array(void)
    {
        std::array<int, 3> arr{3 , 2, 1};

        std::cout << "\n--- std::array ---" << std::endl;
        std::sort(arr.begin(), arr.end());
        std::reverse_copy(arr.begin(), arr.end(), 
                        std::ostream_iterator<int>(std::cout, " "));

        std::cout << '\n';
        for(const auto& elem : arr)
        {
            std::cout << elem << ' ';
        }
        std::cout << '\n';
    }

    inline void std_vector(void) noexcept
    {
        std::cout << "\n--- std::vector ---" << std::endl;

        std::vector<int> v { 7, 5, 16, 8 };

        v.push_back(25);
        v.push_back(13);

        std::sort(v.begin(), v.end());
        std::for_each(v.begin(), v.end(), [](const auto& elem){
            std::cout << elem << ' ';
        });
        std::cout << std::endl;
    }

    inline void std_list(void) noexcept
    {
        std::cout << "\n--- std::list ---" << std::endl;
        std::list<int> l = { 7, 5, 16, 8 };
        l.push_front(25);
        l.push_back(13);

        auto it = std::find(l.begin(), l.end(), 16);
        if(it!= l.end())
        {
            l.insert(it, 42);
        }

        std::for_each(l.begin(), l.end(), [](const auto& elem){
            std::cout << elem << ' ';
        });
        std::cout << std::endl;
    }

    template<typename T>
    void print_forwardlist(T l)
    {
        std::for_each(l.begin(), l.end(), [](const auto& elem){
            std::cout << elem << ' ';
        });
        std::cout << std::endl;
    }
    inline void std_forwardlist(void) noexcept
    {
        std::cout << "\n--- std::forward_list ---" << std::endl;
        std::forward_list<std::string> words = {"the", "polygot", "is", "also", "cursed"};
        print_forwardlist(words);

        // words2 == words
        std::forward_list<std::string> words2(words.begin(), words.begin());
        print_forwardlist(words2);

        std::forward_list<std::string> words3(words);
        print_forwardlist(words3);

        std::forward_list<std::string> words4(5, "Mo");
        print_forwardlist(words4); 
    }

    inline void std_deque(void) noexcept
    {
        std::cout << "\n--- std::deque ---" << std::endl;
        std::deque<int> d = { 7, 5, 16, 8 };
        d.push_back(13);
        d.push_front(25);

        std::for_each(d.begin(), d.end(), [](const auto& elem){
            std::cout << elem << ' ';
        });
        std::cout << std::endl;

    }

    // adaptor
    inline void std_stack(void) noexcept
    {
        std::cout << "\n--- std::stack ---" << std::endl;
        std::stack<int> c1;
        c1.push(5);
        std::cout << c1.size() << '\n';
        std::stack<int> c2(c1);
        std::cout << c2.size() << '\n';
    }

    inline void std_queue(void) noexcept
    {
        std::cout << "\n--- std::queue ---" << std::endl;
        std::queue<int> q1;
        q1.push(5);
        std::cout << q1.size() << std::endl;
        std::queue<int> q2(q1);
        std::cout << q2.size() << std::endl;
    }

    template<typename T>
    void print_queue(T q)
    {
        while(!q.empty())
        {
            std::cout << q.top() << ' ';
            q.pop();
        }
        std::cout << std::endl;
    }

    inline void std_priorityqueue(void) noexcept
    {
        std::cout << "\n--- std::priority_queue ---" << std::endl;

        std::priority_queue<int> q;
        const auto data = {1,8,5,6,3,4,0,9,7,2};
        for(int n: data)
        {
            q.push(n);
        }
        print_queue(q);

        std::priority_queue<int, std::vector<int>, std::greater<int>> q2(data.begin(), data.end());
        print_queue(q2);

        auto cmp = [](int left, int right){ return (left ^ 1) < (right ^ 1); };
        std::priority_queue<int, std::vector<int>, decltype(cmp)> q3(cmp);
        for(int n: data)
            q3.push(n);
        
        print_queue(q3);

    }

    // associative
    template<typename T>
    void print_map(T m)
    {
        std::for_each(m.begin(), m.end(), [](const auto& it){
            std::cout << it.first << " = " << it.second << "; ";
        });
        std::cout << std::endl;
    }

    // 1...1
    inline void std_map(void) noexcept
    {
        std::cout << "\n--- std::map ---" << std::endl;
        std::map<std::string, int> m = {
            {"CPU", 10},
            {"RAM", 15},
            {"GPU", 20},
            {"SSD", 40},
        };

        print_map(m);

        m["CPU"] = 25;
        m["Monitor"] = 100;

        print_map(m);
    }

    void print_multimap(std::multimap<int, int> mm)
    {
        std::for_each(mm.begin(), mm.end(), [](const auto& it){
            std::cout << it.first << '\t' << it.second << '\n';
        });
        std::cout << std::endl;
    }

    // 1...N
    inline void std_multimap(void) noexcept
    {
        std::cout << "\n--- std::multimap ---" << std::endl;

        std::multimap<int, int> mm;
        // populate
        mm.insert(std::pair<int, int>(1, 40));
        mm.insert(std::pair<int, int>(2, 30));
        mm.insert(std::pair<int, int>(3, 60));
        mm.insert(std::pair<int, int>(6, 50));
        mm.insert(std::pair<int, int>(6, 10));

        print_multimap(mm);

        // insert
        mm.insert(std::pair<int, int>(4, 100));
        print_multimap(mm);
        // erase
        mm.erase(4);
        print_multimap(mm);

        std::cout << mm.lower_bound(6)->second << std::endl;
        std::cout << mm.upper_bound(6)->second << std::endl;
    }

    inline void std_set(void) noexcept
    {
        std::cout << "\n--- std::set ---" << std::endl;

        std::set<int> ss = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        for(auto it = ss.begin(); it != ss.end(); ++it)
        {
            if(*it % 2 == 1)
                ss.erase(it);
        }

        std::for_each(ss.begin(), ss.end(), [](const auto& it){
            std::cout << it << ' ';
        });
        std::cout << std::endl;
    }

    void print_multiset(const std::multiset<int>& ms)
    {
        for(auto elem : ms)
            std::cout << elem << ' ';
        std::cout << '\n';
    }

    inline void std_multiset(void) noexcept
    {
        std::cout << "\n--- std::multiset ---" << std::endl;
        std::multiset<int> a;
        a.insert(4);
        a.insert(3);
        a.insert(2);
        a.insert(1);

        print_multiset(a);
    }

    // unorder associative
    inline void std_unordered_map(void) noexcept
    {
        std::cout << "\n--- std::unordered_map ---" << std::endl;

        std::unordered_map<std::string, std::string> u = {
            {"RED", "#FF0000"},
            {"GREEN", "#00FF00"},
            {"BLUE", "#0000FF"},
        };

        for(const auto& n: u)
        {
            std::cout << "key: [" << n.first << "] value: [" << n.second << "]\n";
        }
    }

    inline void std_unordered_multimap(void) noexcept
    {
        std::cout << "\n--- std::unordered_multimap ---" << std::endl;
        std::unordered_multimap<std::string, std::string> umm;
        umm.emplace(std::make_pair<std::string, std::string>("a", "a"));
        umm.emplace(std::make_pair("b", "abcd"));
        umm.emplace("d", "d");

        for(const auto& [key, val] : umm)
        {
            std::cout << key << " : " << val << std::endl; 
        }
    }

    inline void std_unordered_set(void) noexcept
    {
        std::cout << "\n--- std::unordered_set ---" << std::endl;
        std::unordered_set<int> us = { 14, 1, 2, 13 };
        us.insert(25);
        us.insert(11);

        for(const auto& elem : us)
        {
            std::cout << elem << std::endl;
        }
    }

    inline void std_unordered_multiset(void) noexcept
    {
        std::cout << "\n--- std::unorder_multiset ---" << std::endl;
        std::unordered_multiset<int> numbers;
        numbers.insert(42);
        numbers.insert(69);

        for(const auto& elem: numbers)
        {
            std::cout << elem << std::endl;
        }
    }

} // namespace DataStructureNS

namespace AlgorithmNS
{
    inline void std_foreach(const std::list<int>& mylist)
    {
        std::for_each(mylist.begin(), mylist.end(), [](auto x){
            std::cout << x << ' ';
        });
        std::cout << std::endl;
    }

    inline void std_iterator_helper_function(void) noexcept
    {
        std::cout << "\n--- std::advance ---\n";
        std::forward_list<int> col1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        auto it1 = col1.begin();
        std::advance(it1, 4);
        std::cout << *it1 << std::endl;

        std::cout << "\n--- std::next ---\n";
        std::vector<int> col2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        auto it2 = col2.begin();
        auto it3 = std::next(it2, 4);
        std::cout << *it3 << std::endl;

        std::cout << "\n--- std::prev ---\n";
        std::list<int> col3 {1, 2, 3, 4, 5, 6, 7, 8, 9};
        auto it4 = col3.end();
        auto it5 = std::prev(it4, 4);
        std::cout << *it5 << std::endl;

        std::cout << "\n--- std::distance ---\n";
        std::array<int, 9> col4 {1, 2, 3, 4, 5, 6, 7, 8, 9};
        auto it6 = col4.begin();
        auto it7 = col4.end();
        std::cout << std::distance(it6, it7) << std::endl;

    }

    inline void std_iterator_adaptor(void) noexcept
    {
        std::cout << "\n--- std::istream_iterator ---\n";
        std::cout << "input some numbers(press non-numbers to stop) : ";

        std::vector<int> col2;
        std::istream_iterator<int> eos;
        std::istream_iterator<int> cin_it(std::cin);
        // for(; cin_it != eos; ++cin_it)
        // { col2.push_back(*cin_it); }

        auto back_iter = std::back_inserter(col2);
        std::copy(cin_it, eos, back_iter);

        std::cout << "\n--- std::ostream_iterator ---\n";
        std::ostream_iterator<int> cout_it(std::cout, " ");
        for(const int& n : col2)
            *cout_it = n;
        std::cout << std::endl;

        std::copy(col2.rbegin(), col2.rend(), cout_it);        
    }

    inline void std_heap(void)
    {
        std::vector<int> data = { 1, 2, 3, 4, 5, 6, 7, 8 };
        std::cout << "before make_heap, data : ";
        for(const auto& d:data) { std::cout << d << ' '; }
        std::cout << std::endl;
        std::make_heap(data.begin(), data.end());
        std::cout << "after make_heap, data : ";
        for(const auto& d:data) { std::cout << d << ' '; }
        std::cout << std::endl;
    }
} // namespace AlgorithmNS

void meta_review::variableDemo(void)
{
    /*
    @ variable
    ===
    * concept: box
    * pattern: TNV
    * feature:
        - primitive types(meta types)
            $ char
            $ short
            $ int
            $ long

            $ float
            $ double
            $ long double

            $ [x]byte
            $ boolean
            $ [x]decimal

        - type traits(reflect)
        - type conversion
            $ implicit vs explicit
            $ downcasting vs upcasting
            $ narrowing

        - initialization
            $ resource acquisition is initialization
            $ copy assignment operator
            $ copy ctor
            $ list initialization

        - ByVal, ByRef, ByPtr
            $ ByVal
                ~ lvalue
                ~ rvalue
            $ ByRef
                ~ r-ref
                ~ l-ref
            $ ByPtr
                ~ raw pointer
                ~ array
                ~ smart pointer

        - variable template
            $ generic

        - keywords
            $ storage
                ~ static
                ~ const
                    % const and variable
                    % const and pointer
                    % const and function
                ~ extern
                ~ register
                ~ auto
            
            $ compile time
                ~ constexpr
                ~ string literal

        - parameter vs argument
            $ argument means actual variable
            $ parameter means placeholder variable
    ===    
    */ 

    std::cout << "x1 = " << VarNS::x1 << std::endl;
    std::cout << "x2 = " << VarNS::x2 << std::endl;
    std::cout << "x3 = " << VarNS::x3 << std::endl;
    std::cout << "x4 = " << VarNS::x4 << std::endl;
    std::cout << "x5 = " << VarNS::x5 << std::endl;
    std::cout << "x6 = " << VarNS::x6 << std::endl;
    std::cout << "x7 = " << VarNS::x7 << std::endl;
    std::cout << "x8 = " << VarNS::x8 << std::endl;

    std::cout << "pi<short> : " << VarNS::pi<short> << std::endl;
    std::cout << "pi<int> : " << VarNS::pi<int> << std::endl;
    std::cout << "pi<long> : " << VarNS::pi<long> << std::endl;
    std::cout << "pi<float> : " << VarNS::pi<float> << std::endl;
    std::cout << "pi<double> : " << VarNS::pi<double> << std::endl;
    std::cout << "pi<long double> : " << VarNS::pi<long double> << std::endl;

}

void meta_review::functionDemo(void)
{
    /*
    @ function
    ===
    * concept: black box
    * pattern: TNP
    * feature:
        - regular
        - [x]anonymous
        - lambda
        - [x]immediate
        
        - function pointer
        - [x]decorator
        - [x]generator
        - [x]function in function
        - class in function

        - return_type
            $ ByVal
            $ ByRef
            $ ByPtr
        
        - func_name
            $ overload
            $ operator overload
            $ function template

        - args
            $ ByVal
            $ ByRef
            $ ByPtr

        - keywords
            $ inline vs macro
            $ const
            $ constexpr
            $ noexcept
            $ [[deprecated]]
    ===
    */ 

    std::cout << "fibonacci(5) : " << FuncNS::fibonacci(5) << std::endl;
    std::cout << "factorial(5) : " << FuncNS::factorial(5) << std::endl;
    std::cout << "lambda(2) : " << FuncNS::lambda(2) << std::endl;
    
    FuncNS::func_ptr myfuncptr[] { 
        FuncNS::message,
        FuncNS::message_err,
        FuncNS::message_up,
        FuncNS::message_low,
    };

    myfuncptr[0]("hello TS");

    int x = 69;
    std::cout << "before addOne(int n), x : " << x << std::endl;
    FuncNS::addOne(x);
    std::cout << "after addOne(int n), x : " << x << std::endl;

    x = 69;
    std::cout << "before plusOne(int& n), x : " << x << std::endl;
    FuncNS::plusOne(x);
    std::cout << "before plusOne(int& n), x : " << x << std::endl;

    x = 69;
    std::cout << "before addOne(int* p), x : " << x << std::endl;
    FuncNS::addOne(&x);
    std::cout << "before addOne(int* p), x : " << x << std::endl;
    
    FuncNS::Animal a1 = FuncNS::Animal();
    a1.hello("TS");
    
    const FuncNS::Animal a2 = FuncNS::Animal();
    std::string name = "TS";
    a2.hello(name);

    std::cout << "function template, sum(10, 20.0F)" << FuncNS::sum<int, float>(10, 20.0F) << std::endl;
    std::cout << "function template, sum(10, 20.0)" << FuncNS::sum<int, double>(10, 20.0) << std::endl;
    std::cout << "function template, sum(10, 20.0)" << FuncNS::sum<int, long double>(10, 20.0) << std::endl;
    std::cout << "function template, sum(10L, 20.0)" << FuncNS::sum<long, float>(10L, 20.0F) << std::endl;

}

void meta_review::statementDemo(void)
{
    /*
    @ statement
    ===
    * concept: link
    * pattern: symbol
    * feature:
        - arithmetic
            $ +, -, *, /, %
            $ (prefix)++, --; (postfix) ++, --

        - relational
            $ ==, !=
            $ >, >=
            $ <. <=

        - logic
            $ !
            $ &&
            $ ||

        - access
            $ (*ptr).
            $ ptr->

        - bitwise
            $ ~
            $ <<, >>
            $ &, |, ^

        - assign
            $ T var_name = val;
            $ T var_name(val);
            $ T var_name{val};
            $ T var_name = T(val);
            $ T var_name = T{val};

        - cast
            $ dynamic_cast
            $ static_cast
            $ const_cast
            $ reinterpret_cast
            $ C-style cast

        - op
            $ new
            $ delete

        - op
            $ .
            $ ,
            $ ;
            $ ()
            $ []
            $ {}
            $ <>

    ===
    */

    StatementNS::arithmetic();
    StatementNS::relational();
    StatementNS::logic();
    StatementNS::access();
    StatementNS::bitwise();
    StatementNS::assign();
    StatementNS::cast();
    StatementNS::opforstorage();
    StatementNS::opforother();
}

void meta_review::controlflowDemo(void)
{
    /*
    @ controlflow
    ===
    * concept: branch
    * pattern: branch
    * feature:
        - if...else if...else
        - switch...case...default
        - try...catch...
    ===
    
    */ 

    std::cout << "setDate(2021, 5, 23) is valid? " << std::boolalpha << ControlflowNS::setDate(2021, 5, 23) << std::endl;

    ControlflowNS::zeroDivision(10, 0);
}

void meta_review::loopDemo(void)
{
    /*
    @ loop
    ===
    * concept: circle
    * pattern: circle
    * feature:
        - for(;;)
        - for(:)
        - while
        - do...while 
    ===
    
    */ 

    LoopNS::array_notation();
    LoopNS::whileloop();

}

void meta_review::classDemo(void)
{
    /*
    @ class
    ===
    * concept: sim
    * pattern: sim
    * feature:
        - Abstract
        - Encapsulation
        - Inheritance
            $ is-a
            $ has-a

        - Polymorphism

    * structure:
        ^ default ctor
        ^ default dtor
        ^ copy ctor
        ^ copy assignment operator
        ^ move ctor
        ^ move assignment operator

    * principles:
        # SRP
        # OCP
        # LSP
        # ISP
        # DIP
        # Delimiter principle

    * keywords:
        $ default
        $ explicit (operator opol for type conversion)
        $ override
        $ virtual
        $ =0 (abstract vs concret; abstract class is not allowed to create obj in C++)
    
    * privilage:
        % private
        % public
        % friend

    * other:
        & class vs struct vs enum
        & class template
        & dependency injection
        & class in class? 
    ===
    */ 

    ClassNS::Person *p = new ClassNS::Person();
    ClassNS::Person p1 = ClassNS::Person("TS", 30);
    ClassNS::Person p2 = p1;
    ClassNS::Person p3(p1);
    delete p;

    std::cout << p->ToString() << std::endl;
    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;
    std::cout << p3 << std::endl;

    ClassNS::Teacher t1 = ClassNS::Teacher("TS", 30, "Japanese");
    ClassNS::Teacher t2 = ClassNS::Teacher("ZL", 35, "CS");
    std::cout << t1 << std::endl;
    std::cout << t2 << std::endl;
    std::cout << std::boolalpha << (t1==t2) << std::endl;

    ClassNS::Student s1{"TS", 30, true};
    ClassNS::Student s2("ZL", 35, false);
    std::cout << s1 << std::endl;
    std::cout << std::boolalpha << (s1 == s2) << std::endl;
}

void meta_review::datastructureDemo(void)
{
    /*
    @ datastructure
    ===
    * concept: container
    * pattern: container
    * feature:
        - seq
            $ array -> fixed size
            $ vector
            $ list
            $ forward_list
            $ deque

        - adaptor
            $ stack
            $ queue
            $ priority_queue

        - associative
            $ map
            $ multimap
            $ set
            $ multiset

        - unordered associative
            $ unordered_set
            $ unordered_multiset
            $ unordered_map
            $ unordered_multimap
    ===
    */ 

    DataStructureNS::std_array();
    DataStructureNS::std_vector();
    DataStructureNS::std_list();
    DataStructureNS::std_forwardlist();
    DataStructureNS::std_deque();
    
    DataStructureNS::std_stack();
    DataStructureNS::std_queue();
    DataStructureNS::std_priorityqueue();

    DataStructureNS::std_map();
    DataStructureNS::std_multimap();
    DataStructureNS::std_set();
    DataStructureNS::std_multiset();

    DataStructureNS::std_unordered_map();
    DataStructureNS::std_unordered_multimap();
    DataStructureNS::std_unordered_set();
    DataStructureNS::std_unordered_multiset();
}

void meta_review::algorithmDemo(void)
{
    /*
    @ algorithm
    ===
    * concept: calculation methods
    * pattern: world map of STL algorithm
    * feature:
        - permutation
        - queries
            ^ value queries
                $ count
                $ transform_inclusive_scan
                $ transform_exclusive_scan
                $ inclusive_scan
                $ exclusive_scan

            ^ property queries
            ^ search
            ^ 2-ranges properties

        - secrete runes
            $ _N
            $ _IF
            $ _COPY
            $ stable_
            $ is_
            $ is_*_until

        - movers
        - lone island
        - raw memory 
        - value modifier
        - structure changer
    ===
    */
    
    std::list<int> numbers { 1, 2, 3, 4, 5, 6, 7, 8 };
    AlgorithmNS::std_foreach(numbers);
    AlgorithmNS::std_iterator_helper_function();
    AlgorithmNS::std_iterator_adaptor();
    AlgorithmNS::std_heap();

}
