#ifndef ITER_H_INCLUDED
#define ITER_H_INCLUDED

#include <string>

#include <ctime>
#include <random>

#include <list>
#include <vector>

#include <functional>

#include <iostream>
#include <iterator>
#include <algorithm>

namespace TS
{
    template<class T>
    class A
    {
    public:
        void operator()(T arg)
        {
            std::cout << arg << " ";
            std::cout << std::endl;
        }
    };

    template<int val>
    void print(int const& i)
    {
        std::cout << (i + val) << " ";
    }

    auto mprint = [](const std::string& c, auto const& v){
        std::cout << c;
        for(auto& e : v) {
            std::cout << e << " ";
        }
        std::cout << std::endl;
    };

    class B
    {
    private:
        int m_val;
    public:
        B(int initVal)
        : m_val(initVal)
        {}

        int operator()()
        { return m_val++; }
    };

    void stream_iterator(void);
    void functor(void);
    void function_adapter(void);
}

#endif // ITER_H_INCLUDED
