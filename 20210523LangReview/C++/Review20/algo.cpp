#include "algo.h"

void TS::algo_permutation_heap(void)
{
    std::vector<int> v{2,1,3,99,99,99,0,-1,99,1};
    TS::print("original, v-> ", v);

    std::make_heap(v.begin(), v.end(), std::greater<>{});
    TS::print("std::make_heap, v-> ", v);

    std::pop_heap(std::begin(v), std::end(v), std::greater<>());
    TS::print("std::pop_heap, v-> ", v);

    v.push_back(42);
    std::push_heap(v.begin(), v.end(), std::less<>{});
    TS::print("std::push_heap, v-> ", v);

    std::sort_heap(v.begin(), v.end(), std::less<>());
    TS::print("std::sort_heap, v-> ", v);

    std::prev_permutation(v.begin(), v.end());
    TS::print("std::prev_permutation, v-> ", v);

    std::next_permutation(v.begin(), v.end());
    TS::print("std::next_permutation, v-> ", v);
}

void TS::algo_permutation_sort(void)
{
    std::vector<int> v{2,1,3,99,99,99,0,-1,99,1};
    TS::print("original, v-> ", v);

    std::sort(v.begin(), v.end());
    TS::print("std::sort, v-> ", v);

    std::partial_sort(v.begin(), v.begin() + 3, v.end());
    TS::print("std::partial_sort, v-> ", v);

    std::partition(v.begin(), v.end(), [](auto& e){ return e%2==0; });
    TS::print("std::partition, v-> ", v);

    auto it = std::partition_point(v.begin(), v.end(), TS::IsEven());
    TS::format("std::partition_point, -> ");
    (it != std::end(v))
        ? std::cout << *it << std::endl
        : std::cout << "[not found]\n";

    std::reverse(v.begin(), v.end());
    TS::print("std::reverse, v-> ", v);

    std::random_device rd;
    std::mt19937 mt{rd()};
    std::shuffle(v.begin(), v.end(), mt);
    TS::print("std::shuffle, v-> ", v);

    std::rotate(v.begin(), std::next(v.begin(), 3), v.end());
    TS::print("std::rotate, v-> ", v);
}

void TS::algo_structure_changer(void)
{
    std::vector<int> v{2,1,3,99,99,99,0,-1,99,1};
    TS::print("original, v-> ", v);

    v.erase(std::remove(v.begin(), v.end(), 99), v.end());
    TS::print("std::remove, v-> ", v);

    v = {2,1,3,99,99,99,0,-1,99,1};
    v.erase(std::unique(v.begin(), v.end()), v.end());
    TS::print("std::unique, v-> ", v);
}

void TS::algo_mover(void)
{
    std::vector<int> v{2,1,3,99,99,99,0,-1,99,1};
    TS::print("original, v-> ", v);

    TS::format("std::copy, v-> ");
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    TS::newline();

    std::vector<std::thread> vt;
    vt.emplace_back(TS::func, 1);
    vt.emplace_back(TS::func, 2);
    vt.emplace_back(TS::func, 3);
    std::list<std::thread> lt;
    std::move(vt.begin(), vt.end(), std::back_inserter(lt));
    for(auto& t : lt) t.join();

    using container = std::vector<std::string>;
    container m = {"lorem", "ipsan"};
    container n = {"merci", "beaucoup"};

    std::move_backward(m.begin(), m.end(), n.end());
    TS::print("std::move_backward, m-> ", m);

    std::copy_backward(m.begin(), m.end(), n.end());
    TS::print("std::copy_backward, m-> ", m);

    std::swap_ranges(m.begin(), m.end(), n.begin());
    TS::print("std::swap_ranges, n-> ", n);
}

void TS::algo_value_modifier(void)
{
    std::vector<int> v(10);
    std::fill(v.begin(), v.end(), 42);
    TS::print("std::fill, v-> ", v);

    std::srand(std::time(NULL));
    std::generate(v.begin(), v.end(), [](){ return std::rand()%30; });
    TS::print("std::generate, v-> ", v);

    std::iota(v.begin(), v.end(), 1);
    TS::print("std::iota, v-> ", v);

    std::replace(v.begin(), v.end(), 1, 69);
    TS::print("std::replace, v-> ", v);
}

void TS::algo_set(void)
{
    using container = std::set<int>;
    container A {1,2,3,4,5};
    container B {4,5,6,7,8};
    TS::print("set A, -> ", A);
    TS::print("set B, -> ", B);

    std::vector<int> S;
    std::set_union(A.begin(), A.end(), B.begin(), B.end(), std::back_inserter(S));
    TS::print("std::set_union, S-> ", S);

    S.clear();
    std::set_intersection(A.begin(), A.end(), B.begin(), B.end(), std::back_inserter(S));
    TS::print("std::set_intersection, S-> ", S);

    S.clear();
    std::set_difference(A.begin(), A.end(), B.begin(), B.end(), std::back_inserter(S));
    TS::print("std::set_difference, S-> ", S);

    S.clear();
    std::set_symmetric_difference(A.begin(), A.end(), B.begin(), B.end(), std::back_inserter(S));
    TS::print("std::set_symmetric_difference, S-> ", S);

    bool rv = std::includes(A.begin(), A.end(), B.begin(), B.end());
    TS::format("std::includes, -> ");
    std::cout << std::boolalpha << rv << std::endl;
}

void TS::algo_query_property(void)
{
    std::vector<int> v{2,1,3,99,99,99,0,-1,99,1};
    TS::print("original, v-> ", v);

    // nth_element;
    std::nth_element(v.begin(), std::next(v.begin(), 3), v.end());
    TS::print("std::nth_element, v-> ", v);

    // *_bound;
    std::sort(v.begin(), v.end());
    auto it = std::lower_bound(v.begin(), v.end(), 4);
    TS::format("std::lower_bound, v-> ");
    (it != std::end(v))
        ? std::cout << "at index of " << std::distance(v.begin(), it) << std::endl
        : std::cout << "[not found]\n";

    it = std::upper_bound(v.begin(), v.end(), 4);
    TS::format("std::upper_bound, v-> ");
    (it != std::end(v))
        ? std::cout << "at index of " << std::distance(v.begin(), it) << std::endl
        : std::cout << "[not found]\n";

    // minmax_element;
    auto [mi, ma] = std::minmax_element(v.begin(), v.end());
    TS::format("std::minmax_element, v-> ");
    (mi != std::end(v) && ma != std::end(v))
        ? std::cout << "min -> " << *mi  << ", max -> " << *ma << std::endl
        : std::cout << "[not found]\n";

    // 2-ranges;
    std::string in = "Officia eiusmod mollit enim nisi aliqua elit labore cillum aliquip ea consequat anim mollit deserunt.";
    std::string ou = "eiusmod";

    bool rv = std::equal(ou.begin(), ou.end(), in.begin());
    TS::format("std::equal, v-> ");
    std::cout << std::boolalpha << rv << std::endl;

    rv = std::lexicographical_compare(ou.begin(), ou.end(), in.begin(), in.end());
    TS::format("std::lexicographical_compare, v-> ");
    std::cout << std::boolalpha << rv << std::endl;

    auto [lb, ub] = std::mismatch(ou.begin(), ou.end(), in.begin());
    TS::format("std::mismatch, v-> ");
    std::cout << *lb << ", " << *ub << std::endl;
}

void TS::algo_query_value(void)
{
    std::vector<int> v{2,1,3,99,99,99,0,-1,99,1};
    TS::print("original, v-> ", v);

    // find: find_end, find_first_of,
    // search: binary_search, search_n
    auto it = std::find(v.begin(), v.end(), 3);
    TS::format("std::find, v-> ");
    (it != std::end(v))
        ? std::cout << *it << std::endl
        : std::cout << "[not found]\n";

    std::vector<int> l{1, 3};
    it = std::find_end(l.begin(), l.end(), v.begin(), v.end());
    TS::format("std::find_end, v-> ");
    (it != std::end(v))
        ? std::cout << *it << std::endl
        : std::cout << "[not found]\n";

    it = std::find_first_of(l.begin(), l.end(), v.begin(), v.end());
    TS::format("std::find_first_of, v-> ");
    (it != std::end(v))
        ? std::cout << *it << std::endl
        : std::cout << "[not found]\n";

    std::sort(v.begin(), v.end());
    bool rv = std::binary_search(v.begin(), v.end(), 3);
    TS::format("std::binary_search, v-> ");
    std::cout << std::boolalpha << rv << std::endl;

    it = std::search(l.begin(), l.end(), v.begin(), v.end());
    TS::format("std::search, v-> ");
    (it != std::end(v))
        ? std::cout << *it << std::endl
        : std::cout << "[not found]\n";

    // cai sapr
    int cnt = std::count(v.begin(), v.end(), 99);
    TS::format("std::count, cnt->");
    std::cout << cnt << std::endl;

    it = std::adjacent_find(v.begin(), v.end());
    TS::format("std::adjacent_find, v-> ");
    (it != std::end(v))
        ? std::cout << *it << std::endl
        : std::cout << "[not found]\n";

    TS::format("std::adjacent_difference, v=> ");
    std::adjacent_difference(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    TS::newline();

    double result = std::accumulate(v.begin(), v.end(), 0.0);
    TS::format("std::accumulate, v-> ");
    std::cout << result << std::endl;

//    result = std::reduce(std::execution::par, v.begin(), v.end(), 0.0);
//    TS::format("std::reduce, v-> ");
//    std::cout << result << std::endl;

    using container = std::vector<int>;
    container a{1,2,3,4,5};
    container b{6,7,8,9,10};

    result = std::inner_product(a.begin(), a.end(), b.begin(), 0.0);
    TS::format("std::inner_product, v-> ");
    std::cout << result << std::endl;

    TS::format("std::partial_sum, v-> ");
    std::partial_sum(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    TS::newline();
}

void TS::algo_raw_memory(void)
{
    /*
    - uninitialized_default_construct
    - uninitialized_value_construct
    - uninitialized_fill
    - uninitialized_copy
    - uninitialized_move
    */

    std::cout << "raw memory -> nothing biggy" << std::endl;
}

void TS::algo_secret_rune(void)
{
    /*
    - is_*
    - is_*_until
    - stable_*
    - *_n
    - *_if
    - *_copy
    */

    std::cout << "secret rune -> nothing biggy" << std::endl;
}


void TS::algo_lone_island(void)
{
    std::vector<int> v{2,1,3,99,99,99,0,-1,99,1};
    TS::print("original, v-> ", v);

    TS::format("std::for_each, v-> ");
    std::for_each(v.begin(), v.end(), [](const auto& e){
                    std::cout << e << ' ';
                  });
    TS::newline();

    TS::format("std::transform, v-> ");
    std::string om = "tangsai";
    std::transform(om.begin(), om.end(),
                   std::ostream_iterator<char>(std::cout, " "),
                   [](const char& e){ return std::toupper(e); });
    TS::newline();
}
