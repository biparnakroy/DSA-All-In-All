#include<bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main(){
	int n,m; cin>>n>>m;
	map<string,string> mp;
	string s,a;
	for(int i=0;i<m;i++){
		cin>>s>>a;
		mp[s]=a;
	}
	for(int i=0;i<n;i++){
		cin>>s;
		if(s.length()<=mp[s].length())
			cout<<s<<" ";
		else
			cout<<mp[s]<<" ";
	}
	return 0;
}