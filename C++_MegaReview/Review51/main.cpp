#include "algo.h"
#include "graphic.h"
#include "visitor.h"

typedef void (*func_ptr)(std::vector<char>);
void print_msg(std::vector<char>);

int main()
{
//    std::cout << "Hello world!" << std::endl;
//
//    func_ptr fp = print_msg;
//    std::vector<char> s{'z', 'l', '\n'};
//    fp(s);
//
//    std::function<void(std::vector<char>)> f = print_msg;
//    f(s);

    Shape s = Shape();
    Dot d = Dot();
    Visitor v = Visitor();
    std::vector<Graphic*> g{&d, &s};
//    Graphic* g;
//    g = &s;
//    g->accept(v);
//    g = &d;
//    g->accept(v);
    std::for_each(g.begin(), g.end(),
                  [&](const Graphic* e){ e->accept(v); });


    std::cin.get();

    return 0;
}

void print_msg(std::vector<char> s)
{
    std::transform(s.begin(), s.end(),
                   std::ostream_iterator<char>(std::cout, "\n"),
                   [](char const& e){ return std::toupper(e); });
}
