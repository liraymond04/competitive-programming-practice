#include <iostream>
#include <vector>
using namespace std;


int editdistance(const string& s1, const string &s2) {
  int m = s1.length();
  int n = s2.length();
  vector<vector<int> > dp(m+1, vector<int>(n+1, 0));

  for (int i=0; i<m+1; i++) {
    dp[i][0] = i;
  }
  for (int i=0; i<n+1; i++) {
    dp[0][i] = i;
  }

  for (int i=1; i<m+1; i++) {
    for (int j=1; j<n+1; j++) {
      if (s1[i-1] == s2[j-1]) {
        dp[i][j] = dp[i-1][j-1];
      } else {
        dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
      }
    }
  }

  return dp[m][n];
}

int main(){

    int result = editdistance("kitten", "sitting");
    cout << "expected: 3, actual: " << result << endl;
    
    result = editdistance("intention", "execution");
    cout << "expected: 5, actual: " << result << endl;
    
    result = editdistance("horse", "ros");
    cout << "expected: 3, actual: " << result << endl;
    
    
    return 0;
}