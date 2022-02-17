#include<iostream>
#include<string>

using namespace std;

bool isPalindrome(const string &s)
{
    int start = 0;
    int end = s.length()-1;

    while (start < end) {
        if (s[start] == s[end]) {
            start++;
            end--;
        } else {
            return false;
        }
    }

    return true;
}

int main()
{
    bool result = isPalindrome(""); 
    cout << "expected: 1, actual: " << result << endl;

    result = isPalindrome("a"); 
    cout << "expected: 1, actual: " << result << endl;
    
    result = isPalindrome("ab"); 
    cout << "expected: 0, actual: " << result << endl;
    
    result = isPalindrome("aa"); 
    cout << "expected: 1, actual: " << result << endl;

    result = isPalindrome("aba"); 
    cout << "expected: 1, actual: " << result << endl;

    return 1;
}