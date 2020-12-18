#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;

static char* city[] = {"Paris", "London", "Barcelona", "Hollywood" };
static char* key = "New York";

extern "C" int scmp(const void*, const void*);


int main()
{
    qsort(city, 4, sizeof(char*), scmp);

    if(bsearch(&key, city, 4, sizeof(char*), scmp) == NULL)
        cout << "City " << (string)key << " not found.\n";

    return 0;
}

extern "C"
{
    int scmp(const void* s1, const void* s2)
    {
        return strcmp(*(const char**)s1,
                      *(const char**)s2);
    }
}
