#include<bits/stdc++.h>
using namespace std;
#define int long long int
int32_t main(){
	int n;cin>>n;
	int a[n];
	pair<int,int> seg;
	for(int i=0;i<n;i++)cin>>a[i];

	int segments=0;

	for(int i=0;i<n-1;i++){
		
		if(a[i]>a[i+1]){

			seg.first=i;
			
			while(i<n-1&&a[i]>a[i+1])
				i++;
			seg.second=i;

			sort(a+seg.first,a+seg.second+1);
			i--;
		
			segments++;
		}
	
	}

	if(segments>1||is_sorted(a,a+n)==0)cout<<"no";
	else if(segments=1)cout<<"yes"<<endl<<seg.first+1<<" "<<seg.second+1;
	else cout<<"yes"<<endl<<1<<" "<<1;
	return 0;
}