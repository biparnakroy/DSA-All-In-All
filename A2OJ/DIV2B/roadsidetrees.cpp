#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define MOD 1000000007
int32_t main(){
	int n; cin>>n;
	int res(0),a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	res=a[0]+1;
	for(int i=0;i<n-1;i++){
		res+=abs(a[i]-a[i+1])+2;
	}
	cout<<res;
	return 0;
}