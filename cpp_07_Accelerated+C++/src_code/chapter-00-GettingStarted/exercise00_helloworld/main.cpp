#include <iostream>
#include <string>

void hello(const std::string&, unsigned int);

int main()
{
    std::cout << "\nEnter your first name: ";
    std::string name;
    getline(std::cin, name);
    unsigned int len = name.size(); // or size?
    hello(name, len);

    return 0;
}

void hello(const std::string& s, unsigned int len)
{
    unsigned int pad = 12,
                 ttl = len + pad;

    std::string line(ttl, '*'); // string constructor, fill
    std::string blank(ttl-4, ' ');
    std::string hello = "Hello, " + s + "!";
    std::string left_head("* ");
    std::string right_head(" *");

    std::cout << "\n";
    std::cout << line << std::endl;
    std::cout << left_head << blank << right_head << std::endl;
    std::cout << left_head << hello << right_head << std::endl;
    std::cout << left_head << blank << right_head << std::endl;
    std::cout << line << std::endl;
}
