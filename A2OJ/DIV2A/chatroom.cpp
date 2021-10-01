#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define MAXN 100000

int32_t main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	unordered_set<char> st;
	string s,m="hello"; cin>>s;
	int j=0,p=0;
	for(int i=0;i<s.size();i++){
		if(s[i]==m[j]){
			j++;
			p++;
			if(p==5){
				break;
			}
		}
	}
	if(p==5)cout<<"YES";
	else cout<<"NO";
	return 0;
}