#ifndef STACKN_H_INCLUDED
#define STACKN_H_INCLUDED

template<class T, int n>
class Stack
{
private:
    T arr[n];
    unsigned int max;
    unsigned int tip;
public:
    Stack()
    {
        max = n;
        tip = 0;
    }
    // empty
    bool empty(void)
    {
        return (tip == 0);
    }
    // push
    bool push(const T& x)
    {
        if(tip<(max-1))
        {
            arr[tip++] = x;
            return true;
        }
        return false;
    }
    // pop
    bool pop(T& x)
    {
        if(tip > 0)
        {
            x = arr[--tip];
            return true;
        }
        return false;
    }
};

#endif // STACKN_H_INCLUDED
