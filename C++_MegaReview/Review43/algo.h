#ifndef ALGO_H_INCLUDED
#define ALGO_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <cstddef>
#include <random>
#include <thread>
#include <vector>
#include <list>
#include <set>
#include <iterator>
#include <algorithm>
#include <numeric>

namespace TS
{
    inline void newline(void)
    {
        std::cout << std::endl;
    }

    inline void otopic(const std::string& s)
    {
        std::cout<< "\n=== " << s << " ===\n";
    }

    const int w{35};
    char const b(' ');
    inline void oformat(const std::string& s)
    {
        std::cout << std::setw(TS::w) << std::setfill(TS::b) << s;
    }

    inline void func(const int& e)
    {
        std::this_thread::sleep_for(std::chrono::seconds(e));
        std::cout << std::setw(TS::w) << std::setfill(TS::b) << "thread " << e << " ended\n";
    }

    auto print = [](const std::string& s, auto const& v){
        std::cout << std::setw(TS::w) << std::setfill(TS::b) << s;
        for(auto& e : v) std::cout << e << TS::b;
        TS::newline();
    };

    class IsEven
    {
    public:
        bool operator()(const int& e)
        {
            return e%2==0;
        }
    };

    void algo_permutation_heap(void);
    void algo_permuation_sort(void);
    void algo_structure_changer(void);
    void algo_mover(void);
    void algo_value_modifier(void);
    void algo_set(void);
    void algo_query_property(void);
    void algo_query_value(void);
    void algo_raw_memorry(void);
    void algo_secret_rune(void);
    void algo_lone_island(void);

} // namespace TS

#endif // ALGO_H_INCLUDED
