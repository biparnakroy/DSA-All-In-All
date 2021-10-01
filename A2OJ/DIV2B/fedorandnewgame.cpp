#include<bits/stdc++.h>
using namespace std;
#define int long long int
int32_t main(){
	int n,m,k;cin>>n>>m>>k;
	int x[m+1]; 
	for(int i=0;i<m+1;i++)cin>>x[i];
	int count=0,d=0;
	for(int i=0;i<m;i++){
		d=0;
		for(int j=0;j<n;j++){
			if(((x[m]>>j)&1)!=((x[i]>>j)&1))
				d++;
		}
		if(d<=k)count++;
	}
	cout<<count;
	return 0;
}