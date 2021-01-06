#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

typedef vector<string> VecStr;

VecStr split(const string& s, const char& delimiter=' ');

int main()
{
    string sentence = "Bonjour tout le monde!";
    // subscript op
    cout << sentence[0] << endl;
    // split
    VecStr vs = split(sentence);
    VecStr::const_iterator it;
    it = vs.begin();
    for(; it != vs.end(); ++it)
    {
        cout << *it << endl;
    }
    // update
    sentence[3] = 'J';
    cout << sentence << endl;
    // search
    std::size_t found = sentence.find("on");
    cout << found << endl;

//    string::const_iterator it;

    return 0;
}

VecStr split(const string& s, const char& delimiter)
{
    VecStr vs; unsigned j = 0;
    for(unsigned i=0; i<s.size(); ++i)
    {
        if(s[i]==delimiter)
        { vs.push_back(s.substr(j, i-j)); j = i+1; }

    }
    vs.push_back(s.substr(j, s.size()-1));
    return vs;
}
