#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <math.h>

using namespace std;

int walked[1000][1000];

int main() {
    vector<vector<int> > grid;
    queue<int> q;
    bool possible = false;
    int target;

    int m, n;
    cin >> m;
    cin >> n;

    for (int i=0; i<m; i++) {
        vector<int> row;
        for (int j=0; j<n; j++) {
            int input;
            cin >>input;
            row.push_back(input);
        }
        grid.push_back(row);
    }

    target = grid[0][0];
    q.push(m * n);

    while (!q.empty()) {
        int val = q.front();
        if (val == target) {
            possible = true;
            break;
        }
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == val && walked[i][j] != 1) {
                    q.push((i+1) * (j+1));
                    walked[i][j]= 1; 
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