#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define MAXN 100000

int32_t main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;cin>>n>>m;
    vector<int> f(m);
    for(int i=0;i<m;++i)cin>>f[i];
    int i=0,j=n-1,a=1;

	sort(f.begin(), f.end());
	
	a=f[n-1]-f[0];
	
	for(int i=1;i<=m-n;i++){
		if(f[i+n-1]-f[i]<a){
			a=f[i+n-1]-f[i];
		}
	}
	cout<<a;
	return 0;
}