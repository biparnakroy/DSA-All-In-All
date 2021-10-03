#include<bits/stdc++.h>
using namespace std;
int main(){
	int t=0;
	cin>>t;
	while(t-->0){
		int n=0;
		int q=0;
		cin>>n>>q;
		vector<pair<int,int>> v;
		for(int i=0;i<n;i++){
			int x,y;
			cin>>x>>y;
			v.push_back({x,y});
		}
		sort(v.begin(),v.end());
		int idx=0;
		for(int i=1;i<v.size();i++){
			if(v[idx].second>=v[i].first){
				v[idx].second = max(v[idx].second,v[i].second);
			}
			else{
				idx++;
				v[idx]=v[i];
			}
		}
		while(q-->0){
			int k=0;
			cin>>k;
			int ans=-1;
			for(int i =0;i<=idx;i++){
				int diff=v[i].second-v[i].first+1;
				if(diff>=k)
				{
					ans=v[i].first+k-1;
					break;
				}
				else{
					k=k-diff;
				}
			}
			cout<<ans<<endl;
		}

	}

	return 0;
}