#include <iostream>

using namespace std;
void line(void), message(void);

int main()
{
    cout << "Hello world! starts in main()" << endl;
    line();
    message();
    line();
    cout << "at the end of main()." << endl;
    return 0;
}


void line()
{
    cout << "---------------------------------" << endl;
}

void message()
{
    cout << "hello CNM! in function message()" << endl;
}
