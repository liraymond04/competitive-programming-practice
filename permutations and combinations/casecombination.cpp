#include <iostream>
#include <vector>

using namespace std;

vector<string> caseCombination(const string &source) {
    vector<string> cases;
    cases.push_back(source);

    for (int i=0; i<source.length(); i++) {
        if (source[i] >= 'a' && source[i] <= 'z') {
            int size = cases.size();
            for (int j=0; j<size; j++) {
                string s = cases[j];
                s[i] -= 32;
                cases.push_back(s);
            }
        } else if (source[i] >= 'A' && source[i] <= 'Z') {\
            int size = cases.size();
            for (int j=0; j<size; j++) {
                string s = cases[j];
                s[i] += 32;
                cases.push_back(s);
            }
        }
    }

    return cases;
}

int main() {
    string s = "a1b2";
    vector<string> c = caseCombination(s);
    
    for (int i=0; i<c.size(); i++) {
        cout << c[i] << endl;
    }
    
    return 0;
}