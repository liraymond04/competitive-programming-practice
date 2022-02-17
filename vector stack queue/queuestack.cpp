#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class QueueStack {
private:
    queue<int> q;
public:
    void push(int n) {
        q.push(n);
    }

    void pop() {
        queue<int> n;
        for (int i = 0; i < q.size()-1; i++) {
            n.push(q.front());
            q.pop();
        }
        q = n;
    }

    int top() {
        return q.back();
    }

    int size() {
        return q.size();
    }
};

int main()
{
    QueueStack queueStack;

    queueStack.push(1);
    queueStack.push(2);
    int result = queueStack.top();
    cout << "expected: 2, actual: " << result << endl;

    queueStack.pop();

    result = queueStack.top();
    cout << "expected: 1, actual: " << result << endl;
    return 0;
}