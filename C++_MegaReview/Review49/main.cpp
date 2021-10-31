#include "algo.h"
#include "visitor.h"
#include "graphic.h"
#include <vector>

typedef void (*func_ptr)(char* s);

void print_msg(char*);


int main()
{
    std::cout << "typedef(C++) vs delegate(C#)" << std::endl;

    func_ptr fp = print_msg;

    char msg[] = "hello world";
    fp(msg);

    std::cout << "\n===Visitor Design Patter===" << std::endl;
    Visitor v = Visitor();
    Dot d = Dot();
    Shape s = Shape();
    Graphic* h;
    h = &d;
    h->accept(&v);
    h = &s;
    h->accept(&v);

    TS::newline();

    Graphic *g[] = {&d, &s};
    for(int i=0; i<2; ++i)
    {
        g[i]->accept(&v);
    }

    TS::newline();

    std::vector<Graphic*> u{&d, &s};
    std::for_each(u.begin(),
                  u.end(),
                  [&](const Graphic* e){ e->accept(&v);}
    );

    std::cin.get();

    return 0;
}

void print_msg(char* s)
{
    std::cout << s << std::endl;
}
