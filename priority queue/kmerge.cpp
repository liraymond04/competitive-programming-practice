#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

class VectorData {
public:
    int row;
    int col;
    int value;


    friend bool operator < (const VectorData &left, const VectorData &right) {
        return left.value > right.value;
    }
};

vector<int> kmerge(const vector<vector<int> > &v) {

    vector<int> result;
    priority_queue<VectorData> q;

    for (int i=0; i<v.size(); i++) {
        VectorData n;
        n.row = i;
        n.col = 0;
        n.value = v[i][0];
        q.push(n);
    }

    while (!q.empty()) {
        VectorData top = q.top();
        result.push_back(top.value);
        q.pop();
        if (top.col+1 < v[top.row].size()) {
            VectorData n;
            n.row = top.row;
            n.col = top.col+1;
            n.value = v[n.row][n.col];
            q.push(n);
        }
    }

    return result;
}

void printVector(const vector<int> & v)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        if (i > 0) cout << " , ";
        cout << v[i];
    }
    cout << endl;
}

int main()
{
    vector <int> v1 {1, 3, 5, 7, 9};
    vector <int> v2 {2, 4, 6, 8, 10};
    vector <int> v3 {3, 6, 9, 12};
    vector <int> v4 {0};
    vector <int> v5 {13, 14, 15};

    vector <vector <int> >v;
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);
    v.push_back(v5);

    vector <int> result = kmerge(v);

    printVector(result);

    return 0;


}