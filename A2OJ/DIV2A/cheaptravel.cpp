#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define MAXN 100000

int32_t main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,a,b;cin>>n>>m>>a>>b;
    if(m*a>b){
        int s = n%m*a;
        if(s>b)
            cout<<n/m*b+b;
        else
            cout<<n/m*b+s;
    }
    else{
        cout<<n*a;    
    }
    return 0;
}