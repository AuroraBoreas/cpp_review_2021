#include "algo.h"

void TS::algo_permutation_heap(void)
{
    std::vector<int> v{2,1,3,99,99,99,0,-1,99,1};
    TS::print("original, v-> ", v);

    std::make_heap(v.begin(), v.end(), std::greater<>{});
    TS::print("std::make_heap, v-> ", v);

    std::pop_heap(v.begin(), v.end());
    TS::print("std::pop_heap, v-> ", v);

    v.push_back(42);
    std::push_heap(v.begin(), v.end());
    TS::print("std::push_heap, v-> ", v);

    std::sort_heap(v.begin(), v.end());
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

    // psr
    std::sort(v.begin(), v.end());
    TS::print("std::sort, v-> ", v);

    std::partial_sort(v.begin(), v.begin()+3, v.end());
    TS::print("std::partial_sort, v-> ", v);

    std::partition(v.begin(), v.end(), [](auto const& e){ return e%2==0; });
    TS::print("std::partition, v-> ", v);

    std::reverse(v.begin(), v.end());
    TS::print("std::reverse, v-> ", v);

    std::rotate(v.begin(), std::next(v.begin(), 3), v.end());
    TS::print("std::rotate, v-> ", v);

    std::random_device rd;
    std::mt19937 mt{rd()};
    std::shuffle(v.begin(), v.end(), mt);
    TS::print("std::shuffle, v-> ", v);
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

    // c, m, s
    TS::of("std::copy, v-> ");
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    TS::newline();

    std::list<int> l;
    TS::of("std::copy_backward, l-> ");
    std::copy_backward(v.begin(), v.end(), l.end());
    TS::newline();

    std::vector<std::thread> vt;
    vt.emplace_back(TS::func, 1);
    vt.emplace_back(TS::func, 2);
    vt.emplace_back(TS::func, 3);
    std::list<std::thread> lt;
    std::move(vt.begin(), vt.end(), std::inserter(lt, lt.begin()));
    TS::of("std::move, lt-> \n");
    for(auto& t : lt) t.join();

    // std::move_backward();

    using container = std::vector<std::string>;
    container m {"hello", "wold"};
    container n {"zhang", "liang"};
    std::swap_ranges(m.begin(), m.end(), n.begin());
    TS::print("std::swap_ranges, m-> ", m);
    TS::print("std::swap_ranges, n-> ", n);
}

void TS::algo_value_modifier(void)
{
    std::vector<int> v{2,1,3,99,99,99,0,-1,99,1};
    TS::print("original, v-> ", v);

    std::fill(v.begin(), v.end(), 42);
    TS::print("std::fil, v-> ", v);

    std::iota(v.begin(), v.end(), 0);
    TS::print("std::iota, v-> ", v);

    std::replace(v.begin(), v.end(), 1, 69);
    TS::print("std::replace, v-> ", v);

    std::srand(std::time(NULL));
    auto g = [](){ return std::rand()%30; };
    std::generate(v.begin(), v.end(), g);
    TS::print("std::generate, v-> ", v);
}

void TS::algo_set(void)
{
    using container = std::set<int>;
    container A{1,2,3,4,5};
    container B{4,5,6,7,8};
    TS::print("std::set, A-> ", A);
    TS::print("std::set, B-> ", B);

    std::vector<int> S;

    std::set_union(A.begin(), A.end(), B.begin(), B.end(), std::inserter(S, S.begin()));
    TS::print("std::set_union, S-> ", S);

    S.clear();
    std::set_intersection(A.begin(), A.end(), B.begin(), B.end(), std::inserter(S, S.begin()));
    TS::print("std::set_intersection, S-> ", S);

    S.clear();
    std::set_difference(A.begin(), A.end(), B.begin(), B.end(), std::inserter(S, S.begin()));
    TS::print("std::set_difference, S-> ", S);

    S.clear();
    std::set_symmetric_difference(A.begin(), A.end(), B.begin(), B.end(), std::inserter(S, S.begin()));
    TS::print("std::set_symmetric_difference, S-> ", S);

    S.clear();
    bool rv = std::includes(A.begin(), A.end(), B.begin(), B.end());
    TS::of("std::includes -> ");
    std::cout << std::boolalpha << rv << std::endl;
}

void TS::algo_query_property(void)
{
    std::vector<int> v{2,1,3,99,99,99,0,-1,99,1};
    TS::print("original, v-> ", v);

    std::sort(v.begin(), v.end());
    // *_bound,
    auto it = std::lower_bound(v.begin(), v.end(), 3);
    TS::of("std::lower_bound, of 3 -> ");
    (it != std::end(v))
        ? std::cout << *it << std::endl
        : std::cout << "[not found]\n";

    it = std::upper_bound(v.begin(), v.end(), 3);
    TS::of("std::upper_bound, of 3 -> ");
    (it != std::end(v))
        ? std::cout << *it << std::endl
        : std::cout << "[not found]\n";

    // *_element,
    std::nth_element(v.begin(), v.begin()+3, v.end(), std::greater<>{});
    TS::print("std::nth_element, n -> ", v);

    auto [mi, ma] = std::minmax_element(v.begin(), v.end());
    TS::of("std::minmax_element, ->");
    (mi != std::end(v) && ma != std::end(v))
        ? std::cout << *mi << ", " << *ma << std::endl
        : std::cout << "[not found]\n";

    // is_*
    bool rv = std::is_sorted(v.begin(), v.end());
    TS::of("std::is_sorted, rv-> ");
    std::cout << std::boolalpha << rv << std::endl;

    rv = std::is_partitioned(v.begin(), v.end(), TS::IsEven());
    TS::of("std::is_partitioned, rv-> ");
    std::cout << std::boolalpha << rv << std::endl;

    std::vector<int> u = {2,1,3,99,99,99,0,-1,99,1};
    rv = std::is_permutation(v.begin(), v.end(), u.begin());
    TS::of("std::is_permutation, rv-> ");
    std::cout << std::boolalpha << rv << std::endl;

    rv = std::is_heap(v.begin(), v.end());
    TS::of("std::is_heap, rv-> ");
    std::cout << std::boolalpha << rv << std::endl;

    // is_*_until
    auto iter = std::is_sorted_until(v.begin(), v.end());
    TS::of("std::is_sorted_until, n -> ");
    (iter != std::end(v))
        ? std::cout << *iter << std::endl
        : std::cout << "[not found]\n";

    iter = std::is_heap_until(v.begin(), v.end());
    TS::of("std::is_heap_until, n -> ");
    (iter != std::end(v))
        ? std::cout << *iter << std::endl
        : std::cout << "[not found]\n";
}

void TS::algo_query_value(void)
{
    std::vector<int> v{2,1,3,99,99,99,0,-1,99,1};
    TS::print("original, v-> ", v);

    int cnt = std::count(v.begin(), v.end(), 99);
    TS::of("std::count, 99s -> ");
    std::cout << cnt << std::endl;

    // cai sapr
    TS::of("std::adjacent_difference, v-> ");
    std::adjacent_difference(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    TS::newline();

    auto it = std::adjacent_find(v.begin(), v.end());
    TS::of("std::adjacent_find, v-> ");
    (it != std::end(v))
        ? std::cout << *it << std::endl
        : std::cout << "[not found]\n";

    double result = std::accumulate(v.begin(), v.end(), 0.0);
    TS::of("std::accumulate, result-> ");
    std::cout << result << std::endl;

    // reduce: not implemented yet in gcc++
    std::vector<int> u{2,1,3,99,99,99,0,-1,99,1};
    result = std::inner_product(v.begin(), v.end(), u.begin(), 0.0);
    TS::of("std::inner_product, result-> ");
    std::cout << result << std::endl;

    std::random_device rd;
    std::mt19937 mt{rd()};
    TS::of("std::sample, -> ");
    std::sample(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "), 3, mt);
    TS::newline();

    TS::of("std::partial_sum, v-> ");
    std::partial_sum(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    TS::newline();

    // *_scan: inclusive_scan, exclusive_scan;
}

void TS::algo_raw_memory(void)
{
    /*
    - uninitialized_default_construct
    - uninitialized_value_construct
    - uninitialized_fill
    - uninitialized_move
    - uninitialized_copy
    */
    TS::of("raw memory -> nothing biggy");
    TS::newline();
}

void TS::algo_secret_rune(void)
{
    /*
    - *_if
    - stable_*
    - *_n
    - is_*
    - is_*_until
    - *_copy
    */
    TS::of("secret runes -> nothing biggy");
    TS::newline();
}

void TS::algo_lone_island(void)
{
    std::vector<int> v{2,1,3,99,99,99,0,-1,99,1};
    TS::print("original, v-> ", v);

    TS::of("std::for_each, v-> ");
    std::for_each(v.begin(), v.end(), [](auto const& e){
                    std::cout << e << " ";
                  });
    TS::newline();

    TS::of("std::transform, v-> ");
    std::transform(v.begin(), v.end(),
                   std::ostream_iterator<int>(std::cout, " "),
                   [](const auto& e){
                        return e*e; });
    TS::newline();
}
