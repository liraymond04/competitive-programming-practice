#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int> > grid;

void rotate(int amnt) {
	for (int k = 0; k < amnt; k++) {
		vector<vector<int> > ngrid;
		for (int i = 0; i < n; i++) {
			vector<int> row;
			for (int j = n-1; j >= 0; j--) {
				row.push_back(grid[j][i]);
			}
			ngrid.push_back(row);
		}
		grid = ngrid;
	}
}

int check() {
	int corner = 0;
	int lowest = 99999;

	if (grid[0][0] < lowest) {
		lowest = grid[0][0];
		corner = 0;
	}
	if (grid[0][n-1] < lowest) {
		lowest = grid[0][n-1];
		corner = 3;
	}
	if (grid[n-1][n-1] < lowest) {
		lowest = grid[n-1][n-1];
		corner = 2;
	}
	if (grid[n-1][0] < lowest) {
		lowest = grid[n-1][0];
		corner = 1;
	}

	return corner;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		vector<int> row;
		for (int j = 0; j < n; j++) {
			int input;
			cin >> input;
			row.push_back(input);
		}
		grid.push_back(row);
	}

	rotate(check());

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}