#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    vector<double> villages;
    int n;
    double min = 99999;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        villages.push_back(input);
    }

    sort(villages.begin(), villages.end());

    for (int i = 0; i < n; i++) {
        if (i == 0 || i == n-1) {
            continue;
        }
        float l = (villages[i+1] - villages[i-1]) / 2.0;
        if (l < min) {
            min = l;
        }
    }  

    cout << fixed << setprecision(1) << min;

    return 0;
}