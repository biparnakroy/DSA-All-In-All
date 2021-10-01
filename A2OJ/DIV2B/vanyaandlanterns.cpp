#include<bits/stdc++.h>
using namespace std;
#define int long long int
int32_t main(){
	int n,l;cin>>n>>l;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	int d = max(l-a[n-1],a[0]) * 2;
	for(int i=0;i<n-1;i++){
		d=max(d,(a[i+1]-a[i]));
	}
	cout.precision(20);
	cout<<fixed<<d/2.0;
	return 0;
}