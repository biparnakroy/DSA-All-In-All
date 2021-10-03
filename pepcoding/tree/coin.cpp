//dp[i][j] : now ways to form sum i with coins 0 to j-1
//dp[sum+1][n]

#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n=0;//no of coins
	cin>>n;
	int sum=0;// sum to be formed
	cin>>sum;
	int coin[n];
	for(int i=0;i<n;i++){cin>>coin[i];}
	
	int dp[sum+1][n+1];
	
	// when sum is 0 then no of ways should be 1 not picking up coins 
	//and when no of coins=0 then ways should be 0
	
	for(int i=0;i<=sum;i++){dp[i][0]=0;}
	for(int i=0;i<=n;i++){dp[0][i]=1;}
	
	for(int i=1;i<=sum;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dp[i][j]=dp[i][j-1];
			if(coin[j-1]<=i)
				dp[i][j]+=dp[i-coin[j-1]][j];
		}
	}
	cout << dp[sum][n]<<endl;
	
	return 0;
}
