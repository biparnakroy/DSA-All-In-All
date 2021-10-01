#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define MAXN 100000

int32_t main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,k;cin>>n>>k;
    if(k<=(n+1)/2){
        cout<<2*k-1;
    }    
    else{
        k-=(n+1)/2;
        cout<<2*k;
    }
    return 0;
}