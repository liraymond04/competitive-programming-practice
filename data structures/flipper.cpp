#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<vector<int> > grid{{1, 2}, {3, 4}};
    int h = 0, v = 0;
    string input;

    cin >> input;
    
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == 'H') {
            h++;
        } else {
            v++;
        }
    }

    // 0,0 0,1
    // 1,0 1,1

    if (h % 2 == 1) {
        swap(grid[0][0], grid[1][0]);
        swap(grid[0][1], grid[1][1]);
    }
    if (v % 2 == 1) {
        swap(grid[0][0], grid[0][1]);
        swap(grid[1][0], grid[1][1]);
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}