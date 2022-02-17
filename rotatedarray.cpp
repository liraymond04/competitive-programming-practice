#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

int findPivot(const vector<int>& v) {
    int start = 0;
    int end = v.size()-1;

    while (start < end) {
        int mid = (start + end) / 2;
        if (mid == 0) {
            return mid;
        }
        if (v[mid] < v[mid-1]) {
            return mid;
        }
    }
}

int binarySearch(const vector<int>& v, int start, int end, int num) {
    
}

int find(const vector<int>& v, int num)
{
    int pivot = findPivot(v);
    int start;
    int end;

    if (v[pivot] == v[num]) {
        return pivot;
    } else {
        int result1 = binarySearch(v, 0, pivot, num);
        if (result1 >= 0) {
            return result1;
        }

        int result2 = binarySearch(v, pivot, v.size(), num);
        if (result2 >= 0) {
            return result2;
        }
    }

    int start = 0;
    int end = v.size()-1;

    while (start < pivot) {
        int mid = (start + pivot) / 2;
        //if ()

        if (v[end] < v[mid]) {
            
        }
    }

    return 0;
}

int main()
{

    vector<int> v1{ 4, 5, 1, 2, 3 };
    int num = 1;
    int result = find(v1, num);
    cout << "expected: 2, actual: " << result << endl;
    num = 6;
    result = find(v1, num);
    cout << "expected: -1, actual: " << result << endl;

    vector<int> v2{ 4, 1, 2, 3 };
    num = 3;
    result = find(v2, num);
    cout << "expected: 3, actual: " << result << endl;
    num = 0;
    result = find(v2, num);
    cout << "expected: -1, actual: " << result << endl;

    //put more test cases here

    return 1;
}