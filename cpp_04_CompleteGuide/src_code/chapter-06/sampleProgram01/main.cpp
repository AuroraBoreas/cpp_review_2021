#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    int x, cnt = 0;
    float sum = 0.0;

    cout << "Please enter some integers:\n"
            "(Break with any letter)"
         << endl;

//    char ch('x');
//    if(cin)
//    {
//        cout << "true";
//    } else {
//        cout << "false";
//    }
    while(cin >> x) // this line is interesting as fuck.
    {
        sum += x;
        // ++cnt;
        cnt++;
    }

    cout << "The average of the numbers: " << sum / cnt << endl;

    return 0;
}
