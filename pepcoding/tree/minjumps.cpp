#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    
    int dp[n+1];
    memset(dp,-1,sizeof(dp));
    dp[n]=0;
    // for(int i =0;i<=n;i++)cout<<dp[i]<<" ";
    // cout<<endl;
    
    for(int i=n-1;i>=0;i--){
        if(arr[i]>0){
            int min_val=INT_MAX;
            for(int j=1;j<=arr[i] && j+i<n+1;j++){
                if(dp[i+j]!=-1){
                    min_val=min(min_val,dp[i+j]);
                }
            }
            if(min_val!=INT_MAX)
                dp[i]=min_val+1;
        }
    }
    // for(int i =0;i<=n;i++)cout<<dp[i]<<" ";
    // cout<<endl;
    
    if(dp[0]==-1)
        cout<<"null"<<endl;
    else
        cout<<dp[0]<<endl;
    return 0;
}