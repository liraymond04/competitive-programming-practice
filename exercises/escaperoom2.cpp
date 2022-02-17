#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <math.h>

using namespace std;

int main() {
    vector<vector<int> > grid;
    queue<int> q;
    unordered_map<int, int> walked;
    bool possible = false;
    int m, n;
    cin >> m >> n;

    for (int i=0; i<m; i++) {
        vector<int> row;
        for (int j=0; j<n; j++) {
            int input;
            cin >> input;
            row.push_back(input);
        }
        grid.push_back(row);
    }

    q.push(grid[0][0]);

    while (!q.empty()) {
        int cur = q.front();
        if (cur == grid[m-1][n-1]) {
            possible = true;
            break;
        }
        for (int i=1; i<sqrt(cur)+1; i++) {
            int x = i;
            int y = cur / i;
            if (cur % i == 0 && x <= m && y <= n) {
                int num = grid[x-1][y-1];
                if (walked[num] != 1) {
                    q.push(num);
                    walked[num] = 1;
                }
            }
        }
        q.pop();
    }

    if (possible) {
        cout << "yes";
    } else {
        cout << "no";
    }
    
    return 0;
}