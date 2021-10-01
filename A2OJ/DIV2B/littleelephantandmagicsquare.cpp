#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define MOD 1000000007
#define MAX 200000
int32_t main(){
	int a[3][3],sum=0;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cin>>a[i][j];
			sum+=a[i][j];
		}
	}
	sum/=2;
	int b,c;
	b= a[1][0]-a[0][1]+a[1][2]-a[0][2];
	c= a[2][0]-a[1][0]+a[2][1]-a[1][2];
	a[2][2] = (sum-b-2*c)/3;
	a[1][1] = c+a[2][2];
	a[0][0] = b+a[1][1];
	
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++)
			cout<<a[i][j]<<" ";
		cout<<"\n";
	}
	return 0;
}