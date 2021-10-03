#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.length();

    int dp[n][n];
    memset(dp, 0, sizeof(dp));

    for (int g = 0; g < n; g++)
    {
        for (int i = 0, j = g; j < n; i++, j++)
        {
            if(g==0)
                dp[i][j]=1;
            else if(g==1)
                dp[i][j]= (s[i]==s[j])? 1:0;
            else{   
                if(s[i]==s[j])
                    dp[i][j]=dp[i+1][j-1];
                else
                    dp[i][j]=0;
            }
        }
    }

    int count=INT_MIN;
    for(int i =0;i<n;i++){
        for(int j=n-1;j>=i;j--){
            if(dp[i][j]==1){
                count=max(count,j-i+1);
                break;
            }
        }
    }

   

    // for(int i =0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    cout<<count<<endl;

    return 0;
}