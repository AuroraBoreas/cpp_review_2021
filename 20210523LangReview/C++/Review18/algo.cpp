#include "algo.h"

void scy::algo_permutation_heap(void)
{
    std::vector<int> v{2,1,3,99,99,99,0,-1,99,1};
    scy::print("original, v-> ", v);

    std::make_heap(v.begin(), v.end(), std::less<>{});
    scy::print("std::make_heap, v-> ", v);

    std::pop_heap(v.begin(), v.end(), std::less<>());
    scy::print("std::pop_heap, v-> ", v);

    v.push_back(42);
    std::push_heap(v.begin(), v.end());
    scy::print("std::push_back, v-> ", v);

    std::sort_heap(v.begin(), v.end());
    scy::print("std::sort_heap, v-> ", v);

    std::prev_permutation(v.begin(), v.end());
    scy::print("std::prev_permutation, v-> ", v);

    std::next_permutation(v.begin(), v.end());
    scy::print("std::next_permutation, v-> ", v);

}

void scy::algo_permutation_sort(void)
{
    std::vector<int> v{2,1,3,99,99,99,0,-1,99,1};
    scy::print("original, v-> ", v);

    std::sort(v.begin(), v.end());
    scy::print("std::sort, v-> ", v);

    std::partial_sort(v.begin(), v.begin()+3, v.end());
    scy::print("std::partial_sort, v-> ", v);

    std::partition(v.begin(), v.end(), scy::IsEven());
    scy::print("std::partition, v-> ", v);

    std::reverse(v.begin(), v.end());
    scy::print("std::reverse, v-> ", v);

    std::rotate(v.begin(), std::next(std::begin(v), 3), v.end());
    scy::print("std::rotate, v-> ", v);

    std::random_device rd;
    std::mt19937 mt{rd()};
    std::shuffle(v.begin(), v.end(), mt);
    scy::print("std::shuffle, v-> ", v);
}

void scy::algo_structure_changer(void)
{
    std::vector<int> v{2,1,3,99,99,99,0,-1,99,1};
    scy::print("original, v-> ", v);

    v.erase(std::remove(v.begin(), v.end(), 99), v.end());
    scy::print("std:remove, v-> ", v);

    v.erase(std::unique(v.begin(), v.end()), v.end());
    scy::print("std::unique, v-> ", v);
}

void scy::algo_mover(void)
{
    std::vector<int> v{2,1,3,99,99,99,0,-1,99,1};
    scy::print("original, v-> ", v);

    scy::oformat("std::copy, v-> ");
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    scy::newline();

    std::list<int> l;
    std::copy_backward(v.begin(), v.end(), l.end());
    scy::print("std::copy_backward, l-> ", l);

    std::vector<std::thread> vt;
    vt.emplace_back(scy::func, 1);
    vt.emplace_back(scy::func, 2);
    vt.emplace_back(scy::func, 3);
    std::list<std::thread> lt;
    std::move(vt.begin(), vt.end(), std::inserter(lt, lt.begin()));
    for(auto& t : lt) t.join();

    // std::move_backward
    std::vector<std::string> m {"hello", "world!"};
    std::vector<std::string> n {"zhang", "liang"};
    std::move_backward(m.begin(), m.end(), n.end());
    scy::print("std::move_backward, n-> ", n);

    std::swap_ranges(m.begin(), m.end(), n.begin());
    scy::print("std::swap_ranges, n-> ", n);
    scy::newline();
}

void scy::algo_value_modifier(void)
{
    std::vector<int> v{2,1,3,99,99,99,0,-1,99,1};
    scy::print("original, v-> ", v);

    std::fill(v.begin(), v.end(), 42);
    scy::print("std::fill, v-> ", v);

    std::iota(v.begin(), v.end(), 1);
    scy::print("std::iota, v-> ", v);

    std::srand(std::time(NULL));
    auto g = [](){ return std::rand()%30; };
    std::generate(v.begin(), v.end(), g);
    scy::print("std::generate, v-> ", v);

    v = {2,1,3,99,99,99,0,-1,99,1};
    std::replace(v.begin(), v.end(), 99, 42);
    scy::print("std::replace, v-> ", v);
}

void scy::algo_set(void)
{
    using container = std::set<int>;
    container A {1,2,3,4,5};
    container B {4,5,6,7,8};
    std::vector<int> S;

    std::set_union(A.begin(), A.end(), B.begin(), B.end(), std::back_inserter(S));
    scy::print("std::set_union, S-> ", S);

    S.clear();
    std::set_intersection(A.begin(), A.end(), B.begin(), B.end(), std::back_inserter(S));
    scy::print("std::set_intersection, S-> ", S);

    S.clear();
    std::set_difference(A.begin(), A.end(), B.begin(), B.end(), std::back_inserter(S));
    scy::print("std::set_difference, S-> ", S);

    S.clear();
    std::set_symmetric_difference(A.begin(), A.end(), B.begin(), B.end(), std::back_inserter(S));
    scy::print("std::set_symmetric_difference, S-> ", S);

    S.clear();
    std::merge(A.begin(), A.end(), B.begin(), B.end(), std::back_inserter(S));
    scy::print("std::merge, S-> ", S);

    bool rv = std::includes(A.begin(), A.end(), B.begin(), B.end());
    scy::oformat("std::includes, S-> ");
    rv
        ? std::cout << std::boolalpha << rv << std::endl
        : std::cout << std::boolalpha << rv << std::endl;
}

void scy::algo_query_value(void)
{
    std::vector<int> v{2,1,3,99,99,99,0,-1,99,1};
    scy::print("original, v-> ", v);

    // cai sapr
    scy::oformat("std::count, 99s-> ");
    int cnt = std::count(v.begin(), v.end(), 99);
    std::cout << cnt << std::endl;

    scy::oformat("std::accumulate, total-> ");
    double result = std::accumulate(v.begin(), v.end(), 0.0);
    std::cout << result << std::endl;

    scy::oformat("std::reduce, total-> ");
    std::cout << "not implemented yet" << std::endl;

    scy::oformat("std::adjancent_difference, v-> ");
    std::adjacent_difference(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    scy::newline();

    std::list<int> l{2,1,3,99,99,99,0,-1,99,1};
    scy::oformat("std::inner_product, ip-> ");
    result = std::inner_product(v.begin(), v.end(), l.begin(), 0.0);
    std::cout << result << std::endl;

    std::random_device rd;
    std::mt19937 mt{rd()};
    scy::oformat("std::sample, v-> ");
    std::sample(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "), 4, mt);
    scy::newline();

    scy::oformat("std::partial_sum, v-> ");
    std::partial_sum(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    scy::newline();
}

void scy::algo_query_property(void)
{
    std::vector<int> v{2,1,3,99,99,99,0,-1,99,1};
    scy::print("original, v-> ", v);

    // *_of
    bool rv = std::any_of(v.begin(), v.end(), scy::IsEven());
    scy::oformat("std::any_of, v-> ");
    std::cout << std::boolalpha << rv << std::endl;

    rv = std::all_of(v.begin(), v.end(), scy::IsEven());
    scy::oformat("std::all_of, v-> ");
    std::cout << std::boolalpha << rv << std::endl;

    rv = std::none_of(v.begin(), v.end(), scy::IsEven());
    scy::oformat("std::none_of, v-> ");
    std::cout << std::boolalpha << rv << std::endl;

    // find, unsorted
    // find_first_of, find_end
    auto it = std::find(v.begin(), v.end(), 3);
    scy::oformat("std::find, v-> ");
    (it != std::end(v))
        ? std::cout << *it << std::endl
        : std::cout << "[not found]\n";

    // search, sorted
    // binary_search, search_n
    std::string in = "Amet dolore duis id anim ut nulla non id.";
    std::string ou = "dolors";
    auto iter = std::search(ou.begin(), ou.end(), in.begin(), in.end());
    scy::oformat("std::search, v-> ");
    (iter != std::end(in))
        ? std::cout << *iter << std::endl
        : std::cout << "[not found]\n";

    // 2-ranges: mismatch, equal, lexicographical_compare
    rv = std::equal(in.begin(), in.end(), ou.begin());
    scy::oformat("std::equal, v-> ");
    std::cout << std::boolalpha << rv << std::endl;

    rv = std::lexicographical_compare(in.begin(), in.end(), ou.begin(), ou.end());
    scy::oformat("std::lexicographical_compare, v-> ");
    std::cout << std::boolalpha << rv << std::endl;

    auto [mi, ma] = std::mismatch(in.begin(), in.end(), ou.end());
    scy::oformat("std::mismatch, v-> ");
    (mi != std::end(in) && ma != std::end(in))
        ? std::cout << *mi << ", " << *ma << std::endl
        : std::cout << "[not found]\n";
}

void scy::algo_raw_memory(void)
{
    /*
    - uninitialized_default_construct
    - uninitialized_value_construct
    - uninitialized_copy
    - uninitialized_fill
    - uninitialized_move
    */

    std::cout << "raw memory -> nothing biggy" << std::endl;
}

void scy::algo_secret_rune(void)
{
    /*
    - *_if
    - stable_*
    - *_n
    - is_*
    - is_*_until
    - *_copy
    */

    std::cout << "secret runes -> nothing biggy" << std::endl;

}

void scy::algo_lone_island(void)
{
    std::vector<int> v{2,1,3,99,99,99,0,-1,99,1};
    scy::print("original, v-> ", v);

    scy::oformat("std::for_each, v-> ");
    std::for_each(v.begin(), v.end(), [](const auto& e){
                    std::cout << e << " ";
                  });
    scy::newline();

    scy::oformat("std::transform, v-> ");
    std::transform(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "), [](const auto& e){ return e*e; });
    scy::newline();
}

