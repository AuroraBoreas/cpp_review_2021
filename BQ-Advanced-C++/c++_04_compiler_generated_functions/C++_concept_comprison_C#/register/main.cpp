#include <iostream>
#include <cstdlib>
#include <stdexcept>

void message(char*), message_up(char*), message_low(char*), message_error(char*);

typedef void (*CallBack)(char*);


int main()
{
    CallBack mregister[] = { message, message_error, message_up, message_low };

    char s[] = "hello world";
    mregister[0](s);
    mregister[1](s);
    mregister[2](s);
    mregister[3](s);

    return 0;
}

void message(char* s)
{ std::cout << s << std::endl; }

void message_up(char* s)
{
    char c;
    for(; *s != '\0'; ++s)
    { c = std::toupper(*s); std::cout.put(c); }
    std::cout << std::endl;
}

void message_low(char* s)
{
    char c;
    for(; *s != '\0'; ++s)
    { c = std::tolower(*s); std::cout.put(c); }
    std::cout << std::endl;
}

void message_error(char* s)
{ std::cerr << s << std::endl; }
