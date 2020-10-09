#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    int ac(32);
    const int limit(256);
    const int step(20);

    while(true)
    {
        cout << "\nCharacter Decimal Hexadecimal\n\n";
        int upper;
        for(upper = ac + step; ac < upper && ac < limit; ++ac)
        {
            cout << " " << (char)ac
                 << setw(10) << dec << ac
                 << setw(10) << hex << ac << endl;
        }
        if (upper >= limit) { break; }
        cout <<"\nGo on -> <return>,Stop -> <q>+<return>";
        char answer;
        cin.get(answer);
        if(answer == 'q' || answer == 'Q') { break; }
        cin.sync(); // clear input buffer
    }

    return 0;
}
