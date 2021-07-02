#include "algo.h"

void TS::algo_permutation_heap(void)
{
    // make heap push pop sort
    std::vector<int> v{2,1,3,99,99,99,0,-1,99,1};
    TS::print("original, v-> ", v);

    std::make_heap(v.begin(), v.end(), std::greater<>{});
    TS::print("std::make_heap, v-> ", v);

    std::pop_heap(v.begin(), v.end(), std::less<>());
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
    // psr
    std::vector<int> v{2,1,3,99,99,99,0,-1,99,1};
    TS::print("original, v-> ", v);

    std::sort(v.begin(), v.end());
    TS::print("std::sort, v-> ", v);

    std::reverse(v.begin(), v.end());
    TS::print("std::reverse, v-> ", v);

    std::partial_sort(v.begin(), std::next(v.begin(), 3), v.end());
    TS::print("std::partial_sort, v-> ", v);

    std::partition(v.begin(), v.end(), TS::IsEven());
    TS::print("std::partition, v-> ", v);

    std::rotate(v.begin(), std::begin(v)+3, v.end());
    TS::print("std::rotate, v-> ", v);

    std::random_device rd;
    std::mt19937 mt{rd()};
    std::shuffle(v.begin(), v.end(), mt);
    TS::print("std::shuffle, v-> ", v);

    auto it = std::partition_point(v.begin(), v.end(), TS::IsEven());
    TS::oformat("std::partition_point, it-> ");
    (it != std::end(v))
        ? std::cout << *it << std::endl
        : std::cout << "[not found]\n";

    bool rv = std::is_sorted(v.begin(), v.end());
    TS::oformat("std::is_sorted, it-> ");
    std::cout << std::boolalpha << rv << std::endl;

    rv = std::is_heap(v.begin(), v.end());
    TS::oformat("std::is_heap, it-> ");
    std::cout << std::boolalpha << rv << std::endl;

    rv = std::is_partitioned(v.begin(), v.end(), TS::IsEven());
    TS::oformat("std::is_partitioned, it-> ");
    std::cout << std::boolalpha << rv << std::endl;

    std::list<int> u {2,1,3,99,99,99,0,-1,99,1};
    rv = std::is_permutation(v.begin(), v.end(), u.begin());
    TS::oformat("std::is_permutation, it-> ");
    std::cout << std::boolalpha << rv << std::endl;

    it = std::is_sorted_until(v.begin(), v.end());
    TS::oformat("std::is_sorted_until, it-> ");
    (it != std::end(v))
        ? std::cout << *it << std::endl
        : std::cout << "[not found]\n";

    it = std::is_heap_until(v.begin(), v.end());
    TS::oformat("std::is_heap_until, it-> ");
    (it != std::end(v))
        ? std::cout << *it << std::endl
        : std::cout << "[not found]\n";
}

void TS::algo_structure_changer(void)
{
    std::vector<int> v{2,1,3,99,99,99,0,-1,99,1};
    TS::print("original, v-> ", v);

    v.erase(std::remove(v.begin(), v.end(), 99), v.end());
    TS::print("std::remove, v-> ", v);

    v = {2,1,3,99,99,99,0,-1,99,1};
    v.erase(std::unique(v.begin(), v.end()), v.end());
    TS::print("std::erase, v-> ", v);
}

void TS::algo_mover(void)
{
    std::vector<int> v{2,1,3,99,99,99,0,-1,99,1};
    TS::print("original, v-> ", v);

    TS::oformat("std::copy, v-> ");
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    TS::newline();

    std::list<int> l;
    std::copy_backward(v.begin(), v.end(), l.end());
    TS::print("std::copy_backward, l-> ", l);

    std::vector<std::thread> vt;
    vt.emplace_back(TS::func, 1);
    vt.emplace_back(TS::func, 2);
    vt.emplace_back(TS::func, 3);
    std::list<std::thread> lt;
    std::move(vt.begin(), vt.end(), std::back_inserter(lt));
    TS::oformat("std::move, ->\n");
    for(auto& t : lt) t.join();

    // std::move_backward

    using container = std::vector<std::string>;
    container m {"hello", "world"};
    container n {"zhang", "liang"};
    TS::print("std::swap_ranges, b4 -> ", m);
    TS::print("std::swap_ranges, b4 -> ", n);
    std::swap_ranges(m.begin(), m.end(), n.begin());
    TS::print("std::swap_ranges, af -> ", m);
    TS::print("std::swap_ranges, af -> ", n);
}

void TS::algo_value_modifier(void)
{
    std::vector<int> v{2,1,3,99,99,99,0,-1,99,1};
    TS::print("original, v-> ", v);

    std::fill(v.begin(), v.end(), 42);
    TS::print("std::fill, v-> ", v);

    std::iota(v.begin(), v.end(), 1);
    TS::print("std::iota, v-> ", v);

    std::replace(v.begin(), v.end(), 1, 42);
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
    std::vector<int> S;
    TS::print("std::set A -> ", A);
    TS::print("std::set B -> ", B);

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

    S.clear();
    bool rv = std::includes(A.begin(), A.end(), B.begin(), B.end());
    TS::oformat("std::includes, v-> ");
    std::cout << std::boolalpha << rv << std::endl;

    S.clear();
    TS::oformat("std::merge, S-> ");
    std::merge(A.begin(), A.end(), B.begin(), B.end(), std::ostream_iterator<int>(std::cout, " "));
    TS::newline();
}

void TS::algo_query_property(void)
{
    std::vector<int> v{2,1,3,99,99,99,0,-1,99,1};
    TS::print("original, v-> ", v);

    // *_element: nth_element, minmax_element;
    std::nth_element(v.begin(), std::next(v.begin(), 3), v.end());
    TS::print("std::nth_element, v-> ", v);

    auto [mi, ma] = std::minmax_element(v.begin(), v.end());
    TS::oformat("std::minmax_element, minmax->");
    (mi != std::end(v) && ma != std::end(v))
        ? std::cout << *mi << ", " << *ma << std::endl
        : std::cout << "[not found]\n";

    // *_bound: lower_bound, upper_bound;
    auto it = std::lower_bound(v.begin(), v.end(), 2, std::less<>());
    TS::oformat("std::lower_bound, it-> ");
    (it != std::end(v))
        ? std::cout << *it << std::endl
        : std::cout << "[not found]\n";

    it = std::upper_bound(v.begin(), v.end(), 2, std::less<>{});
    TS::oformat("std::upper_bound, it-> ");
    (it != std::end(v))
        ? std::cout << *it << std::endl
        : std::cout << "[not found]\n";

    // *_scan: inclusive_scan, exclusive_scan;
}

void TS::algo_query_value(void)
{
    std::vector<int> v{2,1,3,99,99,99,0,-1,99,1};
    TS::print("original, v-> ", v);

    // cai sapr
    int cnt = std::count(v.begin(), v.end(), 99);
    TS::oformat("std::count, cnt->");
    std::cout << cnt << std::endl;

    double rs = std::accumulate(v.begin(), v.end(), 0.0);
    TS::oformat("std::accumulate, rs-> ");
    std::cout << rs << std::endl;

    TS::oformat("std::adjacent_difference, rs-> ");
    std::adjacent_difference(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    TS::newline();

    auto it = std::adjacent_find(v.begin(), v.end());
    TS::oformat("std::adjacent_find, it-> ");
    (it != std::end(v))
        ? std::cout << *it << std::endl
        : std::cout << "[not found]\n";

    std::vector<int> u{2,1,3,99,99,99,0,-1,99,1};
    rs = std::inner_product(v.begin(), v.end(), u.begin(), 0.0);
    TS::oformat("std::inner_product, rs-> ");
    std::cout << rs << std::endl;

    std::random_device  rd;
    std::mt19937 mt{rd()};
    TS::oformat("std::sample, v-> ");
    std::sample(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "), 3, mt);
    TS::newline();

    TS::oformat("std::partial_sum, v-> ");
    std::partial_sum(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    TS::newline();
}

void TS::algo_raw_memory(void)
{
    /*
    - uninitialized_default_construct
    - uninitialized_value_construct
    - uninitialized_copy
    - uninitialized_fill
    - uninitialized_move
    */

    TS::oformat("std::raw_memory -> nothing biggy\n");
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
    TS::oformat("std::secret_runes -> nothing biggy \n");
}

void TS::algo_lone_island(void)
{
    std::vector<int> v{2,1,3,99,99,99,0,-1,99,1};
    TS::print("original, v-> ", v);

    TS::oformat("std::for_each, v-> ");
    std::for_each(v.begin(), v.end(), [](const auto& e){
                        std::cout << e << TS::b;
                  });
    TS::newline();

    TS::oformat("std::transform, v-> ");
    std::transform(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "), [](const auto& e){ return e*e; });
    TS::newline();
}
