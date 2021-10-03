#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    string a="",b="";
    cin>>a;
    cin>>b;
    int dp[n+1][n+1];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(a[i-1]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<dp[n][n]<<endl;
    return 0;
}