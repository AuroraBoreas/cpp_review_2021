#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    string s("hello world!");
    cout << "before s.erase(6): " << s << endl;
    s.erase(7);
    cout << "after s.erase(6) : " << s << endl;

    string here("Here they go again"),
           str("Bob and Bill");

    int pos = here.find("they");
    if(pos != string::npos)
    {
        here.replace(pos, 2, str);
    }
    cout << "after replace: " << here << endl;
    return 0;
}
