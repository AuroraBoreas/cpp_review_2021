#include "algo.h"

int main()
{
    std::cout << "Hello world!" << std::endl;

    CY::otopic("permutation_heap");
    CY::algo_permutation_heap();
    CY::otopic("permutation_sort");
    CY::algo_permutation_sort();
    CY::otopic("structure_changer");
    CY::algo_structure_changer();
    CY::otopic("mover");
    CY::algo_mover();
    CY::otopic("value_modifier");
    CY::algo_value_modifier();
    CY::otopic("set");
    CY::algo_set();
    CY::otopic("query_value");
    CY::algo_query_value();
    CY::otopic("query_property");
    CY::algo_query_property();
    CY::otopic("raw_memory");
    CY::algo_raw_memory();
    CY::otopic("secret_rune");
    CY::algo_secret_rune();
    CY::otopic("lone_island");
    CY::algo_lone_island();


    std::cin.get();

    return 0;
}
