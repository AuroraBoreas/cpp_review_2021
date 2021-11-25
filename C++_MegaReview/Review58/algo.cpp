#include "algo.h"

void CY::algo_permutation_heap(void)
{
    std::vector<int> v{2,1,3,99,99,99,0,-1,99};
    CY::print("original, v-> ", v);

    /// make heap pop
    std::make_heap(v.begin(), v.end(), std::greater<>{});
    CY::print("std::make_heap, v-> ", v);

    std::pop_heap(v.begin(), v.end(), std::less<>());
    CY::print("std::pop_heap, v-> ", v);

    v.push_back(42);
    std::push_heap(v.begin(), v.end());
    CY::print("std::push_heap, v-> ", v);

    std::sort_heap(v.begin(), v.end());
    CY::print("std::sort_heap, v-> ", v);

    std::prev_permutation(v.begin(), v.end());
    CY::print("std::prev_permutation, v-> ", v);

    std::next_permutation(v.begin(), v.end());
    CY::print("std::next_permutation, v-> ", v);
}

void CY::algo_permutation_sort(void)
{
    std::vector<int> v{2,1,3,99,99,99,0,-1,99};
    CY::print("original, v-> ", v);

    /// psr

    std::partition(v.begin(), v.end(), CY::IsEven());
    CY::print("std::partition, v-> ", v);

    auto it = std::partition_point(v.begin(), v.end(), [](const auto& e)->bool{ return e%2==0; });
    CY::oformat("std::partition_point, it-> ");
    (it != std::end(v))
        ? std::cout << *it << std::endl
        : std::cout << "[not found]" << std::endl;

    std::partial_sort(v.begin(), v.begin()+3, v.end());
    CY::print("std::partial_sort, v-> ", v);

    std::sort(v.begin(), v.end());
    CY::print("std::sort, v-> ", v);

    std::reverse(v.begin(), v.end());
    CY::print("std::reverse, v-> ", v);

    std::rotate(v.begin(), std::next(std::begin(v), 3), v.end());
    CY::print("std::rotate, v-> ", v);
}

void CY::algo_structure_changer(void)
{
    std::vector<int> v{2,1,3,99,99,99,0,-1,99};
    CY::print("original, v-> ", v);

    /// ru
    int const x(99);
    v.erase(std::remove(v.begin(), v.end(), x), v.end());
    CY::print("std::remove, v-> ", v);

    v = {2,1,3,99,99,99,0,-1,99};
    v.erase(std::unique(v.begin(), v.end()), v.end());
    CY::print("std::unique, v-> ", v);
}

void CY::algo_mover(void)
{
    std::vector<int> v{2,1,3,99,99,99,0,-1,99};
    CY::print("original, v-> ", v);

    /// cms
    CY::oformat("std::copy, v-> ");
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    CY::newline();

    std::list<int> u;
    std::copy_backward(v.begin(), v.end(), u.end());
    CY::print("std::copy_backward, u-> ", u);

    std::vector<std::thread> vt;
    vt.emplace_back(CY::func, 1);
    vt.emplace_back(CY::func, 2);
    vt.emplace_back(CY::func, 3);
    std::list<std::thread> lt;
    std::move(vt.begin(), vt.end(), std::back_inserter(lt));
    CY::oformat("std::move, lt->\n");
    for(auto& t : lt) t.join();
    CY::newline();

    using container = std::vector<std::string>;
    container m{"hello", "world"};
    container n{"zhang", "liang"};
    std::move_backward(m.begin(), m.end(), n.end());
    CY::print("std::move_backward, n->", n);

    m = {"hello", "world"};
    n = {"zhang", "liang"};
    std::swap_ranges(m.begin(), m.end(), n.begin());
    CY::print("std::move_backward, m->", m);
    CY::print("std::move_backward, n->", n);
}

void CY::algo_value_modifier(void)
{
    std::vector<int> v{2,1,3,99,99,99,0,-1,99};
    CY::print("original, v-> ", v);

    /// figr
    std::fill(v.begin(), v.end(), 1);
    CY::print("std::fill, v-> ", v);

    std::iota(v.begin(), v.end(), 0);
    CY::print("std::iota, v-> ", v);

    std::replace(v.begin(), v.end(), 1, 42);
    CY::print("std::replace, v-> ", v);

    std::random_device rd;
    std::mt19937 g{rd()};
    std::generate(v.begin(), v.end(), g);
    CY::print("std::generate, v-> ", v);
}

void CY::algo_set(void)
{
    std::vector<int> v{2,1,3,99,99,99,0,-1,99};
    CY::print("original, v-> ", v);

    /// umids
    using container = std::vector<int>;
    container A{1, 2, 3, 4, 5, 5};
    container B{4, 5, 6, 7, 8, 8};
    std::list<int> S;

    S.clear();
    std::set_union(A.begin(), A.end(), B.begin(), B.end(), std::back_inserter(S));
    CY::print("std::set_union, S-> ", S);

    S.clear();
    std::merge(A.begin(), A.end(), B.begin(), B.end(), std::back_inserter(S));
    CY::print("std::merge, S-> ", S);

    S.clear();
    std::set_difference(A.begin(), A.end(), B.begin(), B.end(), std::back_inserter(S));
    CY::print("std::set_difference, S-> ", S);

    S.clear();
    std::set_intersection(A.begin(), A.end(), B.begin(), B.end(), std::back_inserter(S));
    CY::print("std::set_intersection, S-> ", S);

    S.clear();
    std::set_symmetric_difference(A.begin(), A.end(), B.begin(), B.end(), std::back_inserter(S));
    CY::print("std::set_symmetric_difference, S-> ", S);
}

void CY::algo_query_value(void)
{
    std::vector<int> v{2,1,3,99,99,99,0,-1,99};
    CY::print("original, v-> ", v);

    /// cai sapr
    int x(42);
    int cnt = std::count(v.begin(), v.end(), x);
    CY::oformat("std::count, cnt-> ");
    std::cout << cnt << std::endl;

    double rv = std::accumulate(v.begin(), v.end(), .0);
    CY::oformat("std::accumulate, rv-> ");
    std::cout << std::setprecision(2) << rv << std::endl;

    std::vector<int> u{2,1,3,99,99,99,0,-1,99};
    rv = std::inner_product(v.begin(), v.end(), u.begin(), 0.0);
    CY::oformat("std::inner_product, rv-> ");
    std::cout << std::setprecision(2) << rv << std::endl;

    CY::oformat("std::sample, v-> ");
    std::random_device rd;
    std::mt19937 g{rd()};
    std::sample(v.begin(), v.end(),
                std::ostream_iterator<int>(std::cout, " "), 4, g);
    CY::newline();

    CY::oformat("std::adjacent_difference, v-> ");
    std::adjacent_difference(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    CY::newline();

    auto it = std::adjacent_find(v.begin(), v.end());
    CY::oformat("std::adjacent_find, it-> ");
    (it != std::end(v))
        ? std::cout << *it << std::endl
        : std::cout << "[not found]\n";

    CY::oformat("std::partial_sum, v-> ");
    std::partial_sum(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    CY::newline();

    /// std::reduce;
}

void CY::algo_query_property(void)
{
    std::vector<int> v{2,1,3,99,99,99,0,-1,99};
    CY::print("original, v-> ", v);

    /// sebfs lem
    // std::transform_exclusive_scan; std::transform_inclusive_scan;
    std::nth_element(v.begin(), v.begin()+3, v.end());
    CY::print("std::nth_element, v-> ", v);

    auto [mi, ma] = std::minmax_element(v.begin(), v.end());
    CY::oformat("std::minmax_element, min/max-> ");
    (mi != std::end(v) && ma != std::end(v))
        ? std::cout << *mi << ", " << *ma << std::endl
        : std::cout << "[not found]\n";

    const int x(42);
    auto it = std::lower_bound(v.begin(), v.end(), x);
    CY::oformat("std::lower_bound, it-> ");
    (it != std::end(v))
        ? std::cout << *it << std::endl
        : std::cout << "[not found]\n";

    it = std::upper_bound(v.begin(), v.end(), x);
    CY::oformat("std::upper_bound, it-> ");
    (it != std::end(v))
        ? std::cout << *it << std::endl
        : std::cout << "[not found]\n";

    std::vector<int> u{1,3};
    it = std::find_first_of(u.begin(), u.end(), v.begin(), v.end());
    CY::oformat("std::find_first_of, it-> ");
    (it != std::end(v))
        ? std::cout << *it << std::endl
        : std::cout << "[not found]\n";

    it = std::find_end(u.begin(), u.end(), v.begin(), v.end());
    CY::oformat("std::find_end, it->");
    (it != std::end(v))
        ? std::cout << *it << std::endl
        : std::cout << "[not found]\n";

    std::sort(v.begin(), v.end());

    it = std::search(u.begin(), u.end(), v.begin(), v.end());
    CY::oformat("std::search, it-> ");
    (it != std::end(v))
        ? std::cout << *it << std::endl
        : std::cout << "[not found]\n";

    bool rv = std::binary_search(v.begin(), v.end(), x);
    CY::oformat("std::binary_search, rv-> ");
    std::cout << std::boolalpha << rv << std::endl;

    std::string m{"hello world"};
    std::string n{"o w"};
    rv = std::equal(n.begin(), n.end(), m.begin(), m.end());
    CY::oformat("std::equal, rv-> ");
    std::cout << std::boolalpha << rv << std::endl;

    rv = std::lexicographical_compare(n.begin(), n.end(), m.begin(), m.end());
    CY::oformat("std::lexicographical_compare, rv-> ");
    std::cout << std::boolalpha << rv << std::endl;

    auto [im, am] = std::mismatch(n.begin(), n.end(), m.begin());
    CY::oformat("std::mismatch, beg/end-> ");
    (im != std::end(m) && am != std::end(m))
        ? std::cout << *im << ", " << *am << std::endl
        : std::cout << "[not found]\n";
}

void CY::algo_raw_memory(void)
{
    std::vector<int> v{2,1,3,99,99,99,0,-1,99};
    CY::print("original, v-> ", v);

    ///
    /** raw_memory
     * uninitialized_default_construct
     * uninitialized_value_construct
     * uninitialized_fill
     * uninitialized_copy
     * uninitialized_move
    */

     CY::oformat("std::raw_memory, -> nothing special;\n");
}

void CY::algo_secret_rune(void)
{
    std::vector<int> v{2,1,3,99,99,99,0,-1,99};
    CY::print("original, v-> ", v);

    ///
    /** secret_rune
     * *_if
     * stable_*
     * *_n
     * *_is; *_is_copy;
     * *_copy;
     */

    CY::oformat("std::secret_rune, -> nothing biggy;\n");
}

void CY::algo_lone_island(void)
{
    std::vector<int> v{2,1,3,99,99,99,0,-1,99};
    CY::print("original, v-> ", v);

    ///ft
    CY::oformat("std::for_each, v-> ");
    std::for_each(v.begin(), v.end(), [](const auto& e)->void{ std::cout << e << " "; });
    CY::newline();


    CY::oformat("std::transfrom, v-> ");
    std::transform(v.begin(), v.end(),
                   std::ostream_iterator<int>(std::cout, " "),
                   [](const auto& e){ return e*e; });
    CY::newline();
}

