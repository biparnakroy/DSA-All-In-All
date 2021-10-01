#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define MAXN 100000

int32_t main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int m,n,k;
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cin>>k;
			if(k){
				m=i;n=j;
			}
		}
	}
	int res = abs(m-2)+abs(n-2);
	cout<<res;
	return 0;
}