#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &v, int start, int mid, int end) {
    vector<int> merged;

    int start1 = start;
    int end1 = mid;
    int start2 = mid+1;
    int end2 = end;

    while ((start1 <= end1) && (start2 <= end2)) {
        if (v[start1] < v[start2]) {
            merged.push_back(v[start1]);
            start1++;
        } else {
            merged.push_back(v[start2]);
            start2++;
        }
    }

    if (start1 <= end1) {
        for (int i=start1; i <= end1; i++) {
            merged.push_back(v[i]);
        }
    }
    if (start2 <= end2) {
        for (int i = start2; i <= end2; i++) {
            merged.push_back(v[i]);
        }
    }

    int j = 0;
    for (int i = start; i <= end; i++) {
        v[i] = merged[j];
        j++;
    }
}

void mergesort(vector<int> &v, int start, int end)
{
    if (start == end) {
        return;
    }

    int mid = (start + end) / 2;

    mergesort(v, 0, mid);
    mergesort(v, mid+1, end);
    merge(v, start, mid, end);
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

int main(){
    vector<int> v { 3, 2, 5, 4, 6, 3};
    mergesort (v, 0, v.size() - 1);
    printVector(v);

    return 0;
}