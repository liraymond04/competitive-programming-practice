#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int> > pascalTriangle(int n) {
    vector<vector<int> > v;

    for (int i = 0; i <= n; i++) {
        vector<int> row;
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                row.push_back(1);
            }
            else {
                row.push_back(v[i-1][j-1] + v[i-1][j]);
            }
        }
        v.push_back(row);
    }

    return v;
}

void printVector(const vector<vector<int> >& v) {
    for (int i = 0; i < v.size(); i++) {
        vector<int> row = v[i];
        for (int j = 0; j < row.size(); j++) {
            if (j > 0) {
                cout << ", ";
            }
            cout << row[j];
        }
        cout << endl;
    }
}
int main()
{
    vector<vector<int> > v = pascalTriangle(6);
    printVector(v);

    return 0;
}