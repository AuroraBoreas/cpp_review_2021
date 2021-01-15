/*

SL tuple

(73)

@ZL, 20210114

+ how to extract values from tuple back to vars
    - using std::make_tuple();
    - using std::tie() + std::ignore;

+ tuple implementation review
    template<typename... Types>
    class tuple
    {
        public:
            explicit tuple(const Types&...);
            template<typename... UTypes>
            explicit tuple(UTypes&&...);
    }

    * we can tell implicit type conversion is NOT allowed during initialization
    * due to the reason above, u can't pass an initializer list where a tuple is expected
    * u have to explicitly convert the initial values into tuple then u can pass it

+ additional tuple features
    - tuple_size<tupletype>::value
    - tuple_element<index, tupletype>::type
    - tuple_cat(); this function combines any form of tuples, even pair<>s

+ how to loop through a tuple?
    - first thought: using std::tuple_size<tupletype>::value to get the number of elements , then using std::get<index>(tuple) to extract
    - after view doc, there is an easy way to do this in SL
    - first thought is not working :p
    - it turns out that the book also concern it and give a solution :O
        - move to next project to demonstrate
*/

#include <iostream>
#include <tuple>
#include <string>
#include <memory>
#include <vector>

int main()
{
    // when modifying an existing value via a tuple
    std::string s;
    auto x = std::make_tuple(s);
    std::get<0>(x) = "my value";    // modifies x but not s;
    std::cout << s << std::endl;

    auto y = std::make_tuple(std::ref(s));
    std::get<0>(y) = "my value";    // modifies y, and also s;
    std::cout << s << std::endl;

    // extract values of a tuple back to some vars
    std::tuple<int, float, std::string> t(77, 1.1, "more light");
    int i;
    float f;
    std::string str;
    std::make_tuple(std::ref(i), std::ref(f), std::ref(str)) = t;

    // more convenient way by using std::tie()
    std::tie(i, f, str) = t; // creates a tuple with references to i, f, and str

    // if u dont wanna some elements, using std::ignore() to ignore them
    std::tie(i, std::ignore, str) = t;

    std::tuple<int, double> t1(42, 3.14); // OK
    std::tuple<int, double> t2{42, 3.14}; // OK
    // std::tuple<int, double> t3 = {42, 3.14}; // not OK. rvalue is a non-type brace obj.

    // pass or impasse: can pass or can't pass an initializer_list to tuple?
    // std::vector<std::tuple<int, double>> v1{{1, 1.0},{2, 2.0}}; // not OK
    // make it explicit as tuple template class constructors requires
    std::vector<std::tuple<int, double>> v2 { std::make_tuple(1, 1.0),
                                              std::make_tuple(2, 2.0) }; // OK
    // comparing with pair template
    std::vector<std::pair<int, float>> p1{{1, 1.0}, {2, 2.0}}; // OK
    // u may make it explicit too
    std::vector<std::pair<int, float>> p2{ std::make_pair(1, 1.9),
                                           std::make_pair(2, 2.9) }; // OK


    // tuple_size
    typedef std::tuple<int, float, std::string> TupleType;
    auto value1 = std::tuple_size<TupleType>::value;
    std::cout << value1 << std::endl;
    // tuple_element
    std::tuple_element<1, TupleType>::type type1;
    std::cout << type1 << std::endl;
    // tuple concatenate
    int n;
    auto tt = std::tuple_cat(std::make_tuple(42,7.7,"hello"),
                             std::tie(n));

    // loop through a tuple
    auto _s = std::tuple_size<decltype(tt)>::value;
    for(int index=0; index<_s; ++i)
        //std::cout << std::get<index>(tt) << std::endl;  // not OK. std::get<index>(tuple) is a constexpr...



    return 0;
}
