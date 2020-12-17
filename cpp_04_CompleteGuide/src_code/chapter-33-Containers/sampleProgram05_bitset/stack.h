#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

template<class T>
class Stack
{
private:
    T* basePtr;
    unsigned int max, tip;
public:
    // constructor
    Stack(unsigned int n)
    {
        basePtr = new T[n];
        max = n;
        tip = 0;
    }
    // destructor
    ~Stack(){ delete[] basePtr; }
    // empty?
    bool empty(void) const { return (tip==0); }
    // push
    bool push(const T& x)
    {
        if(tip < (max-1))
        {
            basePtr[tip++] = x;
            return true;
        }
        return false;
    }
    // pop
    bool pop(T& x)
    {
        if(tip > 0)
        {
            x = basePtr[--tip];
            return true;
        }
        return false;
    }
    // copy constructor?
};

#endif // STACK_H_INCLUDED
