#include <iostream>
#include <vector>
using namespace std;


int binarySearch(const vector<int> &v, int num, int start, int end) {
    int mid = (start + end) / 2;

    if (start > end) {
        return -1;
    }
    if (v[mid] == num) {
        return mid;
    }

    if (num < v[mid]) {
        return binarySearch(v, num, 0, mid-1);
    } else {
        return binarySearch(v, num, mid+1, end);
    }

    //return 0;
}

int main(){

    vector<int> v{1, 3, 4, 5};

    int result = binarySearch(v, 1, 0, v.size() - 1);
    cout << "expected: 0, actual: " << result << endl;

    result = binarySearch(v, 5, 0, v.size() - 1);
    cout << "expected: 3, actual: " << result << endl;

    result = binarySearch(v, 0, 0, v.size() - 1);
    cout << "expected: -1, actual: " << result << endl;

    result = binarySearch(v, 2, 0, v.size() - 1 );
    cout << "expected: -1, actual: " << result << endl;

    result = binarySearch(v, 6, 0, v.size() - 1);
    cout << "expected: -1, actual: " << result << endl;
    return 0;
}