#include <iostream>
#include <queue>
#include <iomanip>
#include <math.h>

using namespace std;

class Interval {
public: 
    int time;
    int pos;

    friend bool operator < (const Interval &left, const Interval &right) {
        return left.time > right.time;
    }
};

int main() {
    int n;
    priority_queue<Interval> q;

    cin >> n;
    
    for (int i=0; i<n; i++) {
        int it;
        int ip;
        Interval ni;
        cin >> it >> ip;

        ni.time =  it;
        ni.pos = ip;

        q.push(ni);
    }
    
    double max = 0;
    while (q.size() != 1) {
        double curp = q.top().pos;
        double curt = q.top().time;
        q.pop();
        double newp = q.top().pos;
        double newt = q.top().time;
        double result = (newp - curp) / (newt - curt);
        if (result < 0) {
            result *= -1;
        }
        if (result > max) {
            max = result;
        }
    }

    cout << fixed << setprecision(1) << max;

    return 0;
}