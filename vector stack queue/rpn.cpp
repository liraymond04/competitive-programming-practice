#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int evaluate(const vector<string>& tokens) {
    stack<int> s;

    for (int i = 0; i < tokens.size(); i++) {
        if (tokens[i] == "+") {
            int n1 = s.top();
            s.pop();
            int n2 = s.top();
            s.pop();
            s.push(n1 + n2);
        }
        else if (tokens[i] == "-") {
            int n1 = s.top();
            s.pop();
            int n2 = s.top();
            s.pop();
            s.push(n2 - n1);
        }
        else if (tokens[i] == "*") {
            int n1 = s.top();
            s.pop();
            int n2 = s.top();
            s.pop();
            s.push(n1 * n2);
        }
        else if (tokens[i] == "/") {
            int n1 = s.top();
            s.pop();
            int n2 = s.top();
            s.pop();
            s.push(n2 / n1);
        }
        else {
            s.push(stoi(tokens[i]));
        }
    }

    return s.top();
}

int main()
{
    vector <string> tokens {"2", "1", "+", "3", "*"};
    int result = evaluate(tokens);
    cout << "expected: 9, actual: " << result << endl;

    vector<string> tokens1 {"4", "13", "5", "/", "+"};
    result = evaluate(tokens1);
    cout << "expected: 6, actual: " << result << endl;

    vector<string> tokens2 {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    result = evaluate(tokens2);
    cout << "expected: 22, actual: " << result << endl;
    return 0;
}

/*
def rpn(tokens):
    s = Stack()

    for i in tokens:
        if (i == "+"):
            n1 = s.top()
            s.pop()
            n2 = s.top()
            s.pop()
            s.push(n1 + n2)
        elif (i == "-"):
            n1 = s.top()
            s.pop()
            n2 = s.top()
            s.pop()
            s.push(n2 - n1)
        elif (i == "*"):
            n1 = s.top()
            s.pop()
            n2 = s.top()
            s.pop()
            s.push(n1 * n2)
        elif (i == "/"):
            n1 = s.top()
            s.pop()
            n2 = s.top()
            s.pop()
            s.push(n2 / n1)
        else:
            s.push(int(i))

    return s.top()
*/
