#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define MAXN 100000

int32_t main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n; cin>>n;
	map<int,int> mp;
	vector<int> p(n);
	for(int i=0;i<n;++i){
		cin>>p[i];
		mp[p[i]]=i+1;
	}
	for(int i=0;i<n;i++){
		cout<<mp[mp[p[i]]]<<" ";
	}
	return 0;
}