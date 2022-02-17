#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;

vector<int> heapSort(vector<int>& nums) {
    //use greater<int> to make the top element as the smallest number.
    priority_queue <int, vector<int>, greater<int> > queue;

    for (int i=0; i<nums.size(); i++) {
        queue.push(nums[i]);
    }

    vector<int> result;

    for (int i=0; i<nums.size(); i++) {
        result.push_back(queue.top());
        queue.pop();
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
    vector <int> nums {2, 7, 11, 15, 3, 2, 4, 9};

    vector <int> result = heapSort(nums);

    printVector(result);

    return 0;

}