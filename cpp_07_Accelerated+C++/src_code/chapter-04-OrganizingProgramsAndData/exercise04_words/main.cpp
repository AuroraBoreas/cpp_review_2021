#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <set>

using std::string;
using std::vector;
using std::istream;
using std::cout;
using std::cin;
using std::endl;
using std::set;

typedef vector<string> VecStr;
typedef set<string> SetStr;

istream& readWords(istream& is, VecStr& v); // word container

char inputPrompt[] = "\n Please enter your words"
                     "quit with -1: ";

int main()
{
    // read user input
    VecStr vs;
    cout << inputPrompt;
    readWords(cin, vs);
    // sort
    std::sort(vs.begin(), vs.end());
    // put elements into set
    VecStr::const_iterator VecStrIt;
    VecStrIt = vs.begin();
    SetStr ss;
    for(; VecStrIt != vs.end(); ++VecStrIt)
    {
        ss.insert(*VecStrIt);
    }
    // count
    SetStr::const_iterator SetStrIt;
    SetStrIt = ss.begin();
    unsigned cnt;
    string tmpStr;
    for(; SetStrIt != ss.end(); ++SetStrIt)
    {
        tmpStr = *SetStrIt; cnt = 0;
        VecStrIt = vs.begin();
        for(; VecStrIt != vs.end(); ++VecStrIt)
        {
            if(tmpStr == *VecStrIt)
                cnt++;
        }
        cout << tmpStr << "\t" << cnt << endl;
    }

    return 0;
}

istream& readWords(istream& is, VecStr& v)
{
    string word;
    while(is>>word && word != "-1")
    {
        v.push_back(word);
    }

    return is;
}
