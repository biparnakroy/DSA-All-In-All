#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define MAXN 100000

int32_t main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    if(n<0){
        int n1=n/10,n2=(n/100)*10+n%10;
        cout<<max(n1,n2);
    }
    else{
        cout<<n;
    }
    return 0;
}