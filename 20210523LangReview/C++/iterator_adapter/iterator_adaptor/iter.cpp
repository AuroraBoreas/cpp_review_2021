#include "iter.h"

void TS::stream_iterator(void)
{
    std::cout << "std::copy, pls input anything -> \n";
    std::list<std::string> l;
    std::copy(std::istream_iterator<std::string>(std::cin),
              std::istream_iterator<std::string>(),
              std::inserter(l, l.begin()));

    std::cout << "std::for_each, -> \n";
    std::for_each(l.begin(), l.end(), [](auto const& e){
                    std::cout << e << " ";
                  });
}

void TS::functor(void)
{
//    std::vector<int> v {1,2,3,4,5};
//    std::for_each(std::cbegin(v), std::cend(v), TS::print<10>);
    std::cout << std::endl;

    std::list<int> l;
    std::generate_n(std::back_inserter(l), 9, TS::B(10));
    TS::mprint("functor, l-> ", l);
    std::cout << std::endl;
}

void TS::function_adapter(void)
{
    std::vector<int> v(10);
    std::srand(std::time(nullptr));
    std::generate(v.begin(), v.end(), [](){ return std::rand()%42; });
    TS::mprint("original, v-> ", v);

    auto it = std::find_if(v.begin(), v.end(), std::bind2nd(std::greater<int>(), 42));
    (it != std::end(v))
        ? std::cout << "found -> " << *it << std::endl
        : std::cout << "[not found]\n";
}
