#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define MOD 1000000007
int32_t main(){
	int n,s,t;
	cin>>n>>s>>t;
	int p[n];
	for(int i=0;i<n;i++){
		cin>>p[i];
	}
	int i=0;
	while(i<n){
		if(s==t){
			cout<<i;
			return 0;
		}	
		s=p[s-1];
		i++;
	}
	cout<<-1;
	return 0;
}