/*

resource management

Because the copy constructor, destructor, and assignment operator are so tightly coupled,
the relationship among them has become known as the rule of three:
If your class needs a destructor, it probably needs a copy constructor and an assignment operator too.

*/

#include <iostream>
#include <algorithm>
#include <memory>
#include <string>
#include <tuple>
#include "vec.h"

using namespace std;

int main()
{
    std::string *p;
    std::size_t sz;
    std::tie(p, sz) = std::get_temporary_buffer<std::string>(4);

    std::uninitialized_fill(p, p+sz, "Example");

    for(std::string *i=p; i != p+sz; ++i)
    {
        std::cout << *i << '\n';
        i->~basic_string<char>(); // what does it mean? destructor?
    }
    std::return_temporary_buffer(p); // what does it mean?

    return 0;
}
