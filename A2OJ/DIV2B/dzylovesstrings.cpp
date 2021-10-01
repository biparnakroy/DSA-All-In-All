#include<bits/stdc++.h>
using namespace std;
#define int long long int
int32_t main(){
	string s; cin>>s;
	int x,k;cin>>k;
	map<char,int> w;
	for(int i='a';i<='z';i++){
		cin>>x;
		w[i]=x;
	}
	int sum=0;
	for(int i=0;i<s.length();i++){
		sum+=(i+1)*w[s[i]];
	}
	int mx=0;
	for(auto x:w){
		mx=max(mx,x.second);
	}
	for(int i=s.length();i<s.length()+k;i++){
		sum+=(i+1)*mx;
	}
	cout<<sum;
	return 0;
}