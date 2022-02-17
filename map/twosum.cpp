#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector <int> result;
    unordered_map<int, int> m;

    for (int i=0; i<nums.size(); i++) {
        int key = target-nums[i];
        int value = i;

        if (m.find(nums[i]) != m.end()) {
            result.push_back(m[nums[i]]);
            result.push_back(value);
            break;
        }

        m[key] = value;
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
    vector <int> nums {2, 7, 11, 15};

    vector <int> result = twoSum(nums, 9);

    printVector(result);

    return 0;

}

// 1 - custom operator
// 2 - two sum
// 3 - queue