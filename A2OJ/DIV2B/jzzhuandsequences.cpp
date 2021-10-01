#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define MOD 1000000007
int32_t main(){
	int x,y,n; cin>>x>>y>>n;
	int a[] = {x,y,y-x,-x,-y,x-y};
	cout<<(a[(n-1)%6]%MOD+MOD)%MOD;
	return 0;
}