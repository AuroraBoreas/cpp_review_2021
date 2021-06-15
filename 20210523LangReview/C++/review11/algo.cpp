#include "algo.h"

void TS::algo_permutation_heap(void)
{
    inline void o(const std::string& topic)
    { std::cout << "\n=== " << topic << " ===\n"; }

    std::vector<int> v{1, 3, 7, 6, 99, 99, 99, 0, -1, 99, 1};
    TS::print("original, v-> ", v);

    std::make_heap(std::begin(v), std::end(v), std::greater<>{});
    TS::print("std::make_heap, v-> ", v);

    std::pop_heap(v.begin(), v.end(), std::greater<>());
    TS::print("std::pop_heap, v-> ", v);

    v.push_back(42);
    std::push_heap(v.begin(), v.end(), std::less<>{});
    TS::print("std::push_heap, v-> ", v);

    std::prev_permutation(v.begin(), v.end());
    TS::print("std::prev_permutation, v-> ", v);

    std::next_permutation(v.begin(), v.end());
    TS::print("std::next_permutation, v-> ", v);
}

void TS::algo_permutation_sort(void)
{
    std::vector<int> v(10);
    std::srand(std::time(nullptr));
    std::generate(v.begin(), v.end(), [](){ return std::rand()%30; });
    TS::print("original, v-> ", v);

    std::sort(v.begin(), v.end());
    TS::print("std::sort, v-> ", v);

    std::reverse(v.begin(), v.end());
    TS::print("std::reverse, v-> ", v);
    
    std::rorate(v.begin(), std::next(v.begin(), 3), v.end());
    TS::print("std::rotate, v-> ", v);
    
    std::random_device rd;
    std::mt19937_64 mt(rd());
    std::shuffle(v.begin(), v.end(), mt);
    TS::print("std::shuffle, v-> ", v);

    std::partition(v.begin(), v.end(), [](auto& e){ return e%2==0; });
    TS::print("std::partition, v-> ", v);
}

void TS::algo_structure_changer(void)
{
    std::vector<int> v { 1, 2, 99, 99, 99, -1, 0, 99, 1 };
    TS::print("original, v-> ", v);

    v.erase(std::remove(v.begin(), v.end(), 99), v.end());
    TS::print("std::remove, v-> ", v);

    v = { 1, 2, 99, 99, 99, -1, 0, 99, 1 };
    v.erase(std::unique(v.begin(), v.end()), v.end());
    TS::print("std::unique, v-> ", v);
}

void TS::algo_mover(void)
{
    std::vector<int> v(10);
    std::srand(std::time(nullptr));
    std::generate(v.begin(), v.end(), [](){ return std::rand()%20; });
    TS::print("original, v-> ", v);

    std::list<int> l;
    TS::copy(v.begin(), v.end(), std::back_inserter(l));
    TS::print("std::copy, l-> ", l);

    std::vector<std::this_thread> vt;
    vt.emplace_back(TS::func, 1);
    vt.emplace_back(TS::func, 2);
    vt.emplace_back(TS::func, 3);
    std::list<std::this_thread> lt;
    std::move(vt.begin(), vt.end(), std::back_inserter(lt));
    std::cout << "std::move" << std::endl;
    for(auto& t : lt) t.join();

    l.clear();
    std::move_backward(vt.begin(), vt.end(), lt.begin());
    std::cout << "std::move_backward" << std::endl;
    for(auto& t: lt) t.join();

    std::vector<char> vname{'t', 's'};
    std::list<char> lname;
    std::swap_ranges(vname.begin(), vname.end(), std::back_inserter(lname));
    TS::print("std::swap_ranges, lname-> ", lname);
}

void TS::algo_value_modifier(void)
{
    std::vector<int> v;
    std::fill(v.begin(), v.end(), 42);
    TS::print("std::fill, v-> ", v);
    
    std::iota(v.begin(), v.end(), 1);
    TS::print("std::iota, v-> ", v);

    std::srand(std::time(nullptr));
    std::generate(v.begin(), v.end(), [](){ return std::rand()%19; });
    TS::print("std::generate, v-> ", v);

    v = {1,3,99,99,99,0,-1,99,1};
    std::replace(v.begin(), v.end(), 99, 69);
    TS::print("std::replace, v-> ", v);
}

void TS::algo_set(void)
{
    using container = std::vector<int>;
    container A = {1,2,3,4,5};
    conatiner B = {4,5,6,7,8};
    std::set<int> s;
    
    std::set_intersection(a.begin(), a.end(), b.begin(), b.end(), s.begin());
    TS::print("std::set_intersection, s-> ", s);
    
    std::set_union(a.begin(), a.end(), b.begin(), b.end(), s.begin());
    TS::print("std::set_union, s-> ", s);
    
    std::set_difference(a.begin(), a.end(), b.begin(), b.end(), s.begin());
    TS::print("std::set_difference, s-> ", s);
    
    std::set_symmetric_difference(a.begin(), a.end(), b.begin(), b.end(), s.begin());
    TS::print("std::set_symmetric_difference, s-> ", s);
    
    bool rv = std::includes(a.begin(), a.end(), b.begin(), b.end());
    rv
        ? std::cout << "std::includes, rv-> " << std::boolalpha << std::endl
        : std::cout << "[not found]\n";
}

void TS::algo_query_property(void)
{
    // cai sapr
    std::vector<int> v{1,3,99,99,99,0,-1,99,1};
    TS::print("original, v-> ", v);

    int cnt = std::count(v.begin(), v.end(), 99);
    std::cout << "std::count, v has -> " << cnt << std::endl;

    double result = std::accumulate(v.begin(), v.end(), 0.0);
    std::cout << "std::accumulate, v -> " << result << std::endl;

    result = std::inclusive_scan(std::execution::seq, v.begin(), v.end(), 0.0);
    std::cout << "std::inclusive_scan, v -> " << result << std::endl;

    result = std::exclusive_scan(std::execution::seq, v.begin(), v.end(), 0.0);
    std::cout << "std::exclusive_scan, v -> " << result << std::endl;
    
    result = std::reduce(std::execution::par, v.begin(), v.end(), 0.0);
    std::cout << "std::reduce, v-> " << result << std::endl;

    std::vector<int> w{1,3,99,99,99,0,-1,99,1};
    result = std::inner_product(v.begin(), v.end(), w.begin());
    std::cout << "std::inner_product, v-> " << result << std::endl;

    std::random_device rd;
    std::mt19937 mt(rd());
    std::list<int> l;
    std::sample(v.begin(), v.end(), std::back_inserter(l), 3, mt);
    TS::print("std::sample, l-> ", l);

    l.clear();
    std::adjacent_difference(v.begin(), v.end(), std::back_inserter(l));
    TS::print("std::adjacent_difference, l-> ", l);

    l.clear();
    std::partial_sum(v.begin(), std::next(v.begin(), 4), v.end());
    TS::print("std::partial_sum, l-> ", l);  

    std::cout << "std::mismatch()" << std::endl;
    std::cout << "std::equal()" << std::endl;
    std::cout << "std::lexicographical_compare()" << std::endl;   
}

void TS::algo_query_value(void)
{
    std::vector<int> v{1,3,99,99,99,0,-1,99,1};
    TS::print("original, v-> ", v);

    auto it = std::find(v.begin(), v.end(), 3);
    (it != v.end())
        ? std::cout << "std::find, 1st 3 at index of ->" << std::distance(v.begin(), it) << std::endl
        : std::cout << "[not found]\n";
    
    it = std::find_first_of(v.begin(), v.end(), 99);
    (it != v.end())
        ? std::cout << "std::find, 1st 99 at index of ->" << std::distance(v.begin(), it) << std::endl
        : std::cout << "[not found]\n";
    
    it = std::find_end(v.begin(), v.end(), 99);
    (it != v.end())
        ? std::cout << "std::find, last 99 at index of ->" << std::distance(v.begin(), it) << std::endl
        : std::cout << "[not found]\n";
    
    std::sort(v.begin(), v.end());
    bool rv = std::binary_search(v.begin(), v.end(), 99);
    rv
        ? std::cout << "std::binary_search, found 99? -> " << std::boolalpha << rv << std::endl
        : std::cout << "[not found]\n";

    
    std::partition(v.begin(), v.end(), [](auto& e){ return e%2==1; });
    it = std::lower_bound(v.begin(), v.end(), 42);
    (it != v.end())
        ? std::cout << "std::lower_bound, 42 in ->" << std::distance(v.begin(), it) << std::endl
        : std::cout << "[not found]\n";
    
    it = std::upper_bound(v.begin(), v.end(), 42);
    (it != v.end())
        ? std::cout << "std::upper_bound, 42 in ->" << std::distance(v.begin(), it) << std::endl
        : std::cout << "[not found]\n";
    
    it = std::adjacent_find(v.begin(), v.end());
    (it != v.end())
        ? std::cout << "std::adjacent_find, 1st adjacent found at ->" << std::distance(v.begin(), it) << std::endl
        : std::cout << "[not found]\n";

    it = std::min_element(v.begin(), v.end());
    (it != v.end())
        ? std::cout << "std::min_element, found at ->" << std::distance(v.begin(), it) << std::endl
        : std::cout << "[not found]\n";

    it = std::max_element(v.begin(), v.end());
    (it != v.end())
        ? std::cout << "std::min_element, found at ->" << std::distance(v.begin(), it) << std::endl
        : std::cout << "[not found]\n";

    auto [mi, ma] = std::minmax_element(v.begin(), v.end());
    (it != v.end())
        ? std::cout << "std::minmax_element, min ->" << mi << ", max -> " << ma << std::endl
        : std::cout << "[not found]\n";
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

    std::cout << "raw memory, nothing special, nothing biggy" << std::endl;
}

void TS::algo_secret_rune(void)
{
    /*
    - *_if
    - stable_*
    - is_*
    - is_*_until
    - *_copy
    - *_n    
    */
    std::cout << "secret runes, nothing special, nothign biggy" << std::endl;
}

void TS::algo_lone_island(void)
{
    std::vector<int> v(10);
    std::srand(std::time(nullptr));
    std::generate(v.begin(), v.end(), [](){ return std::rand()%30; });

    std::cout << "std::for_each" << std::endl;
    std::for_each(v.begin(), v.end(), [](const auto& e){
        std::cout << e << TS::b;
    });
    std::cout << std::endl;

    std::vector<char> name{'t', 'a', 'n', 'g', 's', 'a', 'i'};
    std::list<char> l;
    std::transform(name.begin(), name.end(), std::back_inserter(l), [](auto const& e){
        return std::toupper(e);
    });
    std::cout << "std::transform" << std::endl;
    std::copy(l.begin(), l.end(), std::ostream_iterator<char>(std::cout, TS::b));
    std::cout << std::endl;
}

