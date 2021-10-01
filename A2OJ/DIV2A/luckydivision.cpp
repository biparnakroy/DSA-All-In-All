#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define MAXN 100000

int32_t main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int arr[]={4,7,47,74,444,447,474,477,744,747,777};
	int n; cin>>n;
	for(int i=0;i<11;i++){
		if(n%arr[i]==0){
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";
	return 0;
}