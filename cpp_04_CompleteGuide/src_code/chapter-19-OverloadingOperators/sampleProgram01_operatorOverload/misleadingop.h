#ifndef MISLEADINGOP_H_INCLUDED
#define MISLEADINGOP_H_INCLUDED

class MyClass
{
    private:
        int a;
    public:
        MyClass(int i) : a(i) { }
        bool operator<(const MyClass& z) { return this->a >= z.a; } // ???
        int operator+(const MyClass& z)  { return this->a - z.a; } // ???
};

#endif // MISLEADINGOP_H_INCLUDED
