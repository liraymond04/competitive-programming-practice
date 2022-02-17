#include <iostream>
#include <vector>
using namespace std;


int knapsackDP(const vector<int>& weights, const vector <int> & values, int weightLimit) {
    int r = values.size();
    int c = weightLimit;
    vector<vector<int> > table(r + 1, vector<int>(c + 1, 0));

    for (int i=0; i<c+1; i++) {
        table[0][i] = 0;
    }
    for (int i=0; i<r+1; i++) {
        table[i][0] = 0;
    }

    for (int i=1; i<=r; i++) {
        for (int j=1; j<=c; j++) {
            if (j >= weights[i-1]) {
                table[i][j] = max(table[i-1][j], table[i-1][j-weights[i-1]] + values[i-1]);
            } else {
                table[i][j] = table[i-1][j];
            }
        }
    }

    return table[r][c];
}

int main(){

    vector<int> weights {1, 3, 5, 6, 7};
    vector<int> values {1, 8, 18, 22, 28};
    int weightLimit = 11;
    
    int result = knapsackDP(weights, values, weightLimit);
    cout << "expected: 40, actual: " << result << endl;
   
    
    
    return 0;
    // palindrome - check middlle palindrome, check end and start, i - start j - end
}