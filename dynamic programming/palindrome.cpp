#include <iostream>
#include <vector>
using namespace std;


int longestPalindrome(const string& s) {
    int length = s.length();
    vector<vector<bool> > dp(length, vector<bool>(length, true));
    // dp[i][j] = dp[i+1][j-1] && s[i] == s[j]
    
    int max = 1;
    for (int l=0; l<length; l++) {
        for (int i=0; i<length - l; i++) {
            int j = i + l;
            if (i == j) {
                dp[i][j] = true;
            } else {
                dp[i][j] = dp[i+1][j-1] && (s[i] == s[j]);
                if (dp[i][j]) {
                    if (l + 1 > max) {
                        max = l + 1;
                    }
                }
            }
        }
    }

   return max;
}

int main(){

    int result = longestPalindrome("cbbd");
    cout << "expected: 2, actual: " << result << endl;
    
    result = longestPalindrome("abba");
    cout << "expected: 4, actual: " << result << endl;
    
    result = longestPalindrome("dabcba");
    cout << "expected: 5, actual: " << result << endl;
    
    
    return 0;
}

// max(s[i+1][j], s[i][j-1])