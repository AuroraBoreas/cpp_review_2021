#include <iostream>
#include <string>
#include <cstdlib>

void hello(const std::string&, unsigned int);

std::string prompt = "\nEnter your name "
                     "(press ctrl + c to quit) : ";

int main()
{
    std::cout << prompt;
    std::string name;
    unsigned int len;
    while(getline(std::cin, name))
    {
        if(std::cin.bad())
            break;
        else
        {
            len = name.size();
            if(len<1)
            {
                std::cerr << "name is empty" << std::endl;
                return -1;
            }
            hello(name, len);
            std::cout << prompt;
        }
    }

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
