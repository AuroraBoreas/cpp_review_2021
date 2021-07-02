#include "algo.h"

void scy::algo_permutation_heap(void)
{
    std::vector<int> v{2, 1, 3, 99, 99, 99, 0, -1, 99, 1};
    scy::print("original, v-> ", v);

    std::make_heap(std::begin(v), std::end(v), std::greater<>{});
    scy::print("std::make_heap, v-> ", v);

    std::pop_heap(v.begin(), v.end(), std::less<>());
    scy::print("std::pop_heap, v-> ", v);

    v.push_back(69);
    std::push_heap(v.begin(), v.end(), std::greater<>());
    scy::print("std::push_heap, v-> ", v);

    std::sort_heap(v.begin(), v.end(), std::greater<>());
    scy::print("std::sort_heap, v-> ", v);

    std::prev_permutation(v.begin(), v.end());
    scy::print("std::prev_permutation, v-> ", v);

    std::next_permutation(v.begin(), v.end());
    scy::print("std::next_permutation, v-> ", v);
}

void scy::algo_permutation_sort(void)
{
    std::vector<int> v{2, 1, 3, 99, 99, 99, 0, -1, 99, 1};
    scy::print("original, v-> ", v);

    std::sort(v.begin(), v.end(), std::greater<>{});
    scy::print("std::sort, v-> ", v);

    std::partial_sort(v.begin(), std::next(v.begin(), 3), v.end());
    scy::print("std::partial_sort, v-> ", v);

    class IsEven
    {
    public:
        bool operator()(const int& e) const
        { return e%2==0; }
    };

    std::partition(v.begin(), v.end(), IsEven());
    scy::print("std::partition, v-> ", v);

    auto it = std::partition_point(v.begin(), v.end(), IsEven());
    scy::format("std::partition_point, -> ");
    (it != std::end(v))
        ? std::cout << *it << std::endl
        : std::cout << "[not found]\n";

    std::rotate(v.begin(), std::next(v.begin(), 3), v.end());
    scy::print("std::rotate, v-> ", v);

    std::random_device rd;
    std::mt19937 mt{rd()};
    std::shuffle(v.begin(), v.end(), mt);
    scy::print("std::shuffle, v-> ", v);
}

void scy::algo_structure_changer(void)
{
    std::vector<int> v{2, 1, 3, 99, 99, 99, 0, -1, 99, 1};
    scy::print("original, v-> ", v);

    v.erase(std::remove(v.begin(), v.end(), 99), v.end());
    scy::print("std::remove, v-> ", v);

    v = {2, 1, 3, 99, 99, 99, 0, -1, 99, 1};
    v.erase(std::unique(v.begin(), v.end()), v.end());
    scy::print("std::unique, v-> ", v);
}

void scy::algo_mover(void)
{
    std::vector<int> v{2, 1, 3, 99, 99, 99, 0, -1, 99, 1};
    scy::print("original, v-> ", v);

    std::list<int> l;
    std::copy(v.begin(), v.end(), std::inserter(l, l.begin()));
    scy::print("std::copy, l-> ", l);

    std::vector<int> m(15);
    std::copy_backward(l.begin(), l.end(), m.end());
    scy::print("std::copy_backward, m-> ", m);

    std::vector<std::thread> vt;
    vt.emplace_back(scy::func, 1);
    vt.emplace_back(scy::func, 2);
    vt.emplace_back(scy::func, 3);
    std::list<std::thread> lt;
    std::move(vt.begin(), vt.end(), std::front_inserter(lt));
    scy::format("std::move, -> \n");
    for(auto& t : lt) t.join();

    using container = std::vector<std::string>;
    container c1 {"hello", "world"};
    container c2 {"zhang", "liang"};
    std::move_backward(c1.begin(), c1.end(), c2.end());
    scy::print("std::move_backward, -> ", c2);

    std::swap_ranges(c1.begin(), c1.end(), c2.begin());
    scy::print("std::swap_ranges, c1-> ", c1);
    scy::print("std::swap_ranges, c2-> ", c2);
}

void scy::algo_value_modifier(void)
{
    std::vector<int> v{2, 1, 3, 99, 99, 99, 0, -1, 99, 1};
    scy::print("original, v-> ", v);

    std::fill(v.begin(), v.end(), 42);
    scy::print("std::fill, v-> ", v);

    std::iota(v.begin(), v.end(), 0);
    scy::print("std::iota, v-> ", v);

    std::srand(std::time(NULL));
    auto g = [](){ return std::rand()%30; };
    std::generate(v.begin(), v.end(), g);
    scy::print("std::generate, v-> ", v);

    v = {2, 1, 3, 99, 99, 99, 0, -1, 99, 1};
    std::replace(v.begin(), v.end(), 99, 69);
    scy::print("std::replace, v-> ", v);
}

void scy::algo_set(void)
{
    std::set<int> A {1,2,3,4,5};
    std::set<int> B {4,5,6,7,8};
    std::vector<int> S;

    scy::format("std::merge, S-> ");
    std::merge(A.begin(), A.end(), B.begin(), B.end(), std::ostream_iterator<int>(std::cout, " "));
    scy::newline();

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

    bool rv = std::includes(A.begin(), A.end(), B.begin(), B.end());
    scy::format("std::includes, S-> ");
    scy::tf(rv);
}

void scy::algo_query_property(void)
{
    std::vector<int> v{2, 1, 3, 99, 99, 99, 0, -1, 99, 1};
    scy::print("original, v-> ", v);

    auto isEven = [](const auto& e){ return e%2==0; };
    bool rv = std::any_of(v.begin(), v.end(), isEven);
    scy::format("std::any_of, -> ");
    scy::tf(rv);

    rv = std::all_of(v.begin(), v.end(), isEven);
    scy::format("std::all_of, -> ");
    scy::tf(rv);

    rv = std::none_of(v.begin(), v.end(), isEven);
    scy::format("std::none_of, -> ");
    scy::tf(rv);

    // minmax_element
    auto [mi, ma] = std::minmax_element(v.begin(), v.end());
    scy::format("std::minmax_element, -> ");
    (mi != std::end(v) && ma != std::end(v))
        ? std::cout << *mi << ", " << *ma << std::endl
        : std::cout << "[not found]\n";

    // nth_element
    std::nth_element(v.begin(), v.begin()+3, v.end(), std::greater<>{});
    scy::print("std::nth_element, v-> ", v);

    // *_bound
    auto it = std::lower_bound(v.begin(), v.end(), 42);
    scy::format("std::lower_bound, -> ");
    (it != std::end(v))
        ? std::cout << *it << std::endl
        : std::cout << "[not found]\n";

    it = std::upper_bound(v.begin(), v.end(), 42);
    scy::format("std::upper_bound, -> ");
    (it != std::end(v))
        ? std::cout << *it << std::endl
        : std::cout << "[not found]\n";


    std::string in = "Non enim deserunt qui excepteur.";
    std::string ou = "Non";

    rv = std::equal(in.begin(), in.end(), ou.begin(), ou.end());
    scy::format("std::equal, -> ");
    scy::tf(rv);

    rv = std::lexicographical_compare(in.begin(), in.end(), ou.begin(), ou.end());
    scy::format("std::lexicographical_compare, -> ");
    scy::tf(rv);

    auto [p1, p2] = std::mismatch(ou.begin(), ou.end(), in.begin());
    scy::format("std::mismatch, -> ");
    (p1 != std::end(in) && p2 != std::end(in))
        ? std::cout << *p1 << ", " << *p2 << std::endl
        : std::cout << "[not found]\n";

    // find
    it = std::find(v.begin(), v.end(), 2);
    scy::format("std::find, -> ");
    (it != std::end(v))
        ? std::cout << *it << std::endl
        : std::cout << "[not found]\n";

    // find_end
    std::string m = "hello world!";
    std::string n = "wo";
    auto iter = std::find_end(n.begin(), n.end(), m.begin(), m.end());
    scy::format("std::find_end, -> ");
    (iter != std::end(m))
        ? std::cout << *iter << std::endl
        : std::cout << "[not found]\n";

    // find_first_of
    iter = std::find_first_of(n.begin(), n.end(), m.begin(), m.end());
    scy::format("std::find_first_of, -> ");
    (iter != std::end(m))
        ? std::cout << *iter << std::endl
        : std::cout << "[not found]\n";

    // search
    iter = std::search(n.begin(), n.end(), m.begin(), n.end());
    scy::format("std::search, -> ");
    (iter != std::end(m))
        ? std::cout << *iter << std::endl
        : std::cout << "[not found]\n";

    // binary_search
    std::sort(v.begin(), v.end());
    rv = std::binary_search(v.begin(), v.end(), 3);
    scy::format("std::binary_search, -> ");
    scy::tf(rv);
}

void scy::algo_query_value(void)
{
    std::vector<int> v{2, 1, 3, 99, 99, 99, 0, -1, 99, 1};
    scy::print("original, v-> ", v);

    int cnt = std::count(v.begin(), v.end(), 99);
    scy::format("std::count, -> ");
    std::cout << cnt << std::endl;

    // adjacent_find
    auto it = std::adjacent_find(v.begin(), v.end());
    scy::format("std::adjacent_find, -> ");
    (it != std::end(v))
        ? std::cout << *it << std::endl
        : std::cout << "[not found]\n";

    // adjacent_different
    std::vector<int> l;
    std::adjacent_difference(v.begin(), v.end(), std::back_inserter(l));
    scy::print("std::adjacent_difference, l-> ", l);

    // inner_product
    using container = std::vector<int>;
    container c1 {1,2,3,4,5};
    container c2 {4,5,6,7,8};
    double result = std::inner_product(c1.begin(), c1.end(), c2.begin(), 1);
    scy::format("std::inner_product, -> ");
    std::cout << result << std::endl;

    // accumulate
    result = std::accumulate(v.begin(), v.end(), 0.0);
    scy::format("std::accumulate, -> ");
    std::cout << result << std::endl;

    // inclusive_scan
    // exclusive_scan
    // reduce
    // partial_sum
    scy::format("std::partial_sum, -> ");
    std::partial_sum(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    scy::newline();
}

void scy::algo_raw_memory(void)
{
    /*
    - uninitialized_default_construct
    - uninitialized_value_construct
    - uninitialized_copy
    - uninitialized_move
    - uninitialized_fill
    */

    std::cout << "raw memory -> nothing biggy, nothing special\n";
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
    std::cout << "secret runes -> nothing biggy, nothing special\n";
}

void scy::algo_lone_island(void)
{
    std::vector<int> v{2, 1, 3, 99, 99, 99, 0, -1, 99, 1};
    scy::print("original, v-> ", v);

    // for_each
    scy::format("std::for_each, v-> ");
    std::for_each(v.begin(), v.end(), [](auto& e){
                    std::cout << e << " ";
                  });
    scy::newline();

    // transform
    std::list<int> l;
    std::transform(v.begin(), v.end(), std::back_inserter(l), [](const auto& e){ return e*e; });
    scy::print("std::transform, l-> ", l);
}
