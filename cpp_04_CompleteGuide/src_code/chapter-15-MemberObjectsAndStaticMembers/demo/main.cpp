#include <iostream>
#include <sstream>
#include <string>
#include "simple.h"
#include "daytime.h"

std::string& convert_int_to_string(int, int, int);

int main()
{
    std::cout << "Hello world!" << std::endl;
    SimpleClass sc1;
    sc1.print();

    DayTime morning(8, 30, 0);
    SimpleClass sc2("bonjour", 300, morning);
    sc2.print();

    std::cout << std::endl;

    int a(1), b(2), c=3;
    std::cout << "a = " << a  << ", b = " << b << ", c = " << c << std::endl;
    std::cout << "convert int to string: " << convert_int_to_string(a, b, c) << std::endl;

    return 0;
}

std::string& convert_int_to_string(int a, int b, int c)
{
    std::stringstream tmp_iostream;
    tmp_iostream << a << ":" << b << ":" << c;
    static std::string str;
    tmp_iostream >> str;
    return str;
}
