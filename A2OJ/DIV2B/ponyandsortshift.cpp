#include<bits/stdc++.h>
using namespace std;
#define int long long int
int32_t main(){
	int n; cin>>n;
	int a[n];
	int seg=0,mnpos;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n-1;i++){
		if(a[i]>a[i+1]){
			mnpos=i;
			seg++;
		}
	}
	if(a[n-1]>a[0]){
		mnpos=n-1;
		seg++;
	}
	if(seg==0)cout<<0;
	else if(seg>1) cout<<-1<<endl;
	else cout<<n-1-mnpos<<endl;	
	return 0;
}