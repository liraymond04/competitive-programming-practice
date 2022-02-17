#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Data {
    string source;
    int value;

    Data() {
        source = "";
        value = 0;
    }
};

int subsequence(const string& s1, const string &s2) {
    int m = s1.size();
    int n = s2.size();
    vector<vector<Data> > dp(m + 1, vector<Data>(n + 1));
    // dp[i][j] = d[i-1][j-1] + 1 if s1[i] == s2[j]
    // max(dp[i-1][j], dp[i][j-1]) if s1[i] != s2[j]
    
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n ;j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j].value = dp[i-1][j-1].value + 1;
                dp[i][j].source = "diagonal";
            } else {
                if (dp[i-1][j].value > dp[i][j-1].value) {
                    dp[i][j].value = dp[i-1][j].value;
                    dp[i][j].source = "up";
                } else {
                    dp[i][j].value =  dp[i][j-1].value;
                    dp[i][j].source = "left";
                }
            }
        }
    }

    int i = m;
    int j = n;
    string s = "";
    while (dp[i][j].source != "") {
        if (dp[i][j].source == "up") {
            i-1;
        }
        else if (dp[i][j].source == "down") {
            j-1;
        }
        else {
            s = dp[i][j].source + s;
            i-1;
            j-1;
        }
    }

    return dp[m][n].value;
}

string longestCommonSubsequence(const string& s1, const string &s2) {
    int m = s1.length();
    int n = s2.length();
    vector<vector<Data> > dp(m+1, vector<Data>(n+1));
    // dp[i][j] = d[i-1][j-1] + 1 if s1[i] == s2[j]
    // max(dp[i-1][j], dp[i][j-1]) if s1[i] != s2[j]

    for (int i=0; i<=m; i++) {
        dp[i][0].value = 1;
    }
    for (int j=0; j<=n; j++) {
        dp[0][j].value = 1;
    }
    
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j].value = dp[i-1][j-1].value + 1;
                dp[i][j].source = "diagonal";
            } else {
                if (dp[i-1][j].value >= dp[i][j-1].value) {
                    dp[i][j].value = dp[i-1][j].value;
                    dp[i][j].source = "up";
                } else {
                    dp[i][j].value =  dp[i][j-1].value;
                    dp[i][j].source = "left";
                }
            }
        }
    }

    int i = m;
    int j = n;
    string s = "";
    while (i > 0 && j > 0) {
        if (dp[i][j].source == "diagonal") {
            i--;
            j--;
            s += string(1, s2[j]);
        }
        else if (dp[i][j].source == "up") {
            i--;
        }
        else if (dp[i][j].source == "left") {
            j--;
        }
    }

    reverse(s.begin(), s.end());
    return s;
}

int main() {

    string result = longestCommonSubsequence("acbaed", "abcadf");
    cout << "expected: acad, actual: " << result << endl;
    
    result = longestCommonSubsequence("12341", "341213");
    cout << "expected: 123, actual: " << result << endl;
    
    result = longestCommonSubsequence("AGGTAB", "GXTXAYB");
    cout << "expected: GTAB, actual: " << result << endl;
    
    
    return 0;
}