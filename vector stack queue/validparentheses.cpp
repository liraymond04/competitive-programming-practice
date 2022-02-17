#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

bool isValidParentheses(const string &p) {
    if (p == "") {
        return true;
    }

    stack<char> s;

    for (int i = 0; i < p.length(); i++) {
        const char c = p[i];
        if (c == '(' || c == '[' || c == '{') {
            s.push(c);
        }
        if (c == ')') {
            if (s.size() == 0) {
                return false;
            }
            if (s.top() == '(') {
                s.pop();
            } else {
                return false;
            }
        }
        if (c == ']') {
            if (s.size() == 0) {
                return false;
            }
            if (s.top() == '[') {
                s.pop();
            } else {
                return false;
            }
        }
        if (c == '}') {
            if (s.size() == 0) {
                return false;
            }
            if (s.top() == '{') {
                s.pop();
            } else {
                return false;
            }
        }
    }

    if (s.size() != 0) {
        return false;
    }

    return true;
}

int main()
{

    bool result = isValidParentheses("");
    cout << "expected: 1, actual: " << result << endl;

    result = isValidParentheses("(");
    cout << "expected: 0, actual: " << result << endl;

    result = isValidParentheses(")");
    cout << "expected: 0, actual: " << result << endl;

    result = isValidParentheses("()");
    cout << "expected: 1, actual: " << result << endl;

    result = isValidParentheses("()()");
    cout << "expected: 1, actual: " << result << endl;

    result = isValidParentheses("(())");
    cout << "expected: 1, actual: " << result << endl;

    result = isValidParentheses("{()}[]");
    cout << "expected: 1, actual: " << result << endl;

    result = isValidParentheses("{[()]}}");
    cout << "expected: 0, actual: " << result << endl;

    result = isValidParentheses("{[()]}[");
    cout << "expected: 0, actual: " << result << endl;

    return 0;
}