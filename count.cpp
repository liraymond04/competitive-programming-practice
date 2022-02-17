#include<iostream>
#include<vector>

using namespace std;

int countOccurrence(const vector<int>& v, int num)
{
    int count = 0;
    for (int i=0; i<v.size(); i++) {
        if (v[i] == num) {
            count++;
        }
    }
    return count;
}

int main()
{
    vector<int> v;

    int num = 1;
    int result = countOccurrence(v, num); 
    cout << "expected: 0, actual: " << result << endl;

    v.push_back(0);
    result = countOccurrence(v, num); 
    cout << "expected: 0, actual: " << result << endl;
    
    v.push_back(1);
    result = countOccurrence(v, num); 
    cout << "expected: 1, actual: " << result << endl;
    
    v.push_back(2);
    result = countOccurrence(v, num); 
    cout << "expected: 1, actual: " << result << endl;

    v.push_back(1);
    result = countOccurrence(v, num); 
    cout << "expected: 2, actual: " << result << endl;

    return 1;
}