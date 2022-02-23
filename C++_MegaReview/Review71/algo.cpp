#include "algo.h"

void cy::algo_permutation_heap(void)
{
    std::vector<int> v{2,1,3,4,99,88,99,0,-1,99};
    cy::print("original, v-> ", v);

    /// mspp
    std::make_heap(v.begin(), v.end(), std::greater<>{});
    cy::print("std::make_heap, v-> ", v);

    std::sort_heap(v.begin(), v.end(), std::less<>());
    cy::print("std::sort_heap, v-> ", v);

    std::pop_heap(v.begin(), v.end(), std::greater<>{});
    cy::print("std::pop_heap, v-> ", v);

    v.push_back(42);
    std::push_heap(v.begin(), v.end(), std::greater<>{});
    cy::print("std::push_heap, v-> ", v);

    std::prev_permutation(v.begin(), v.end());
    cy::print("std::prev_permutation, v-> ", v);

    std::next_permutation(v.begin(), v.end());
    cy::print("std::next_permutation, v-> ", v);
}

void cy::algo_permutation_sort(void)
{
    std::vector<int> v{2,1,3,4,99,88,99,0,-1,99};
    cy::print("original, v-> ", v);

    /// psr
    std::partition(v.begin(), v.end(), [](const int& e)->bool{ return e%2==0; });
    cy::print("std::partition, v-> ", v);

    auto it = std::partition_point(v.begin(), v.end(), cy::IsEven());
    cy::oformat("std::partition_point, it-> ");
    (it != std::end(v))
        ? std::cout << *it << std::endl
        : std::cout << "[not found]\n";

    std::partial_sort(v.begin(), v.end(), std::next(std::begin(v), 3));
    cy::print("std::partial_sort, v-> ", v);

    std::sort(v.begin(), v.end(), std::less<>());
    cy::print("std::sort, v-> ", v);

    std::random_device rd;
    std::mt19937 g{rd()};
    std::shuffle(v.begin(), v.end(), g);
    cy::print("std::shuffle, v-> ", v);

    std::reverse(v.begin(), v.end());
    cy::print("std::reverse, v-> ", v);

    std::rotate(v.begin(), v.end()-3, v.end());
    cy::print("std::rotate, v-> ", v);
}

void cy::algo_structure_changer(void)
{
    std::vector<int> v{2,1,3,4,99,88,99,0,-1,99};
    cy::print("original, v-> ", v);

    /// ru
    v.erase(std::remove(v.begin(), v.end(), 99), v.end());
    cy::print("std::remove, v-> ", v);

    v = {2,1,3,4,99,88,99,0,-1,99};
    v.erase(std::unique(v.begin(), v.end()), v.end());
    cy::print("std::unique, v-> ", v);
}

void cy::algo_mover(void)
{
    std::vector<int> v{2,1,3,4,99,88,99,0,-1,99};
    cy::print("original, v-> ", v);

    /// cms
    cy::oformat("std::copy, v-> ");
    std::copy(v.begin(), v.end(),
              std::ostream_iterator<int>(std::cout, " "));
    cy::newline();

    std::list<int> u{1,2};
    std::copy_backward(v.begin(), v.end(), u.end());
    cy::print("std::copy_backward, u-> ", u);

    std::vector<std::thread> vt;
    vt.emplace_back(cy::func, 1);
    vt.emplace_back(cy::func, 2);
    vt.emplace_back(cy::func, 3);
    std::list<std::thread> lt;
    std::move(vt.begin(), vt.end(), std::back_inserter(lt));
    cy::oformat("std::move, lt->\n");
    for(auto& t : lt) t.join();
    cy::newline();

    using container = std::vector<std::string>;
    container m {"hello", "world"};
    container n {"zhang", "liang"};
    std::move_backward(m.begin(), m.end(), n.end());
    cy::print("std::move_backward, m-> ", m);
    cy::print("std::move_backward, n-> ", n);

    m = {"hello", "world"};
    n = {"zhang", "liang"};
    std::swap_ranges(m.begin(), m.end(), n.begin());
    cy::print("std::swap_ranges, m-> ", m);
    cy::print("std::swap_ranges, n-> ", n);
}

void cy::algo_value_modifier(void)
{
    std::vector<int> v{2,1,3,4,99,88,99,0,-1,99};
    cy::print("original, v-> ", v);

    /// figr
    std::fill(v.begin(), v.end(), 1);
    cy::print("std::fill, v-> ", v);

    std::iota(v.begin(), v.end(), 0);
    cy::print("std::iota, v-> ", v);

    std::replace(v.begin(), v.end(), 1, 42);
    cy::print("std::replace, v-> ", v);

    std::srand(std::time(NULL));
    std::function<int(void)> g = [](){ return std::rand()%30; };
    std::generate(v.begin(), v.end(), g);
    cy::print("std::generate, v-> ", v);
}

void cy::algo_set(void)
{
    std::vector<int> v{2,1,3,4,99,88,99,0,-1,99};
    cy::print("original, v-> ", v);

    /// umdis
    using container = std::set<int>;
    container A{1,2,3,4,5,5};
    container B{4,5,6,7,8,8};
    std::vector<int> S;

    S.clear();
    std::set_union(A.begin(), A.end(), B.begin(), B.end(), std::back_inserter(S));
    cy::print("std::set_union, S-> ", S);

    S.clear();
    std::merge(A.begin(), A.end(), B.begin(), B.end(), std::back_inserter(S));
    cy::print("std::merge, S-> ", S);

    S.clear();
    std::set_difference(A.begin(), A.end(), B.begin(), B.end(), std::back_inserter(S));
    cy::print("std::set_diference, S-> ", S);

    S.clear();
    std::set_intersection(A.begin(), A.end(), B.begin(), B.end(), std::back_inserter(S));
    cy::print("std::set_intersection, S-> ", S);

    S.clear();
    std::set_symmetric_difference(A.begin(), A.end(), B.begin(), B.end(), std::back_inserter(S));
    cy::print("std::set_symmetric_difference, S-> ", S);
}

void cy::algo_query_value(void)
{
    std::vector<int> v{2,1,3,4,99,88,99,0,-1,99};
    cy::print("original, v-> ", v);

    /// cai sapr
    int n = std::count(v.begin(), v.end(), 99);
    cy::oformat("std::count, n-> ");
    std::cout << n << std::endl;

    double rv = std::accumulate(v.begin(), v.end(), .0);
    cy::oformat("std::accmulate, rv-> ");
    std::cout << rv << std::endl;

    std::vector<int> u{2,1,3,4,99,88,99,0,-1,99};
    rv = std::inner_product(v.begin(), v.end(), u.begin(), .0);
    cy::oformat("std::inner_product, rv-> ");
    std::cout << rv << std::endl;

    cy::oformat("std::sample, v-> ");
    std::random_device rd;
    std::mt19937 g{rd()};
    std::sample(v.begin(), v.end(),
                std::ostream_iterator<int>(std::cout, " "),
                4, g);
    cy::newline();

    auto it = std::adjacent_find(v.begin(), v.end());
    cy::oformat("std::adjacent_find, it-> ");
    (it != std::end(v))
        ? std::cout << *it << std::endl
        : std::cout << "[not found]\n";

    cy::oformat("std::adjacent_difference, v-> ");
    std::adjacent_difference(v.begin(), v.end(),
                             std::ostream_iterator<int>(std::cout, " "));
    cy::newline();

    cy::oformat("std::partial_sum, v-> ");
    std::partial_sum(v.begin(), v.end(),
                     std::ostream_iterator<int>(std::cout, " "));
    cy::newline();

    // std::reduce
}

void cy::algo_query_property(void)
{
    std::vector<int> v{2,1,3,4,99,88,99,0,-1,99};
    cy::print("original, v-> ", v);

    /// sebfs lem
    // std::transform_inclusive_scan;
    // std::transform_exclusive_scan;
    std::nth_element(v.begin(), v.end(), v.begin()+3);
    cy::print("std::nth_element, v-> ", v);

    auto [mi, ma] = std::minmax_element(v.begin(), v.end());
    cy::oformat("std::minmax_element, min|max-> ");
    (mi != std::end(v) || ma != std::end(v))
        ? std::cout << *mi << ", " << *ma << std::endl
        : std::cout << "[not found]\n";

    int x{42};
    auto lb = std::lower_bound(v.begin(), v.end(), x);
    cy::oformat("std::lower_bound, lb-> ");
    (lb != std::end(v))
        ? std::cout << *lb << std::endl
        : std::cout << "[not found]\n";

    auto ub = std::upper_bound(v.begin(), v.end(), x);
    cy::oformat("std::upper_bound, ub-> ");
    (ub != std::end(v))
        ? std::cout << *ub << std::endl
        : std::cout << "[not found]\n";

    auto it = std::find(v.begin(), v.end(), x);
    cy::oformat("std::find, it-> ");
    (it != std::end(v))
        ? std::cout << *it << std::endl
        : std::cout << "[not found]\n";

    std::vector<int> u{1,3};
    it = std::find_first_of(u.begin(), u.end(), v.begin(), v.end());
    cy::oformat("std::find_first_of, it-> ");
    (it != std::end(v))
        ? std::cout << *it << std::endl
        : std::cout << "[not found]\n";

    it = std::find_end(u.begin(), u.end(), v.begin(), v.end());
    cy::oformat("std::find_end, it-> ");
    (it != std::end(v))
        ? std::cout << *it << std::endl
        : std::cout << "[not found]\n";

    bool rv = std::binary_search(v.begin(), v.end(), x);
    cy::oformat("std::binary_search, rv-> ");
    std::cout << std::boolalpha << rv << std::endl;

    it = std::search(u.begin(), u.end(), v.begin(), v.end());
    cy::oformat("std::search, it-> ");
    (it != std::end(v))
        ? std::cout << *it << std::endl
        : std::cout << "[not found]\n";

    std::string m{"hello world!"};
    std::string n{"o w"};

    rv = std::lexicographical_compare(n.begin(), n.end(), m.begin(), m.end());
    cy::oformat("std::lexicographical_compare, rv-> ");
    std::cout << std::boolalpha << rv << std::endl;

    rv = std::equal(n.begin(), n.end(), m.begin());
    cy::oformat("std::equal, rv-> ");
    std::cout << std::boolalpha << rv << std::endl;

    auto [im, am] = std::mismatch(n.begin(), n.end(), m.begin());
    cy::oformat("std::mismatch, begin|end-> ");
    (im != std::end(m) || am != std::end(m))
        ? std::cout << *im << ", " << *am << std::endl
        : std::cout << "[not found]\n";
}

void cy::algo_raw_memory(void)
{
    std::vector<int> v{2,1,3,4,99,88,99,0,-1,99};
    cy::print("original, v-> ", v);

    /// dvcmf
    cy::oformat("std::raw_memory, -> nothing biggy;\n");
}

void cy::algo_secret_rune(void)
{
    std::vector<int> v{2,1,3,4,99,88,99,0,-1,99};
    cy::print("original, v-> ", v);

    /// if stable n is copy
    cy::oformat("std::secret_rune, -> nothing special;\n");
}

void cy::algo_lone_island(void)
{
    std::vector<int> v{2,1,3,4,99,88,99,0,-1,99};
    cy::print("original, v-> ", v);

    /// ft
    cy::oformat("std::for_each, v-> ");
    std::for_each(v.begin(), v.end(),
                  [](auto const& e)->int{ return e*2; });
    cy::newline();

    cy::oformat("std::transform, v-> ");
    std::transform(v.begin(), v.end(),
                   std::ostream_iterator<int>(std::cout, " "),
                   [](auto const& e)->int{ return e*e; });
    cy::newline();

}

