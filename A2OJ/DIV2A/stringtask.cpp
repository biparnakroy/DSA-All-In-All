#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define MAXN 100000

int32_t main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	string s; cin>>s;
	string res="";
	transform(s.begin(),s.end(),s.begin(),::tolower);
	for(int i=0;i<s.size();i++){
		if(s[i]!='a'&&s[i]!='e'&&s[i]!='i'&&s[i]!='o'&&s[i]!='u'&&s[i]!='y'){
			res+='.';
			res+=s[i];
		}
	}
	cout<<res;
	return 0;
}