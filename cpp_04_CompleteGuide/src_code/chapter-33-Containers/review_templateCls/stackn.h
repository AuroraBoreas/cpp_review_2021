#ifndef STACKN_H_INCLUDED
#define STACKN_H_INCLUDED

template<class T, unsigned int n>
class Stack
{
    private:
        T arr[n];
        unsigned int max, tip;
    public:
        Stack()
        {
            max = n;
            tip = 0;
        }
        // empty
        bool empty(void) const { return (tip==0); }
        bool push(const T& x)
        {
            if(tip<(max-1))
            {
                arr[tip++] = x; return true;
            }
            return false;
        }
        bool pop(T& x)
        {
            if(tip>0)
            {
                x = arr[--tip]; return true;
            }
            return false;
        }
};


#endif // STACKN_H_INCLUDED
