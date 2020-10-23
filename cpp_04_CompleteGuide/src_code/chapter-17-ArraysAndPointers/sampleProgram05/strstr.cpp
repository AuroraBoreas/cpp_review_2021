#include <string.h>
#include <iostream>

namespace MyScope // definition
{
    const char* strstr(const char* s1, const char* s2)
    {
        int len = strlen(s2);
        for(; *s1 != '\0'; ++s1)
            if(strncmp(s1, s2, len) == 0)
                //return (char*)s1; // wtf return (char*)
                std::cout << "s1: " << s1 << std::endl;
                std::cout << "s1 address: " << (char*)s1 << std::endl;
                return s1;
        return NULL;
    }
}
