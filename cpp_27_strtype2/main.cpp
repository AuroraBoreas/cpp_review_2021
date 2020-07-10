#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    string s1 = "penguin";
    string s2, s3;

    s2 = s1;
    cout << "s2: " << s2 << endl;
    s2 = "buzzard";
    cout << "s2: " << s2 << endl;
    s3 = s1 + s2;
    cout << "s3: " << s3 << endl;
    s1 += s2;
    cout << "s1: " << s1 << endl;
    s2 += " for a day";
    cout << "s2+=\" for a day\" yields s2 = "
         << s2
         << endl;

    return 0;
}
