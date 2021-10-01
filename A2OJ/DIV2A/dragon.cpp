#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define MAXN 100000

int32_t main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    int s,n;cin>>s>>n;
    vector<pair<int,int>> y(n);
    for(auto &x:y) cin>>x.first>>x.second;
    sort(y.begin(),y.end());
	int f=1;
	for(auto x:y){
		if(s>x.first)
			s+=x.second;
		else{
			f=0;
			cout<<"NO";
			break;
		}
	}
	if(f)
	cout<<"YES";
	return 0;
}