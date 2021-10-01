#include<bits/stdc++.h>
using namespace std;
// #define int long long int
#define MOD 1000000007
#define MAX 200000
bool arr(string a , string b){
 	sort(a.begin(), a.end());
 	sort(b.begin(), b.end());
 	return a==b;
}
bool both(string a, string b){
	for(int i=0;i<b.length();i++){
		int index =a.find(b[i]);
		if(index==-1){
			return false;
		}
		a[index]='#';
	}
	return true;
}
bool automaton(string a,string b){
	int j=0;
	for(int i=0;i<a.length()&&j<b.length();i++){
		j+=a[i]==b[j];
	}
	if(j==b.length())
		return true;
	else return false;
}
int32_t main(){
	string s,t;
	cin>>s>>t;
	if(arr(s,t))cout<<"array";
	else if(automaton(s,t))cout<<"automaton";
	else if(both(s,t))cout<<"both";
	else cout<<"need tree";
	return 0;
}