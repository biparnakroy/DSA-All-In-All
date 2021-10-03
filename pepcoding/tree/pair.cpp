#include <bits/stdc++.h>
using namespace std;
int main(){
	
	int n =0;
	cin>>n;
	int dp[n+1];
	int mod=int(1e9+7);
	
	for(int i=0;i<=n;i++){
		if(i<=2)
		   dp[i]=i;
		else
		   dp[i]=(dp[i-1]+(i-1)*dp[i-2])%mod;
		   if(dp[i]<0)
		   	dp[i]+=mod;
		  }
	cout<<dp[n]<<endl;
	
	return 0;
	}
