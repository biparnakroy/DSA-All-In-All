#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define MAXN 100000

int32_t main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n; cin>>n;
	vector<int> h(n),g(n);
	for(int i=0;i<n;++i){
		cin>>h[i]>>g[i];
	}
	int res=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(h[i]==g[j])res++;
		}
	}
	cout<<res;
	return 0;
}