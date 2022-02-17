#include <iostream>
#include <vector>
using namespace std;


int maxSubArray(const vector <int>& v) {
    int max = 0;
    vector<int> maximum;
    maximum.push_back(v[0]);

    for (int i=1; i<v.size(); i++) {
        if (maximum[i-1] >= 0) {
            int num = maximum[i-1] + v[i];
            maximum.push_back(num);
            if (num > max) {
                max = num;
            }
        } else {
            maximum.push_back(v[i]);
            if (v[i] > max) {
                max = v[i];
            }
        }
    }

    return max;
}

int main(){

    vector<int> v1{-2, 1, -3, 4, -1, 2, 1, -5, 4 };
    
    int result = maxSubArray(v1);
    cout << "expected: 6, actual: " << result << endl;
    
    vector<int> v2{-2, -3, 4, -1, -2, 1, 5, -3};
    result = maxSubArray(v2);
    cout << "expected: 7, actual: " << result << endl;
    
    return 0;
}