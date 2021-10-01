#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define MAXN 1000000
int prime[MAXN];
void sieve(){
	memset(prime,0,MAXN);
	prime[0]=1;
	prime[1]=1;
	for(int i=2;i<MAXN;i++){
		if(prime[i]==0){
			for(int j=i*i;j<MAXN;j+=i){
				prime[j]=1;
			}
		}
	}
}
int square(int n){
	double sq = sqrt(n);
	if(sq == (int)sqrt(n))return 1;
	else return 0;
}
int32_t main(){
	sieve();
	int n;cin>>n;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	
	for(int i=0;i<n;i++){
		if(a[i]==4){
			cout<<"YES"<<endl;
		}
		else if(a[i]%2==0){
			cout<<"NO"<<endl;
		}
		else if(square(a[i])==1&&prime[(int)sqrt(a[i])]==0){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}