#include <iostream>
#include <tuple>
#include <utility>
#include <vector>
#include <forward_list>
#include <memory>
#include <cstdlib>
#include <string>
#include "date.h"

typedef std::vector<int> VI;
typedef std::forward_list<Date> LD;
typedef LD::const_iterator LDIter;

int main()
{
    // containers: forward_list
    std::srand(time(NULL));
    LD dates{ Date(), Date(2021,1,14), Date(2022,1,14) };
    // populate containers
    unsigned m = 10, i = 0;
    VI v;
    while(i<m)
    {
        dates.push_front(Date(2021, std::rand()%12, std::rand()%30));
        v.push_back(std::rand()% 2050);
        i++;
    }
    // forward ptr
    LDIter dPtr = dates.begin();
    std::advance(dPtr, 2);
    std::cout << "size = " << (dates.max_size()) << std::endl;
    for(; dPtr != dates.end(); ++dPtr)
    {
        std::cout << *dPtr << std::endl;
    }
    for(int i=0; i<v.size(); ++i)
    {
        std::cout << v[i] << std::endl;
    }

    // class templates: pair, tuple
    // create and initialize
    std::pair<int, float> p{1, 3.14};
    std::tuple<char, short, int, long, bool, float, double, std::string>
    tu{'a', 1, 3145, 9999L, true, 2.178f, 3.1415926, "bonjour tout le monde"};
    // member access
    std::get<0>(p);
    std::get<1>(tu);
    // approachable also via std::make_pair(), std::make_tuple()
    auto p1 = std::make_pair<int, std::string>(2, "3.214");
    auto t2 = std::make_tuple<double, long>(2.718, 1000L);
    std::get<0>(p1);
    std::get<1>(t2);

    return 0;
}
