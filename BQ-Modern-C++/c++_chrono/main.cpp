#include <iostream>
#include <chrono>

using namespace std;

int main()
{
    // introduction to <chrono>
    {
        /*
        + <chrono> provides three clocks
            - std::chrono::system_clock;
            - std::chrono::steady_clock;
            - std::chrono::high_resolution_clock;

        + it is similar with time pkg in Python
            - time.time()
            - time.perf_count()
            - time.monotonic_count()

        + select prop of <chrono>
            - chrono::system_clock::period
                >>using std::ratio<> to represent  clock period/frequency
            - chrono::duration<>, a template represents time duration
                >> duration<int, std::ratio<1, 1>>  // number of seconds stored in an int
                >> duration<double, std::ratio<60, 1>>  // number of minutes stored in a double
                >> duration<T, sysmtem_clock::period>

            - chrono::time_point<>; represents a point of time
        */

        // fractions in C++
        std::ratio<1, 10> r;
        std::cout << r.num << "/" << r.den << std::endl;

        // using the same
        std::cout << std::chrono::system_clock::period::num << "/" << std::chrono::system_clock::period::den << std::endl;


        //



    }

    // chrono::duration<>
    {
        std::chrono::microseconds mi(2700); // 2700 microseconds
        std::chrono::nanoseconds na = mi;   // 2700 000 nanoseonds
        std::chrono::milliseconds mill = std::chrono::duration_cast<std::chrono::milliseconds>(mi); // 2 millisecond

        mi = mill + mi;     // 2700 + 2000
        mi.count();         // 4700
    }

    // time point
    {
        std::chrono::system_clock::time_point tp = std::chrono::system_clock::now();
        std::cout << tp.time_since_epoch().count() << std::endl;

        tp = tp + std::chrono::seconds(2);
        std::cout << tp.time_since_epoch().count() << std::endl;

        std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
        std::cout << "XY WAN" << std::endl;
        std::chrono::steady_clock::time_point end_ = std::chrono::steady_clock::now();

        std::chrono::steady_clock::duration d = end_ - start;

        if(d == std::chrono::steady_clock::duration::zero())
            std::cout << "no time elapsed!" << std::endl;
        std::cout << std::chrono::duration_cast<std::chrono::microseconds>(d).count() << std::endl;
    }

    return 0;
}
