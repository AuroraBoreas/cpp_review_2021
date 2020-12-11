#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

template<class T>
class Stack
{
private:
    T* basePtr;
    int tip;
    int max;
public:
    Stack(int n)
    {
        basePtr = new T[n];
        max = n;
        tip = 0;
    }
    ~Stack() { delete[] basePtr; }

    Stack<T>& operator=(const Stack<T>&);

    bool empty(){ return (tip==0); }
    bool push(const T& x);
    bool pop(T& x);
};

#endif // STACK_H_INCLUDED
