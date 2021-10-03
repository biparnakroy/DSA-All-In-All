// dp[i][j]: max value with items of wt[0 to i-1] and knapsack capacity j
// dp[n+1][W+1]

#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n=0;//no of items
	cin>>n;
	int W=0;// capacity of knapsack
	cin>>W;
	int val[n];
	for(int i=0;i<n;i++){cin>>val[i];}
	int wt[n];
	for(int i=0;i<n;i++){cin>>wt[i];}
	
	int dp[n+1][W+1];
	// when capacity is 0 then max value should be 0 and when no of items=0 then
	// max value should be 0
	
	for(int i=0;i<=n;i++){dp[i][0]=0;}
	for(int i=0;i<=W;i++){dp[0][i]=0;}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=W;j++)
		{
			if(wt[i-1]>j)
				dp[i][j]=dp[i-1][j];
			else
				dp[i][j]=max(dp[i-1][j],val[i-1]+dp[i-1][j-wt[i-1]]);
		}
	}
	cout << dp[n][W]<<endl;
	
	return 0;
}
