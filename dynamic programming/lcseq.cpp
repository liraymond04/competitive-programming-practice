#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Data
{
    char source;
    int value;

    Data()
    {
        value = 0;
        source = ' ';
    }
};

//with extra dummy row, column
string longestCommonSubsequence1(const string &s1, const string &s2)
{
    int n = s1.length();
    int m = s2.length();

    //initialize the table with (n+1, m+1)
    //The first row and column are dummy row and column.
    vector<vector<Data>> dp(n + 1, vector<Data>(m + 1));

    // dp[i][j] = dp[i-1][j-1] + 1, if s[i] = s[j]
    // dp[i][j] = max(dp[i-1][j], dp[i][j-1]), if s[i] != s[j]

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j].value = dp[i - 1][j - 1].value + 1;
                dp[i][j].source = 'D';
            }
            else
            {
                if (dp[i - 1][j].value >= dp[i][j - 1].value)
                {
                    dp[i][j].value = dp[i - 1][j].value;
                    dp[i][j].source = 'U';
                }
                else
                {
                    dp[i][j].value = dp[i][j - 1].value;
                    dp[i][j].source = 'L';
                }
            }
        }
    }

    string s = "";
    int i = n;
    int j = m;

    while (i > 0 && j > 0)
    {
        if (dp[i][j].source == 'D')
        {
            i--;
            j--;
            s += string(1, s2[j]);
        }
        else if (dp[i][j].source == 'L')
        {
            j--;
        }
        else
        {
            i--;
        }
    }
    reverse(s.begin(), s.end());
    return s;
}

//no dummy row, column
string longestCommonSubsequence(const string &s1, const string &s2)
{
    int n = s1.length();
    int m = s2.length();

    //initialize the table with (n, m)
    vector<vector<Data>> dp(n, vector<Data>(m));

    // dp[i][j] = dp[i-1][j-1] + 1, if s[i] = s[j]
    // dp[i][j] = max(dp[i-1][j], dp[i][j-1]), if s[i] != s[j]

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s1[i] == s2[j])
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j].value = 1; //first row or column
                }
                else
                {
                    dp[i][j].value = dp[i - 1][j - 1].value + 1;
                }
                dp[i][j].source = 'D';
            }
            else
            {
                int up = (i == 0) ? 0 : dp[i - 1][j].value;
                int left = (j == 0) ? 0 : dp[i][j - 1].value;
                if (up >= left)
                {
                    dp[i][j].value = up;
                    dp[i][j].source = 'U';
                }
                else
                {
                    dp[i][j].value = left;
                    dp[i][j].source = 'L';
                }
            }
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++)
    //     cout << "(" << dp[i][j].value << ", " << dp[i][j].source << ") ";
    //  cout << endl;
    // }

    string s = "";
    int i = n - 1;
    int j = m - 1;

    //back track the optimal path.
    //start from the lower right corner,
    while (i >= 0 && j >= 0)
    {
        if (dp[i][j].source == 'D')
        {
            //the case: dp[i][j] = dp[i-1][j-1] + 1, if s[i] = s[j]
            s += string(1, s2[j]);
            i--;
            j--;
        }
        else if (dp[i][j].source == 'L')
        {
            j--;
        }
        else
        {
            i--;
        }
    }
    //back track string is the reversed string of the sub sequence.
    //we need to reverse it back 
    reverse(s.begin(), s.end());
    return s;
}

int main()
{

    string result = longestCommonSubsequence("acbaed", "abcadf");
    cout << "expected: acad, actual: " << result << endl;

    result = longestCommonSubsequence("12341", "341213");
    cout << "expected: 123, actual: " << result << endl;

    result = longestCommonSubsequence("AGGTAB", "GXTXAYB");
    cout << "expected: GTAB, actual: " << result << endl;

    return 0;
}