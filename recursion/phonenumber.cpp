#include <iostream>
#include <string>
#include <vector>

using namespace std;



vector<string> phoneNumber(string digits) {
    vector<string> v;
    vector <string> letters {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    if (digits == "") {
        return v;
    }
    if (digits.length() == 1) {
        int index = digits[0] - '0';
        string mapped = letters[index-2];
        for (int i=0; i<mapped.length(); i++) {
            string result(1, mapped[i]);
            v.push_back(result);
        }
        return v;
    }

    vector<string> phone;
    string sub = digits.substr(1);
    phone = phoneNumber(sub);
    int index = digits[0] - '0';
    string mapped = letters[index-2];
    for (int i=0; i<mapped.length(); i++) {
        for (int j=0; j<phone.size(); j++) {
            string result = mapped[i] + phone[j];
            v.push_back(result);
        }
    }

    return v;
}



void printVector(const vector<string> & v)
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
    vector<string> v = phoneNumber("");
    printVector(v);

    v= phoneNumber("2");
    printVector(v);

    v= phoneNumber("23");
    //["ad","ae","af","bd","be","bf","cd","ce","cf"]
    printVector(v);



    return 0;
}




