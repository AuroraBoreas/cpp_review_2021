#include <iostream>
#include <string>
#include <vector>

typedef std::string::const_iterator strIter; // good to know

std::vector<std::string> split(const std::string& s, const char& delimiter);

bool isPalindrome(const std::string& s);

int main()
{
    std::string eye = "eye", die = "die";
    std::cout << isPalindrome(eye) << std::endl;
    std::cout << isPalindrome(die) << std::endl;

    return 0;
}

std::vector<std::string> split(const std::string& s, const char& delimiter)
{
    std::vector<std::string> result;
    strIter it = s.begin();
    for(; it != s.end(); ++it)
    {
        if(*it == delimiter){}
            // ...
    }
    return result;
}

bool isPalindrome(const std::string& s)
{
    return std::equal(s.begin(), s.end(), s.rbegin());
}
