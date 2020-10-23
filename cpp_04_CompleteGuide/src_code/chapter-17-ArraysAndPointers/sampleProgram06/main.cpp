#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    if(argc != 3)
    {
        cerr << "Use: hello name1 name2" << endl;
        return 1;
    }
    cout << "hello " << argv[1] << '!' << endl;
    cout << "best wishes \n"
         << "\tyours " << argv[2] << endl;

    return 0;
}
