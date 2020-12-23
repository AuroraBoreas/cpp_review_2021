#include <iostream>
#include <cstdlib>

void message_error(char*), message(char*),
     message_up(char*),    message_low(char*),
     (*funcPtr[])(char*) = { message_error, message,
                             message_up, message_low };

char call[]   = "index out of range\n";
char hello[]  = "Bonjour tout le monde!\n";
char prompt[] = "\nChoose your number btwn(1,2,3): ";

int main()
{
    std::cout << prompt;

    unsigned int n;
    while(std::cin >> n)
    {
        if(n<1 || n>3)
        {
            (*funcPtr[0])(call);
            break;
        }
        else
        {
            (*funcPtr[n])(hello);
            std::cout << prompt;
        }
    }

    return 0;
}

void message_error(char* s)
{
    std::cout << s << std::endl;
}

void message(char* s)
{
    std::cerr << s << std::endl;
}

void message_up(char* s)
{
    char c;
    for(; *s != '\0'; ++s)
    {
        c = std::toupper(*s); std::cout.put(c);
    }
}

void message_low(char* s)
{
    char c;
    for(; *s != '\0'; ++s)
    {
        c = std::tolower(*s); std::cout.put(c);
    }
}
