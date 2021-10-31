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
#include <thread>
#include <functional>
#include <chrono>
#include <set>
#include <list>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>

namespace TS
{
    inline void newline(void)
    {
        std::cout << std::endl;
    }
    inline void otopic(const std::string& s)
    {
        std::cout << s << std::endl;
    }
}; // namespace TS

#endif // ALGO_H_INCLUDED
