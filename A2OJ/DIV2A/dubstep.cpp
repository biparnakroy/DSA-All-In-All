#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define MAXN 100000

int32_t main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    int wub=0;
	string s,res=""; cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='W'&&s[i+1]=='U'&&s[i+2]=='B'){
			i=i+2;
			wub++;
		}
		else {
			if(wub)res+=" ";
			res+=s[i];
			wub=0;
		}
	}
	if(res[0]==' ')res.erase(res.begin());
	cout<<res;
	return 0;
}