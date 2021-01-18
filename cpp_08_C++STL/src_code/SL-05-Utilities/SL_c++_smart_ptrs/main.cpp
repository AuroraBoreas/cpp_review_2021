/*

SL smart pointer review

(76)

@ZL, 20210115

+ what is smart pointer?
    - "raw pointer".

        ```c++
        {
            T* ptr = new T[];
            // ...
            delete[] ptr;
        }
        ```

    - "smart pointer"
        - share_ptr<T*> var(new T()); shared ownership, auto-count;
            - also support: weak_ptr, bad_weak_ptr, enable_shared_from_this;
        - unique_ptr<T*> var(new T()); exclusive ownership

+ why?
    - "raw pointer" may cause memory leak, which is not good.

+ how?

*/

#include <iostream>
#include <memory>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
