#include "algo.h"

void TS::algo_permutation_heap(void)
{
    std::vector<int> v{2,1,3,99,99,99,0,-1,99,99,1};
    TS::print("original, v-> ", v);

    std::make_heap(v.begin(), v.end(), std::greater<>{});
    TS::print("std::make_heap, v-> ", v);

    std::pop_heap(v.begin(), v.end());
    TS::print("std::pop_heap, v-> ", v);

    v.push_back(42);
    std::push_heap(v.begin(), v.end(), std::less<>{});
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
    std::vector<int> v{2,1,3,99,99,99,0,-1,99,99,1};
    TS::print("original, v-> ", v);

    std::sort(v.begin(), v.end());
    TS::print("std::sort, v-> ", v);

    std::partial_sort(v.begin(), std::next(v.begin(), 3), v.end());
    TS::print("std::partial_sort, v-> ", v);

    std::partition(v.begin(), v.end(), [](const auto& e){ return e%2==0; });
    TS::print("std::partition, v-> ", v);

    std::rotate(v.begin(), v.begin() + 3, v.end());
    TS::print("std::rorate, v-> ", v);

    std::reverse(v.begin(), v.end());
    TS::print("std::reverse, v-> ", v);

    std::random_device rd;
    std::mt19937 mt{rd()};
    std::shuffle(v.begin(), v.end(), mt);
    TS::print("std::shuffle, v-> ", v);

    auto it = std::partition_point(v.begin(), v.end(), TS::IsEven());
    TS::o("std::partition_point, v-> ");
    (it != std::end(v))
        ? std::cout << *it << std::endl
        : std::cout << "[not found]\n";
}

void TS::algo_structure_changer(void)
{
    std::vector<int> v{2,1,3,99,99,99,0,-1,99,99,1};
    TS::print("original, v-> ", v);

    v.erase(std::remove(v.begin(), v.end(), 99), v.end());
    TS::print("std::remove, v-> ", v);

    v.erase(std::unique(v.begin(), v.end()), v.end());
    TS::print("std::unique, v-> ", v);
}

void TS::algo_mover(void)
{
    std::vector<int> v{2,1,3,99,99,99,0,-1,99,99,1};
    TS::print("original, v-> ", v);

    TS::o("std::copy, v-> ");
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    TS::newline();

    std::vector<std::thread> vt;
    vt.emplace_back(TS::func, 1);
    vt.emplace_back(TS::func, 2);
    vt.emplace_back(TS::func, 3);
    std::list<std::thread> lt;
    std::move(vt.begin(), vt.end(), std::back_inserter(lt));
    for(auto& t : lt) t.join();

    std::list<int> l;
    std::copy_backward(v.begin(), v.end(), l.end());
    TS::print("std::copy_backward, v-> ", v);

    std::string m = "hello world";
    std::string n = "zhang liang";
    std::move_backward(m.begin(), m.end(), n.end());
    TS::o("std::move_backward, n-> ");
    std::cout << n << std::endl;

//    TS::o("std::swap_ranges, -> ");
//    std::swap_ranges(m.begin(), n.end(), n.end());
//    std::cout << m << std::endl;
//    std::cout << n << std::endl;
}

void TS::algo_value_modifier(void)
{
    std::vector<int> v(10);
    std::fill(v.begin(), v.end(), 42);
    TS::print("std::fill, v-> ", v);

    v.clear();
    std::iota(v.begin(), v.end(), 1);
    TS::print("std::iota, v-> ", v);

    v.clear();
    std::random_device rd;
    std::mt19937 g{rd()};
    std::generate(v.begin(), v.end(), g);
    TS::print("std::generate, v-> ", v);

    std::vector<int> w{2,1,3,99,99,99,0,-1,99,99,1};
    std::replace(w.begin(), w.end(), 99, 42);
    TS::print("std::replace, w-> ", w);
}

void TS::algo_set(void)
{
    using container = std::set<int>;
    container A {1,2,3,4,5};
    container B {4,5,6,7,8};
    std::vector<int> S;

    std::set_union(A.begin(), A.end(), B.begin(), B.end(), std::back_inserter(S));
    TS::print("std::union, S-> ", S);

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
    TS::o("std::includes, -> ");
    std::cout << std::boolalpha << rv << std::endl;
}

void TS::algo_query_property(void)
{
    // 2-ranges: equal, lexicographic_compare, mismatch
    std::string in = "Ad sit magna velit cupidatat tempor ullamco proident et.";
    std::string ou = "sit";
    bool rv = std::equal(ou.begin(), ou.end(), in.begin());
    TS::o("std::equal, v-> ");
    std::cout << std::boolalpha << rv << std::endl;

    rv = std::lexicographical_compare(ou.begin(), ou.end(), in.begin(), in.end());
    TS::o("std::lexicographical_compare, v-> ");
    std::cout << std::boolalpha << rv << std::endl;

    auto [mi, ma] = std::mismatch(ou.begin(), ou.end(), in.begin());
    TS::o("std::mismatch, v-> ");
    (mi != std::end(in) && ma != std::end(in))
        ? std::cout << *mi << *ma << std::endl
        : std::cout << "[not found]\n";

    // *_of: any_of, none_of, all_of
    std::vector<int> v{2,1,3,99,99,99,0,-1,99,99,1};
    rv = std::any_of(v.begin(), v.end(), TS::IsEven());
    TS::o("std::any_of, v-> ");
    std::cout << std::boolalpha << rv << std::endl;

    rv = std::all_of(v.begin(), v.end(), TS::IsEven());
    TS::o("std::all_of, v-> ");
    std::cout << std::boolalpha << rv << std::endl;

    rv = std::none_of(v.begin(), v.end(), TS::IsEven());
    TS::o("std::none_of, v-> ");
    std::cout << std::boolalpha << rv << std::endl;

    // *_bound: upper_bound, lower_bound
    auto it = std::lower_bound(v.begin(), v.end(), 3);
    TS::o("std::lower_bound, v-> ");
    (it != std::end(v))
        ? std::cout << *it << std::endl
        : std::cout << "[not found]\n";

    it = std::upper_bound(v.begin(), v.end(), 3);
    TS::o("std::upper_bound, v-> ");
    (it != std::end(v))
        ? std::cout << *it << std::endl
        : std::cout << "[not found]\n";

    // *_element: nth_element, min_element, max_element
    it = std::min_element(v.begin(), v.end());
    TS::o("std::min_element, v-> ");
    (it != std::end(v))
        ? std::cout << *it << std::endl
        : std::cout << "[not found]\n";

    it = std::max_element(v.begin(), v.end());
    TS::o("std::max_element, v-> ");
    (it != std::end(v))
        ? std::cout << *it << std::endl
        : std::cout << "[not found]\n";

    auto [im, am] = std::minmax_element(v.begin(), v.end());
    TS::o("std::minmax_element, v-> ");
    (im != std::end(v) && am != std::end(v))
        ? std::cout << *im << ", " << *am << std::endl
        : std::cout << "[not found]\n";

    std::nth_element(v.begin(), std::next(v.begin(), 3), v.end(), std::greater<>{});
    TS::print("std::nth_element, v-> ", v);
}

void TS::algo_query_value(void)
{
    std::vector<int> v{2,1,3,99,99,99,0,-1,99,99,1};
    // find, find_end, find_first_of

    // search, binary_search, search_n

    // cai sapr
    int cnt = std::count(v.begin(), v.end(), 99);
    TS::o("std::count, v-> ");
    std::cout << cnt << std::endl;

    TS::o("std::adjacent_difference, -> ");
    std::adjacent_difference(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    TS::newline();

    auto it = std::adjacent_find(v.begin(), v.end());
    TS::o("std::adjacent_find, -> ");
    (it != std::end(v))
        ? std::cout << *it << std::endl
        : std::cout << "[not found]\n";

    double result = std::accumulate(v.begin(), v.end(), 0.0);
    TS::o("std::accumulate, -> ");
    std::cout << result << std::endl;

//    result = std::reduce(v.begin(), v.end(), 0.0);
//    TS::o("std::reduce, -> ");
//    std::cout << result << std::endl;


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

    std::cout << "raw memory -> nothin biggy" << std::endl;
}

void TS::algo_secret_rune(void)
{
    /*
    - *_if
    - stable_*
    - is_*
    - is_*_until
    - *_n
    - *_copy
    */
    std::cout << "secret rune -> nothing biggy" << std::endl;
}

void TS::algo_lone_island(void)
{
    std::vector<int> v{2,1,3,99,99,99,0,-1,99,99,1};

    TS::o("std::for_each, v-> ");
    std::for_each(v.begin(), v.end(), [](auto const& e){
                    std::cout << e << " ";
                  });
    TS::newline();

    TS::o("std::transform, v-> ");
    std::transform(v.begin(), v.end(),
                std::ostream_iterator<int>(std::cout, " "),
                [](auto const& e){ return e*e; });
    TS::newline();
}

