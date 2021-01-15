#ifndef PRINTTUPLE_HPP_INCLUDED
#define PRINTTUPLE_HPP_INCLUDED

#include <iostream>
#include <tuple>

template<int IDX, int MAX, typename... Args>
struct PRINT_TUPLE
{
    static void print(std::ostream& os, const std::tuple<Args...>& t)
    {
        os << std::get<IDX>(t) << (IDX+1 == MAX? "": ",");
        PRINT_TUPLE<IDX+1, MAX, Args...>::print(os, t);
    }
};

// partial specialization to end recursion
template<int MAX, typename... Args>
struct PRINT_TUPLE<MAX, MAX, Args...>
{
    static void print(std::ostream& os, const std::tuple<Args...>& t)
    {}
};

// finally op ol global function template to print tuple
template<typename... Args>
std::ostream& operator<<(std::ostream& os, const std::tuple<Args...>& t)
{
    os << "[";
    PRINT_TUPLE<0, sizeof...(Args), Args...>::print(os, t);
    return os << "]";
}


#endif // PRINTTUPLE_HPP_INCLUDED
