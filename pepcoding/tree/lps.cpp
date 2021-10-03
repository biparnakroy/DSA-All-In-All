#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int n = s.length();
    int dp[n][n];
    int count = 0, len = 1, start = 0, end = 0;
    memset(dp, 0, sizeof(dp));
    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; i++, j++)
        {
            if (gap == 0)
                dp[i][j] = 1; //single char PRE + SUF +1
            else if (gap == 1)
                dp[i][j] = (s[i] == s[j]) ? 3 : 2; //two same chars then pal or not
            else
            {
                dp[i][j] = (s[i] == s[j]) ? dp[i][j - 1] + dp[i+1][j]+1: dp[i][j - 1] + dp[i+1][j]-dp[i+1][j-1]; // if outer chars are same then check inner chars
            }
            // calulate the count of palindromes and len of palindromes
            // if (dp[i][j] == 1)
            // {
            //     if (len <= j - i + 1)
            //     {
            //         len = j - i + 1;
            //         start = i;
            //         end = j - i + 1;
            //     }
            //     count++; // count of palindromes
            // }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    //cout << "count of palindromes: " << count << endl;
    // cout << count << endl;
    // cout << len<< endl;
    // cout << s.substr(start, end) << endl;
    return 0;
}

// cbb
// C B B BB 