#include <bits/stdc++.h>
using namespace std;
#define int long long int
int32_t main(){
    
    string s;
    cin>>s;
    int n=s.length();
    
    int dp[n+1];
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    
    unordered_map<char,int> m;
    
    for(int i=1;i<=n;i++){
        dp[i]=2*dp[i-1];
        if(m.find(s[i-1])!= m.end()){
            dp[i]=dp[i]-dp[m[s[i-1]]-1];
        }
        m[s[i-1]]=i;
    }
    for(int i=0;i<=n;i++){
        cout<<dp[i]<<" ";
    }
    cout<<endl;
    cout<<dp[n]-1<<endl;
    return 0;
}