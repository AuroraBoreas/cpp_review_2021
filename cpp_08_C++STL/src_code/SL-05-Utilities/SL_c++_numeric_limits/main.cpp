/*
SL c++ numeric limits

+ header file <limits>
    - covers
        <climits>
        <limits.h>
        <cfloat>
        <float.h>

    - advantages:
        1. offers more type safety.(why?)
        2. enables a programmer to write templates that evaluate limits. (why?)

    - template usage:
        1. use templates to implement something once for any type.
        2. use templates to provide a common interface that is implemented for each type.

    - specializations of the template source code:

        ```c++

        namespace std
        {
            template<> class numeric_limits<int>
            {
                public:

                static constexpr bool is_specialized = true;

                static constexpr int min() noexcept
                { return -2147483648; }

                static constexpr int max() noexcept
                { return 2147483648; }

                static constexpr int digit = 31;
                ...
            }
        }

        ```

    - numeric member list
        is_specialized
        is_signed
        is_integer
        is_exact
        is_bounded
        is_modulo
        is_iec559

        min()

        max()
        lowest()

        digits
        digits10
        max_digits10

        radix

        min_exponent
        max_exponent
        min_exponent10
        max_exponent10

        epsilon()

        round_style
        round_error()

        has_infinity
        infinity()

        has_quiet_NaN
        quiet_NaN()

        has_signaling_NaN
        signaling_Nan()

        has_denorm
        has_Denorm_loss

        denorm_min()
        traps
        tinyness_before

    - full specialization

        ```c++
        namespace std
        {
            template<> class numeric_limits<float>
            {
                public:
                    static constexpr bool is_special = true;

                    inline constexpr float min() noexcept
                    { return 1.17549435E-38F; }

                    inline constexpr float max() noexcept
                    { return 3.40282347E+38F; }

                    inline constexpr float lowest() noexcept
                    { return -3.40282347E+38F; }

                    static constexpr int digits = 24;
                    static constexpr int digits10 = 6;
                    static constexpr int max_digit10 = 9;

                    static constexpr bool is_signed  = true;
                    static constexpr bool is_integer = false;
                    static constexpr bool is_exact   = false;
                    static constexpr bool is_bounded = true;
                    static constexpr bool is_modulo  = false;
                    static constexpr bool is_iec559  = true;

                    static constexpr int radix = 2;

                    inline constexpr float epsilon() noexcept
                    { return 1.19209290E-07F; }

                    static constexpr float_round_style round_style = round_to_nearest;

                    inline constexpr float round_error() noexcept
                    { return 0.5F; }

                    static constexpr int min_exponent = -125;
                    static constexpr int max_exponent = +128;
                    static constexpr int min_exponent10 = -37;
                    static constexpr int max_exponent10 = +38;

                    static constexpr bool has_infinity = true;
                    static constexpr float infinity() noexcept
                    { return ...; }
                    static constexpr bool has_quiet_NaN = true;
                    static constexpr float quiet_NaN = true;
                    static constexpr bool has_signaling_NaN = true;
                    static constexpr float signaling_NaN() noexcept
                    { return ...; }
                    static constexpr float_denorm_style has_denorm = denorm_absent;
                    static constexpr bool has_denorm_loss = false;
                    static constexpr float denorm_min() noexcept
                    { return min(); }

                    static constexpr bool traps = true;
                    static constexpr bool tinyness_before = true;
                };
        }

        ```

*/

#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
