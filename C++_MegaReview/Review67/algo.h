#pragma once
#ifndef ALGO_H_INCLUDED
#define ALGO_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <cstddef>
#include <ctime>
#include <chrono>
#include <thread>
#include <random>
#include <vector>
#include <list>
#include <set>
#include <functional>
#include <iterator>
#include <numeric>
#include <algorithm>

namespace cy
{

    inline void newline(void)
    { std::cout << std::endl; }

    inline void otopic(const std::string& s)
    {
        std::cout << "\n=== " << s << " ===" << std::endl;
    }

    const int w{35};
    char const b(' ');
    inline void oformat(const std::string& s)
    {
        std::cout << std::setw(cy::w) << std::setfill(cy::b) << s;
    }

    auto print = [](const std::string& s, auto const& v){
        cy::oformat(s);
        for(auto& e : v) std::cout << e << cy::b;
        cy::newline();
    };

    class IsEven
    {
    public:
        bool operator()(const int& e)
        {
            return (e % 2) == 0;
        }
    }; // class IsEven

    inline void func(const int& e)
    {
        std::this_thread::sleep_for(std::chrono::seconds(e));
        cy::oformat("thread ");
        std::cout << e << " ended;" << std::endl;
    }

    void algo_permutation_heap(void);
    void algo_permutation_sort(void);
    void algo_structure_changer(void);
    void algo_mover(void);
    void algo_value_modification(void);
    void algo_set(void);
    void algo_query_value(void);
    void algo_query_property(void);
    void algo_raw_memory(void);
    void algo_secret_rune(void);
    void algo_lone_island(void);
}

#endif // ALGO_H_INCLUDED
