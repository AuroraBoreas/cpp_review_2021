/*
C++, meta review

@ZL, 20210523

*/ 
#include "meta.h"

int main()
{
    std::cout << "\n=== variable === " << std::endl;
    meta_review::variableDemo();

    std::cout << "\n=== function === " << std::endl;
    meta_review::functionDemo();

    std::cout << "\n=== statement === " << std::endl;
    meta_review::statementDemo();

    std::cout << "\n=== controlflow === " << std::endl;
    meta_review::controlflowDemo();

    std::cout << "\n=== loop === " << std::endl;
    meta_review::loopDemo();

    std::cout << "\n=== class === " << std::endl;
    meta_review::classDemo();

    std::cout << "\n=== datastructure === " << std::endl;
    meta_review::datastructureDemo();

    std::cout << "\n=== algorithm === " << std::endl;
    meta_review::algorithmDemo();

    return 0;
}