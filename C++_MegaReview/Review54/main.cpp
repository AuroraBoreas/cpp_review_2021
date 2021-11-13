#include "algo.h"
#include "graphic.h"
#include "visitor.h"


int main()
{
//    CY::algo_permutation_heap();
//    CY::algo_permutation_sort();
//    CY::algo_structure_changer();
//    CY::algo_mover();
//    CY::algo_value_modifier();
//    CY::algo_set();
//    CY::algo_query_value();
//    CY::algo_query_property();
//    CY::algo_secret_rune();
//    CY::algo_raw_memory();
//    CY::algo_lone_island();

    Shape s = Shape();
    Dot d = Dot();
    Visitor v = Visitor();
    std::vector<Graphic*> g{&s, &d};
    std::for_each(g.begin(), g.end(),
                  [&](const Graphic* e)->void{ e->accept(v); });

    std::cin.get();

    return 0;
}
