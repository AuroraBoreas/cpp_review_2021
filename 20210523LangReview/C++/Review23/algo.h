#ifndef ALGO_H_INCLUDED
#define ALGO_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstddef>
#include <cctype>

#include <ctime>
#include <chrono>
#include <thread>
#include <thread>
#include <random>

#include <vector>
#include <list>
#include <set>

#include <iterator>
#include <algorithm>
#include <numeric>

namespace TS
{
    inline void newline(void) { std::cout << std::endl; }

    inline void otopic(const std::string& s)
    { std::cout << "\n=== " << s << " ===\n"; }

    const unsigned w(35);
    const char b{' '};
    inline void oformat(const std::string& s)
    { std::cout << std::setw(TS::w) << std::setfill(TS::b) << s; }

    auto print = [](const std::string& c, auto const& v){
        std::cout << std::setw(TS::w) << std::setfill(TS::b) << c;
        for(auto& e : v){
            std::cout << e << TS::b;
        }
        TS::newline();
    };

    template<typename T>
    class IsEven
    {
    public:
        bool operator()(const T& e)
        { return e%2==0; }
    };

    inline void func(const int& i)
    {
        std::this_thread::sleep_for(std::chrono::seconds(i));
        std::cout << std::setw(TS::w) << std::setfill(TS::b) << "thread " << i << " ended" << std::endl;
    }

    void algo_permutation_heap(void);
    void algo_permutation_sort(void);
    void algo_structure_changer(void);
    void algo_mover(void);
    void algo_value_modifier(void);
    void algo_set(void);
    void algo_query_property(void);
    void algo_query_value(void);
    void algo_raw_memory(void);
    void algo_secret_rune(void);
    void algo_lone_island(void);
}

#endif // ALGO_H_INCLUDED
