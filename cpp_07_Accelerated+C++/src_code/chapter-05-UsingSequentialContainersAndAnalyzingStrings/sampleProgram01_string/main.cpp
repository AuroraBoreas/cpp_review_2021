#include <iostream>
#include <cctype>
#include <cstdlib>

void message_error(char*), message(char*),
     message_upper(char*), message_lower(char*),
     (*funcPtr[])(char*) = { message_error, message, message_upper, message_lower };

char prompt[] = "\nEnter an integer "
                " btwn (1-3): ";

char hello[] = "hell world";
char world[] = "Bonjour tout le monde!";

int main()
{
    std::cout << prompt;
    int n;
    while(std::cin>>n)
    {
        if(n==0)
        {
            (*funcPtr[0])(hello);
        }
        else if(n>=1 && n<=3)
        {
            (*funcPtr[n])(world);
        }
        else
        {
            std::cerr << "index out of range!\n";
            return -1;
        }
        std::cout << prompt;
    }

    return 0;
}

void message_error(char* s)
{
    std::cerr << s << std::endl;
}

void message(char* s)
{
    std::cout << s << std::endl;
}

void message_upper(char* s)
{
    char c;
    for(; *s != '\0'; ++s)
    {
        c = std::toupper(*s); std::cout.put(c);
    }
}

void message_lower(char* s)
{
    char c;
    for(; *s != '\0'; ++s)
    {
        c = std::tolower(*s); std::cout.put(c);
    }

}
