#include <iostream>
#include <string>
#include "article.h"

using namespace std;

int main()
{
    Article a1(100, "hello world", 99.99),
            a2(a1);

    a2.setName("fuck u");
    a1.print();
    a2.print();

    Article a3 = a2;
    a3.setName("");
    a3.print();

    return 0;
}
