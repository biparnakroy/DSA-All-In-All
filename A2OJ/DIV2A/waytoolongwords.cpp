#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define MAXN 100000

int32_t main(){
	int t;cin>>t;
	while(t--){
		string s;
		cin>>s;
		if(s.size()>10){
			cout<<s[0]<<s.size()-2<<s[s.size()-1]<<endl;
		}
		else{
			cout<<s<<endl;
		}
	}
	return 0;
}