#include<bits/stdc++.h>
using namespace std;
#define int long long int
int32_t main(){
	int r,x,y,x1,y1;
	cin>>r>>x>>y>>x1>>y1;
	double diff = sqrt(pow(x-x1,2.0)+pow(y-y1,2.0));
	cout<<(int)ceil(diff/r/2);
	return 0;
}