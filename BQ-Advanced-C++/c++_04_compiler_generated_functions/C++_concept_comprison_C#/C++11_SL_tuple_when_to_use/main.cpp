#include <iostream>
#include <tuple>
#include <string>
#include <map>
#include <unordered_map>

struct Person { std::string name; int age; } p;
std::tuple<std::string, int> t;

std::tuple<std::string, int> GetNameAge(void)
{
    return std::make_tuple("ZL", 34);
}

int main()
{
    // test
    {
        std::cout << p.name         << ", " << p.age          << std::endl;
        std::cout << std::get<0>(t) << ", " << std::get<1>(t) << std::endl;
    }

    // when to use
    {
        /*

        + usage
            >> as a one-time only structure to transfer a group of data;
            >> comparison of tuples
            >> multi index map

        */
        std::tuple<std::string, int> t1 = GetNameAge();
        std::cout << std::get<0>(t1) << ", " << std::get<1>(t1) << std::endl;


        std::tuple<int, int, int> time1, time2; // hours, minutes, seconds
        time1 = {16, 35, 10};
        time2 = {8, 0, 0};
        if(time1 > time2)
            std::cout << "time 1 is later time" << std::endl;

        std::map<std::tuple<int, char, float>, std::string> m;
        m[std::make_tuple(2, 'a', 2.3)] = "Faith moves mountains";
    }


    return 0;
}
