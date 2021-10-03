#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main(){
    
    int n;
    cin>>n;
    int dp[n+1][2];
    
    memset(dp,0,sizeof(dp));

    dp[1][0]=1;
    dp[1][1]=1;
    
    for(int i=2;i<=n;i++){
       dp[i][0]=dp[i-1][1];
       dp[i][1]=dp[i-1][0]+dp[i-1][1];
    }
    
    
    cout<<(int)pow(dp[n][0]+dp[n][1],2)<<endl;
    
    return 0;
    
}