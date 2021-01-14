#include <iostream>
#include <utility>
#include <functional>
#include <tuple>

using namespace std;

int main()
{
    int i = 0;
    // create a pair with functional::ref()
    auto p = std::make_pair(std::ref(i), std::ref(i));
    std::cout << std::get<0>(p) << " " << std::get<1>(p) << std::endl;
    ++p.first;
    ++p.second;
    std::cout << std::get<0>(p) << " " << std::get<1>(p) << std::endl;
    // another way to extract values out of pair:
    std::pair<char, char> q = std::make_pair('x', 'y');
    char c;
    std::tie(std::ignore, c) = q; // extract second value into c(ignore first one)
    std::cout << "second value: " << c << std::endl;





    return 0;
}
