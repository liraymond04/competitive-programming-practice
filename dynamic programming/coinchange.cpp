#include <iostream>
#include <vector>
using namespace std;


int coinChange(vector<int>& coins, int amount) {
    // dp[i] = min(dp[index], ..., dp[i-coin[n-1]]) + 1
    vector<int> dp(amount+1);
    dp[0] = 0;
    for (int i=1; i<=amount; i++) {
        int m = INT_MAX;
        for (int j=0; j<coins.size(); j++) {
            int index = i-coins[j];
            if (index >= 0 && dp[index] < m) {
                m = dp[index];
            }
        }
        dp[i] = m + 1;
    }

    return dp[amount];
}

int main(){

    vector< int> v {1, 2, 5};
  
    int result = coinChange(v, 11);
    cout << "expected: 3, actual: " << result << endl;
    
    return 0;
}