#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define MAXN 100000

int32_t main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s; getline(cin,s);
    set<char> st;
    for(int i=0;i<s.size();i++){
        st.insert(s[i]);
    }
    int count=0;
    for(auto x:st){
        if(x!=','&&x!='{'&&x!='}'&&x!=' ')count++;
    }
    cout<<count;
	return 0;
}