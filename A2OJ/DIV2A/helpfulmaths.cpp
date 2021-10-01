#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define MAXN 100000

int32_t main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	string s;
	cin>>s;
	vector<int> v;
	for(int i=0;i<s.size();i=i+2){
		v.push_back(s[i]);
	}
	sort(v.begin(),v.end());
	string res="";
	for(int i=0;i<v.size();i++){
		res+=v[i];
		res+="+";
	}
	res.erase(res.end()-1);
	cout<<res;
	return 0;
}