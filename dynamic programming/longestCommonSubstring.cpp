#include <iostream>
#include <vector>
using namespace std;


int longestCommonSubstring(const string& s1, const string &s2) {
    int n = s1.length();
    int m = s2.length();
    int max = 0;
    vector<vector<int> > lcs(n, vector<int>(m, 0));
    
    for (int i=0; i<m; i++) {
        if (s1[0] == s2[i]) {
            lcs[0][i] = 1;
            if (lcs[0][i] > max) {
                max = lcs[0][i];
            }
        }
    }
    for (int i=0; i<n; i++) {
        if (s1[i] == s2[0]) {
            lcs[i][0] = 1;
            if (lcs[i][0] > max) {
                max = lcs[i][0];
            }
        }
    }

    for (int i=1; i<n; i++) {
        for (int j=1; j<m; j++) {
            if (s1[i] == s2[j]) {
                lcs[i][j] = lcs[i-1][j-1] + 1;
                if (lcs[i][j] > max) {
                    max = lcs[i][j];
                }
            } else {
                lcs[i][j] = 0;
            }
        }
    }
   
   return max;
}

int main(){

    int result = longestCommonSubstring("abcdxyz", "xyzabcd");
    cout << "expected: 4, actual: " << result << endl;
    
    result = longestCommonSubstring("a", "xyzabcd");
    cout << "expected: 1, actual: " << result << endl;
    
    result = longestCommonSubstring("ABABC", "BABCA");
    cout << "expected: 4, actual: " << result << endl;
    
    
    return 0;
}