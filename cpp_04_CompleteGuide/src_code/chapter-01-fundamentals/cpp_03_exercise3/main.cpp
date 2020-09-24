#include <iostream>

using namespace std;
void pause(void);

int main()
{
    cout << "Hello world!" << endl;
    pause();
    cout << "!" << endl;
    return 0;
}

void pause()
{
    cout << "BREAK";
}
