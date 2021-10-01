#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define MAXN 100000

int32_t main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	
    string a,b; cin>>a>>b;
    transform(a.begin(),a.end(),a.begin(),::tolower);
    transform(b.begin(),b.end(),b.begin(),::tolower);
    for(int i=0;i<a.size();i++){
    	if(a[i]<b[i]){cout<<"-1";return 0;}
    	else if(a[i]>b[i]){cout<<"1";return 0;}
    }
    cout<<"0";
	return 0;
}