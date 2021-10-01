#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define MAXN 100000

int32_t main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int max = INT_MIN,maxpos,minpos, min = INT_MAX;
	int n; cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]>max){
			max=a[i];
			maxpos = i;
		}
		if(a[i]<=min){
			min=a[i];
			minpos = i;
		}
	}
	if (minpos<maxpos){
		cout<<(n-minpos)+(maxpos-1)-1;
	}
	else{
		cout<<(n-minpos)+(maxpos-1);	
	}
	return 0;
}