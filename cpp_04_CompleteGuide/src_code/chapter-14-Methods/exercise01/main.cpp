#include <iostream>
#include "article.h"

using namespace std;

Article globalArtical1(100000, "fucku", 99.99);

void test(Article a);

int main()
{
    Article a1(100001, "hello world!", 10.0);

    test(globalArtical1);
    test(a1);

    return 0;
}

void test(Article a)
{
    a.print();
}
