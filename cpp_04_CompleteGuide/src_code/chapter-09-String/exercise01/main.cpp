#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    string s1("As time by ..."),
           s2("goes "),
           by("by");
    // insert s2 in front of "by" in s1
    int by_pos = s1.find(by);
    s1.insert(by_pos, s2);
    cout << s1 << endl;

    // erase the remainder of s1 after the substring "by"
    by_pos = s1.find(by);
    s1.erase(by_pos + by.length());
    cout << s1 << endl;

    // replace the substring "time" in s1 with "Bill"
    string subs_time("time"),
           subs_bill("Bill");
    int time_startpos = s1.find(subs_time);
    s1.replace(time_startpos, subs_time.length(), subs_bill);
    cout << s1 << endl;

    return 0;
}
