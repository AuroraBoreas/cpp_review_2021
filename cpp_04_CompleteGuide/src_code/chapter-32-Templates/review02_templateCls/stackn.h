#ifndef STACKN_H_INCLUDED
#define STACKN_H_INCLUDED

template<class T, int n>
class Stack
{
private:
    T arr[n];
    unsigned int tip;
    unsigned int max;
public:
    // constructor
    Stack()
    {
        max = n;
        tip = 0;
    }
    bool empty()
    {
        return (tip==0);
    }
    bool pop(T& x)
    {
        if(tip>0)
        {
            x = arr[--tip];
            return true;
        }
        return false;
    }
    bool push(const T& x)
    {
        if(tip<max-1)
        {
            arr[tip++] = x;
            return true;
        }
        return false;
    }

};

#endif // STACKN_H_INCLUDED
