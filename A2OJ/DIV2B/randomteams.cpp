#include<bits/stdc++.h>
using namespace std;
#define int long long int
int count(int n){
	return n*(n-1)/2;
}
int32_t main(){
	int n,m;cin>>n>>m;
	int rem = n%m, tot = n/m;
	int min = count(tot)*(m-rem) + count(tot+1)*rem;
	int max = count(n-m+1);
	cout<<min<<" "<<max;
}