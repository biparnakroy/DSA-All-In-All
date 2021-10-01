#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define MAXN 100000

int32_t main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m; cin>>n>>m;
    int res;
    if(m>n){
    	res=-1;
    }
    else{
    	if(n%2==0){
    		res=n/2;
    	}
    	else{
    		res=n/2+1;
    	}
    	while(res%m!=0){
    		res++;
    	}
    }
    cout<<res;
	return 0;
}