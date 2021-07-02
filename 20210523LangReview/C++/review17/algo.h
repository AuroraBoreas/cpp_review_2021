#ifndef ALGO_H_INCLUDED
#define ALGO_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <string>

#include <cctype>
#include <cstdlib>
#include <cstddef>

#include <ctime>
#include <chrono>
#include <thread>
#include <random>

#include <set>
#include <vector>
#include <list>

#include <iterator>
#include <algorithm>
#include <numeric>

namespace scy
{
    inline void newline(void) { std::cout << std::endl; }
    inline void o(const std::string& s)
    { std::cout << "\n=== " << s << " ===\n"; }

    const int w  = 35;
    const char b = ' ';

    inline void format(const std::string& s)
    { std::cout << std::setw(scy::w) << std::setfill(scy::b) << s; }

    inline void tf(bool rv)
    {
        rv
            ? std::cout << "true" << std::endl
            : std::cout << "false" << std::endl;
    }

    auto print = [](const std::string& c, auto const& v){
        std::cout << std::setw(scy::w) << std::setfill(scy::b) << c;
        for(auto& e : v) {
            std::cout << e << scy::b;
        }
        scy::newline();
    };

    inline void func(const int& i)
    {
        std::this_thread::sleep_for(std::chrono::seconds(i));
        std::cout << std::setw(scy::w) << std::setfill(scy::b) << "thread " << i << " end" << std::endl;
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
