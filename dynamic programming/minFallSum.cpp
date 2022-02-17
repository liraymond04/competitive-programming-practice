#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int minFallSum(vector<vector<int> >& v) {
    // v[i][j] = min(v[i+1][j-1], v[i+1][j], v[i+1][j+1]) + v[i][j]
    // v[i][j] = min(v[i+1][j], v[i+1][j+1]) + v[i][j]
    // v[i][j] = min(v[i+1][j], v[i+1][j-1]) + v[i][j]
    int n = v.size();
    int m = v[0].size();

    for (int i=n-2; i>=0; i--) {
        for (int j=0; j<m; j++) {
            if (j == 0) {
                v[i][j] = min(v[i+1][j], v[i+1][j+1]) + v[i][j];
            } else if (j == m-1) {
                v[i][j] = min(v[i+1][j], v[i+1][j-1]) + v[i][j];
            } else {
                v[i][j] = min(v[i+1][j-1], min(v[i+1][j], v[i+1][j+1])) + v[i][j];
            }
        }
    }
    
    return *min_element(v[0].begin(), v[0].end());
}

int main(){

    vector< vector<int>> v {{1, 2, 3},{4,5, 6},{7,8,9}};
  
    int result = minFallSum(v);
    cout << "expected: 12, actual: " << result << endl;
    
    return 0;
}