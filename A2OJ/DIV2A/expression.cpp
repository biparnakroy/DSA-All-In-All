#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define MAXN 100000

int32_t main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a,b,c;
    cin>>a>>b>>c;
    int s1,s2,s3,s4,s5,s6;
    s6=a+b+c;
    s1=(a+b)*c;
    s2=a*(b+c);
    s4=a+(c*b);
    s5=(a*b)+c;
    s3=a*b*c;
	cout<<max(s1,max(s2,max(s3,max(s4,max(s6,s5)))));
	return 0;
}