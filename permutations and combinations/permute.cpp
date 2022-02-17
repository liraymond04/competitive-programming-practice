#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <unordered_set>

using namespace std;

void permute(const string &source, string &out, vector<bool> &used)
{

    if (out.size() == source.size())
    {
        cout << out << endl;
        return;
    }

    for (int i = 0; i < source.size(); i++)
    {
        if (used[i])
            continue;
        out.push_back(source[i]);
        used[i] = true;
        permute(source, out, used);
        out.pop_back();
        used[i] = false;
    }
}


void permuteDistinct(const string &source, string &out, vector<bool> &used)
{
    if (out.size() == source.size())
    {
        cout << out << endl;
        return;
    }

    unordered_set<char> history;
    for (int i = 0; i < source.size(); i++)
    {
        if (used[i])
            continue;
        char ch = source[i];
        if (history.find(ch) != history.end())
        {
            continue;
        }
        history.insert(ch);
        out.push_back(ch);
        used[i] = true;
        permuteDistinct(source, out, used);
        out.pop_back();
        used[i] = false;
    }
}


void permuteSTL(string &s)
{
    sort(s.begin(), s.end());
    do {
        cout << s << endl;
    } while( next_permutation(s.begin(), s.end()) );
}

int main()
{
    string s = "abc";
    string out = "";
    vector<bool> used(s.size(), false);
    cout << "permute of " << s << ":" << endl;
    permute(s, out, used);

    s = "cbb";
    out = "";

    cout << "permute of " << s << ":" << endl;
    permute(s, out, used);

    out = "";
    cout << "permute distinct of " << s << ":" << endl;
    permuteDistinct(s, out, used);

    cout << "permuteSTL of " << s << ":" << endl;
    permuteSTL(s);

   
    return 0;
}
