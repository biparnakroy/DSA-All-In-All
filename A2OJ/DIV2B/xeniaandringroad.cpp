#include<bits/stdc++.h>
using namespace std;
#define int long long int
int32_t main(){
	int n,m;cin>>n>>m;
	int a[m];
	int curr=1,res=0;
	for(int i=0;i<m;i++){
		cin>>a[i];
		if(a[i]>=curr){
			res+=a[i]-curr;
		}
		else{
			res+=n-(a[i]-curr);
		}
		curr = a[i];
	}
	cout<<res;

	return 0;
}