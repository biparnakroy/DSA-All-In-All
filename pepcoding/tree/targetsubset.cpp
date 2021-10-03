#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,t;
    cin>>n>>t;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    bool dp[n + 1][t + 1];
    memset(dp,false,sizeof(dp));
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
 
    // If sum is not 0 and set is empty,
    // then answer is false
    for (int i = 1; i <= t; i++)
       dp[0][i] = false;
 
    // Fill the subset table in botton up manner
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= t; j++) {
            if (j < a[i - 1])
                dp[i][j] = dp[i - 1][j];
            if (j >= a[i - 1])
                dp[i][j] = dp[i - 1][j]
                               || dp[i - 1][j - a[i - 1]];
        }
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<=t;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    
    if(dp[n][t])
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    return 0;
}