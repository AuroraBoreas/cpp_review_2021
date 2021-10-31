#ifndef ALGO_H_INCLUDED
#define ALGO_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cctype>
#include <ctime>
#include <chrono>
#include <random>
#include <thread>
#include <list>
#include <vector>
#include <set>
#include <numeric>
#include <iterator>
#include <algorithm>
#include <memory>

namespace TS
{
    inline void newline(void)
    {
        std::cout << std::endl;
    }

    inline void otopic(const std::string& s)
    {
        std::cout << "\n=== " << s << " ===\n";
    }

    int const w(35);
    char const b{' '};
    inline void oformat(const std::string& s)
    {
        std::cout << std::setw(TS::w) << std::setfill(TS::b) << s;
    }

    auto print = [](const std::string& s, auto const& v){
        std::cout << std::setw(TS::w) << std::setfill(TS::b) << s;
        for(auto& e : v) std::cout << e << TS::b;
        TS::newline();
    };

    inline void func(const int& i)
    {
        std::this_thread::sleep_for(std::chrono::seconds(i));
        std::cout << std::setw(TS::w) << std::setfill(TS::b) << "thread " << i << " ended\n";
    }

    class IsEven
    {
    public:
        bool operator()(const int& e)
        {
            return e%2==0;
        }
    }; // class IsEven

    void algo_permutation_heap(void);
    void algo_permuation_sort(void);
    void algo_structure_changer(void);
    void algo_mover(void);
    void algo_value_modifier(void);
    void algo_set(void);
    void algo_query_value(void);
    void algo_query_property(void);
    void algo_raw_memory(void);
    void algo_secret_rune(void);
    void algo_lone_island(void);
}; // namespace TS

#endif // ALGO_H_INCLUDED
