#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define MAXN 100000

int32_t main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,x,y;cin>>n;
    cin>>x;
    int k;
    set<int> levels;
	for(int i=0;i<x;i++){
        cin>>k;
        levels.insert(k);
    }
    cin>>y;
    for(int i=0;i<y;i++){
        cin>>k;
        levels.insert(k);
    }
    if(levels.size()==n)cout<<"I become the guy.";
    else cout<<"Oh, my keyboard!";
    return 0;
}