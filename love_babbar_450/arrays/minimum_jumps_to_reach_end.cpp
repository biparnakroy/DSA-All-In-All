// https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1
// Minimum jumps to reach end
// solution : https://www.youtube.com/watch?v=Zobz9BXpwYE&t=880s

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int dp[n+1];
    memset(dp,-1,sizeof(dp));
    dp[n] = 0;
    for(int i = n-1; i >= 0; i--){
        if(arr[i]>0){
            int min_jumps = INT_MAX;
            for(int j=1;j<=arr[i] && i+j<n+1;j++){
                if(dp[i+j]!=-1){
                    min_jumps = min(min_jumps,dp[i+j]);
                }
            }

            if(min_jumps!=INT_MAX){
                dp[i] = min_jumps+1;
            }
        }
    }
    cout << dp[0] << endl;
}