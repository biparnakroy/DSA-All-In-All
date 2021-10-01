#include<bits/stdc++.h>
using namespace std;
#define int long long int
int32_t main(){
	string s;cin>>s;
	int n=s.length()-1,index=s.length()-1;
	for(int i=0;i<n;i++){
		if((s[i]-'0')%2==0){
			index=i;
			if(s[n]>s[i])
				break;
		}
	}
	
	if(n==index)cout<<-1;
	
	else{
		swap(s[n],s[index]);
		cout<<s;
	}
	return 0;
}