#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class IsEven
{
    private:
        int x;
    public:
        IsEven(int i): x(i) {}
        bool operator()()
        {
            return !(x % 2);
        }
};

int main()
{
    std::vector<int> v{1, 2, 3, 4, 5};
    size_t c;
    // lambda
    c = count_if(v.begin(), v.end(), [](int x){ return !(x%2); });
    std::cout << c << std::endl;
    // two more statement lambda
    c = count_if(v.begin(),
                 v.end(),
                 [](int x)->bool
                 {
                     bool res = (x%2);
                     std::cout << x << " is " << (res?"odd": "even") << std::endl;
                     return !res;
                 });
    std::cout << c << std::endl;

    // capture args by vale or ref
    int sum = accumulate(v.begin(), v.end(), 0);
    sum = 0;
    auto f = [&](int x){ return sum += x; };
    for(auto it = v.begin(); it != v.end(); ++it)
    {
        f(*it);
    }
    std::cout << sum << std::endl;

    return 0;
}
