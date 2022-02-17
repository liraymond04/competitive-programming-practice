#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class MinStack {
private:
    stack<int> s;
    stack<int> minStack;
public:
    void push(int n) {
        if (s.size() == 0) {
            minStack.push(n);
        }
        else if (n <= minStack.top()) {
            minStack.push(n);
        }
        s.push(n);
    }

    void pop() {
        if (s.top() == minStack.top()) {
            minStack.pop();
        }
        s.pop();
    }

    int top() {
        return s.top();
    }

    int size() {
        return s.size();
    }

    int getMin() {
        return minStack.top();
    }
};

int main()
{
    MinStack minStack;
    minStack.push(-2);
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    minStack.push(-3);
    int result = minStack.getMin();
    cout << "expected: -3, actual: " << result << endl;

    minStack.pop();

    result = minStack.top();
    cout << "expected: -3, actual: " << result << endl;

    result = minStack.getMin();
    cout << "expected: -3, actual: " << result << endl;

    minStack.pop();
    result = minStack.top();
    cout << "expected: 0, actual: " << result << endl;

    result = minStack.getMin();
    cout << "expected: -2, actual: " << result << endl;

    minStack.pop();
    result = minStack.getMin();
    cout << "expected: -2, actual: " << result << endl;
    result = minStack.top();
    cout << "expected: -2, actual: " << result << endl;


    return 0;
}