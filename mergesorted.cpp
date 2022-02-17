#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

vector<int> merge(const vector<int>& v1, const vector<int>& v2)
{
    vector<int> merged;

    int start1 = 0;
    int end1 = v1.size();
    int start2 = 0;
    int end2 = v2.size();

    while ((start1 < end1) && (start2 < end2)) {
        if (v1[start1] < v2[start2]) {
            merged.push_back(v1[start1]);
            start1++;
        } else {
            merged.push_back(v2[start2]);
            start2++;
        }
    }

    if (start1 < end1) {
        for (int i=start1; i<end1; i++) {
            merged.push_back(v1[i]);
        }
    }
    if (start2 < end2) {
        for (int i=start2; i<end2; i++) {
            merged.push_back(v2[i]);
        } 
    }

    return merged;
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
    vector<int> v1;
    vector<int> v2;

    vector<int> result = merge(v1, v2);
    cout << "expected vector size: 0, actual: " << result.size() << endl;
    printVector(result);

    v1.push_back(1);
    result = merge(v1, v2);
    cout << "expected vector size: 1, actual: " << result.size() << endl;
    printVector(result);

    v2.push_back(2);
    result = merge(v1, v2);
    cout << "expected vector size: 2, actual: " << result.size() << endl;
    printVector(result);
    
    v1.push_back(5);
    result = merge(v1, v2);
    cout << "expected vector size: 3, actual: " << result.size() << endl;
    printVector(result);

    v2.push_back(3);
    result = merge(v1, v2);
    cout << "expected vector size: 4, actual: " << result.size() << endl;
    printVector(result);

    v2.push_back(4);
    result = merge(v1, v2);
    cout << "expected vector size: 5, actual: " << result.size() << endl;
    printVector(result);
    
    v2.push_back(6);
    result = merge(v1, v2);
    cout << "expected vector size: 6, actual: " << result.size() << endl;
    printVector(result);
    
    v2.push_back(8);
    result = merge(v1, v2);
    cout << "expected vector size: 7, actual: " << result.size() << endl;
    printVector(result);
   
    return 1; 
}