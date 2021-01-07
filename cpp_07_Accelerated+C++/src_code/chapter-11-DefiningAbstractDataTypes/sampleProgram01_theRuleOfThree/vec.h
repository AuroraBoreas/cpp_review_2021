/*
explicit
+ what?

+ why?

+ how?

class invariant
+ what?
a class invariant is a condition that defines all valid states for an obj.

+ why?
it is a logical condition to ensure the correct working of a class.

+ how?
class invariants MUST hold when an obj is created,
and they MUST be preserved under all operations of the class.

in particular, all class invariants are both preconditions and post-conditions
for all operations or member functions of the class.

*/

#ifndef VEC_H_INCLUDED
#define VEC_H_INCLUDED

#include <memory>
using std::allocator;

template<class T>
class Vec
{
    public:
        typedef T* iterator;
        typedef const T* const_iterator;
        typedef size_t size_type;
        typedef T value_type;

        // constructor
        Vec(){ create(); }
        explicit Vec(size_type n, const T& t=T()){ create(n, t); }

        Vec(const Vec& v) { create(v.begin(), v.end()); }
        Vec& operator=(const Vec& rhs)
        {
            if(&rhs != this)
            {
                uncreate();
                create(rhs.begin(), rhs.end());
            }
            return *this;
        }
        ~Vec(){ uncreate(); }
        // [] op ol, write and read
        T& operator[](size_type i) { return data[i]; }  // write
        const T& operator[](size_type i) const { return data[i]; } // read
        // push_back
        void push_back(const T& t)
        {
            if(avail == limit)
                grow();
            unchecked_append(t);
        }

        size_type size() const { return avail - data; }
        // Iter
        iterator begin() { return data; }
        const_iterator begin() { return data; }
        // Iter
        iterator end() { return avail; }
        const_iterator end() { return avail; }

    private:
        iterator data;
        iterator avail;
        iterator limit;
        // facilities for memory allocation
        allocator<T> alloc; // obj to handle memory allocation
        // allocate and initialize the underlying array
        void create();
        void create(size_type, const T&);
        void create(const_iterator, const_iterator);

        // destroy or release memory
        void uncreate();
        // support functions for push_back
        void grow();
        void unchecked_append(const T&);
};

template<class T>
void Vec<T>::create()
{
    data = avail = limit = 0;
}

template<class T>
void Vec<T>::create(size_type n, const T& val)
{
    data = alloc.allocate(n);
    limit = avail = data + n;
    uninitialized_fill(data, limit, val); // what is uninitialized_fill?
}

template<class T>
void Vec<T>::create(const_iterator i, const_iterator j)
{
    data = alloc.allocate(j - i);
    limit = avail = uninitialized_copy(i, j, data);
}

template<class T> void Vec<T>::uncreate()
{
    if(data)
    {
        iterator it = avail;
        while(it != data)
            alloc.destroy(--it);
        // return all the storage that was allocated
        alloc.deallocate(data, limit-data);
    }
    // reset pointers to indicate that the Vec is empty again
    data = limit = avail = 0;
}

template<class T> void Vec<T>::grow()
{
    // when growing, allocate twice as much space as currently in use
    size_type new_size = max(2*(limit - data), ptrdiff_t(1));

    // allocate new space and copy existing elements to the new space
    iterator new_data = alloc.allocate(new_size);
    iterator new_avail = uninitialized_copy(data, avail, new_data);

    // return the old space
    uncreate();

    // reset pointers to point to the newly allocated space
    data  = new_data;
    avail = new_avail;
    limit = data + new_size;
}

template<class T> void Vec<T>::unchecked_append(const T& val)
{
    alloc.construct(avail++, val);
}











































#endif // VEC_H_INCLUDED
