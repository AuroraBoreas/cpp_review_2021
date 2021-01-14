/*

pair comparison

+ definition
    // ==
    template<typename T1, typename T2>
    bool operator==(const pair<T1, T2>& x, const pair<T1, T2>& y) const
    { return (x.first == y.first && x.second == y.second); };
    // <
    template<typename T1, typename T2>
    bool operator<(const pair<T1, T2>& x, const pair<T1, T2>& y) const;

    */

#include <iostream>
#include <utility>
#include <functional>

using namespace std;

int main()
{
    int x1 = 1, y1 = 2,
        x2 = 3, y2 = 4;
    auto p1 = std::make_pair(x1, y1);
    std::pair<int, int> p2 = std::make_pair(std::cref(x2), std::cref(y2));

    if(p1 == p2);

    int tmp = std::cref(x1);
    std::cout << &tmp << std::endl;
    std::cout << &x1 << std::endl;

    return 0;
}
