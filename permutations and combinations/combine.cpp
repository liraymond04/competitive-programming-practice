#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <unordered_set>

using namespace std;


void combine(const string &source, string &out, int start)
{
    if (out.size() > 0)
    {
        cout << out << endl;
    }
    
    for (int i = start; i < source.size(); i++)
    {
        out.push_back(source[i]);
        combine(source, out, i + 1);
        out.pop_back();
    }
}



void combineDistinct(const string &source, string &out, int start)
{
    if (out.size() > 0) {
        cout << out << endl;
    }

    unordered_set<char> history;
    for (int i=start; i<source.size(); i++) {
        if (history.find(source[i]) != history.end()) {
            continue;
        }
        out.push_back(source[i]);
        history.insert(source[i]);
        combine(source, out, i+1);
        out.pop_back();
    }
}

int main()
{
    string s = "abc";
    string out = "";
    cout << "combinations of " << s << ":" << endl;
    combine(s, out, 0);

    out = "";
    s = "bbc";
    cout << "combinations distinct of " << s << ":" << endl;
    combineDistinct(s, out, 0);

    return 0;
}
