#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define MAXN 100000

int32_t main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n,m; cin>>n>>m;
	int i=min(n,m);
	if(i%2){
		cout<<"Akshat";
	}
	else{
		cout<<"Malvika";
	}
	return 0;
}