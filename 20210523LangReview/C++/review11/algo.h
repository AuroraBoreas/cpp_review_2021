#ifndef ALGO_H_INCLUDED
#define ALGO_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <string>

#include <cctype>
#include <ctime>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <random>

#include <vector>
#include <list>
#include <set>

#include <iterator>
#include <numeric>
#include <algorithm>
#include <execution> // C++>=20?

namespace TS
{
    const std::string b = " ";
    int const w = 35;
    auto print = [](const std::string& c, auto const& v){
        std::cout << c;
        for(auto& e : v) {
            std::cout << std::setw(TS::w) << std::setfill(TS::b) << e << TS::b:
        }
    };

    inline void func(int const& i)
    {
        std::this_thread::sleep_for(std::chrono::seconds(i));
        std::cout << "thread " << i << " ended" << std::endl;
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

#endif