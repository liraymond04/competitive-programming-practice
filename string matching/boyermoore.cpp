#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void bmSearch(const string &haystack, const string &needle)
{
    vector<int> table (256, -1);

    for (int i=0; i<needle.length(); i++) {
        table[needle[i]] = i;
    }

    int index = 0;
    while (index + needle.length() <= haystack.length()) {
        int i;
        for (i=needle.length()-1; i>=0; i--) {
            if (needle[i] != haystack[index+i]) {
                break;
            }
        }
        if (i < 0) {
            cout << "Found match at index: " << index << endl;
            if (index + needle.length() >= haystack.length()) {
                break;
            }
            char next = haystack[index+needle.length()];
            index = index + needle.length() - table[next];
        } else {
            if (table[haystack[index+i]] < i) {
                index = (index + i) - table[haystack[index+i]];
            } else {
                index++;
            }
        }
    }
}

int main()
{
    string haystack("GCAATGCGTATTGGATATGTGC");
    string needle("TATGTG");
    size_t found = haystack.find(needle);
    if (found != std::string::npos)
        std::cout << "first 'needle' found at: " << found << '\n';

    cout << endl
        << haystack << endl
        << needle << endl;
    bmSearch(haystack, needle);

    haystack = "AAAAAAA";
    needle = "AAA";
    cout << endl
        << haystack << endl
        << needle << endl;
    bmSearch(haystack, needle);

    haystack = "ABBABBA";
    needle = "ABBA";
    cout << endl
        << haystack << endl
        << needle << endl;
    bmSearch(haystack, needle);

    return 0;
}