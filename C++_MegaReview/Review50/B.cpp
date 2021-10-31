#include "B.h"
#include "A.h"

void B::do_that(A* a) const
{
    std::cout << "in object B, do that..\n";
}
