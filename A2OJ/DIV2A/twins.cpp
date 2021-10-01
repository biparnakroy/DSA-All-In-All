#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define MAXN 100000

int32_t main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n,sum=0; cin>>n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin>>v[i];
		sum+=v[i];
	}
	sum=sum/2;
	sort(v.begin(), v.end());
	int mysum=0,count=0;
	for(int i=n-1;i>=0;i--){
			mysum+=v[i];
			count++;
		if(mysum>sum) {
			break;
		}
	}
	cout<<count;
	return 0;
}