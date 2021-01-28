/*

SL c++ type traits
(P122)

@ZL, 20210121

+ purpose:
    - a type trait provides a way to deal with the properties of a type
    - it is a template,
    - which at compile time yields a specific type or value
    - based on one or more passed template args,
    - which are usually types

+ examples:



+ in detail:
    defined in <type_traits>

    namespace std
    {
        template<typename T, T val>
        struct integral_constant
        {
            static constexpr T value = val;
            typedef T value_type;
            typedef integral_constant<T, v> type;
            constexpr operator value_type()
            { return value; }
        };

        typedef integral_constant<bool, true> true_type;
        typedef integral_constant<bool, false> false_type;
    }

    - Trait         Effect
    is_void<T>

    is_integral<T>
    is_floating_point<T>
    is_arithmetic<T>
    is_signed<T>
    is_unsigned<T>

    is_const<T>
    is_volatile<T>

    is_array<T>
    is_enum<T>
    is_union<T>
    is_class<T>
    is_function<T>

    is_reference<T>
    is_lvalue_reference<T>
    is_rvalue_reference<T>
    is_pointer<T>

    is_member_pointer<T>
    is_member_object_pointer<T>
    is_member_function_pointer<T>

    is_fundamental<T>   // fundamental types: void, integral, floating-point, std::nullptr_t

    is_scalar<T> // integral, floating-point, enum, pointer, member pointer, std::nullptr_t

    is_object<T> // any type except void, function, or reference

    is_compound<T> // array, enum, union, class, function, reference, or pointer

    is_trivial<T>
    is_trivially_copyable<T>
    is_standard_layout<T>
    is_pod<T>

    is_literal_type<T>


    is_empty<T>
    is_polymorphic<T>
    is_abstract<T>

    has_virtual_destructor<T>
    is_default_constructor<T>
    is_copy_constructor<T>
    is_move_constructor<T>
    is_copy_assignable<T>
    is_move_assignable<T>
    is_destructible<T>

    is_trivially_default_constructible<T>
    is_trivially_copy_constructible<T>
    is_trivially_move_constructible<T>
    is_trivially_copy_assignable<T>
    is_trivially_move_assignable<T>
    is_trivially_destructible<T>

    is_nothrow_default_constructible<T>
    is_nothrow_copy_constructible<T>
    is_nothrow_move_constructible<T>
    is_nothrow_copy_assignable<T>
    is_nothrow_move_assignable<T>
    is_nothrow_destructible<T>


+ type modifiers
    - allow u to modify types: modify(add or remove) type properties that does not exist or if exists already.

    - Trait                 Effect
    remove_const<T>
    remove_reference<T>
    remove_volatile<T>
    remove_cv<T>            // cv shorts for const_volatile
    remove_pointer<T>

    add_const<T>
    add_pointer<T>
    add_lvalue_reference<T>
    add_rvalue_reference<T>
    add_volatile<T>
    add_cv<T>

    make_signed<T>
    make_unsigned<T>


+ other type traits
    - trait             effect
    rank<T>
    extent<T, I=0>
    remove_extent<T>
    remove_all_extent<T>

    underlying_type<T>

    decay<T>
    enable_if<B, T=void>
    conditional<B, T, F>
    common_type<T1, ...>
    result_of<F, ArgTypes>
    alignment_of<T>
    alignment_storage<Len>
    alignment_storage<Len, Align>
    alignment_union<Len, Types...>


*/

#include <iostream>
#include <type_traits>
#include <string>

template<typename T>
void foo1(const T& val)
{
    if(std::is_pointer<T>::value)
    {
        std::cout << "foo() called for a pointer" << std::endl;
    }
    else
    {
        std::cout << "foo() called for a value" << std::endl;
    }
}

// but, u can't do something like:
template<typename T>
void foo2(const T& val)
{
    std::cout << (std::is_pointer<T>::value? *val: val) << std::endl;
}

// then, how to make it work if we really wanna do implement it?
template<typename T>
void foo_impl(const T& val, std::true_type)
{
    std::cout << "foo() called for pointer to " << *val << std::endl;
}

template<typename T>
void foo_impl(const T& val, std::false_type)
{
    std::cout << "foo() called for value to " << val << std::endl;
}

// the power of type traits comes more from
// the fact that they are `building blocks` for generic code
template<typename T>
void foo(const T& val)
{
    foo_impl(val, std::is_pointer<T>());
}

// flexible overloading for integral types
// (124)



int main()
{
    {
        // example 01
        int x1 = 42;
        foo1(x1);
        int* x2 = &x1;
        foo1(x2);

        foo1(12); // OK

        // example 02
        // foo2(x1); // not OK. u can't dereference a int var

        // example 03
        foo(12); // OK now

    }

    // type traits and effects
    {
        std::is_assignable<int, int>::value; // false;
        std::is_assignable<int&, int>::value; // true;
        std::is_assignable<int&&, int>::value; // false;
        std::is_assignable<long&, int>::value; // true;
        std::is_assignable<int&, void*>::value; // false;
        std::is_assignable<void*, int>::value; // false;
        std::is_assignable<const char*, std::string>::value; // false;
        std::is_assignable<std::string, const char*>::value; // true;


        std::is_constructible<int>::value;              // true;
        std::is_constructible<int, int>::value;         // true;
        std::is_constructible<long, int>::value;        // true;
        std::is_constructible<int, void*>::value;       // false;
        std::is_constructible<void*, int>::value;       // false;
        std::is_constructible<const char*, std::string>::value; // false
        std::is_constructible<std::string, const char*>::value; // true
        std::is_constructible<std::string, char*, int, int>::value; // true

        // std::use_allocator<> is defined in <memory>;
    }

    // Type modifiers
    {
        typedef int T;
        // add
        std::add_const<T>::type;    // const int
        std::add_pointer<T>::type;  // int*
        std::add_lvalue_reference<T>::type; // int&
        std::add_rvalue_reference<T>::type; // int&&
        // make
        std::make_signed<T>::type;  // int
        std::make_unsigned<T>::type; // unsigned int
        // remove
        std::remove_const<T>::type; // int
        std::remove_pointer<T>::type; // int
        std::remove_reference<T>::type; // int

        // whereas
        typedef const int& T;
        // add
        std::add_const<T>::type;    // const int&
        std::add_lvalue_reference<T>::type; // const int& <- no effect
        std::add_rvalue_reference<T>::type; // const int& <- no effect
        std::add_pointer<T>::type;  // const int*
        // make
        std::make_signed<T>::type;  // undefined behavior
        std::make_unsigned<T>::type;    // undefined behavior
        // remove
        std::remove_const<T>::type;     // const int&
        std::remove_reference<T>::type; // const int
        std::remove_pointer<T>::type;   // const int&
    }

    // other type traits
    {
        // example
        // get dimensions
        std::rank<int>::value;          // 0
        std::rank<int[]>::value;        // 1
        std::rank<int[5]>::value;       // 1
        std::rank<int[][7]>::value;     // 2
        std::rank<int[5][7]>::value;    // 2

        // extent
        std::extent<int>::value;        // 0
        std::extent<int[]>::value;      // 0
        std::extent<int[5]>::value;     // 5
        std::extent<int[][7]>::value;   // 0
        std::extent<int[5][7]>::value;  // 5, default I = 0
        std::extent<int[][7], 1>::value; // 7
        std::extent<int[5][7], 1>::value; // 7
        std::extent<int[5][7], 2>::value; // 0

        std::remove_extent<int>::type;      // int
        std::remove_extent<int[]>::type;    // int
        std::remove_extent<int[5]>::type;   // int
        std::remove_extent<int[][7]>::type; // int[7]
        std::remove_extent<int[5][7]>::type;    // int[7]
        std::remove_all_extents<int>::type;   // int
        std::remove_all_extents<int[]>::type;   // int
        std::remove_all_extents<int[5]>::type;  // int
        std::remove_all_extents<int[][7]>::type; // int
        std::remove_all_extents<int[5][7]>::type; // int

    }


    return 0;
}
