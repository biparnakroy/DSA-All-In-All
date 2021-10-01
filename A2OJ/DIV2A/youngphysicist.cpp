#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define MAXN 100000

int32_t main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,x,y,z; cin>>n;
   	int xs(0),ys(0),zs(0);
   	for(int i=0;i<n;i++){
   		cin>>x>>y>>z;
   		xs+=x;
   		ys+=y;
   		zs+=z;
   	}
   	if(xs==0&&ys==0&&zs==0)cout<<"YES";
   	else cout<<"NO";
	return 0;
}