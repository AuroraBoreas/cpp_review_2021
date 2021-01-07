#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    ifstream inFile("PBM_NX_YDAS011DNS0101_Panel_MEASURE_20201020.csv");
    string s;
    if(inFile.good())
    {
        while(getline(inFile, s))
            cout << s << endl; std::clog << s << endl;
    }

    char w = cin.get();
}
