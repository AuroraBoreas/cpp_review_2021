#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

template<class T>
class Stack
{
private:
    T* basePtr;
    int max;
    int tip;
public:
    // constructor
    Stack(int n)
    {
        basePtr = new T[n];
        max = n;
        tip = 0;
    }
    // destructor
    virtual ~Stack(){ delete[] basePtr; }
    // assignment constructor
    Stack<T>& operator=(const Stack<T>&);

    // methods: empty? push? pop?
    bool empty(void)
    {
        return (tip==0);
    }
    bool push(const T& t)
    {
        if(tip < max - 1)
        {
            basePtr[tip++] = t;
            return true;
        }
        return false;
    }
    bool pop(T& t)
    {
        if(tip > 0)
        {
            t = basePtr[--tip];
            return true;
        }
        return false;
    }
};

#endif // STACK_H_INCLUDED
