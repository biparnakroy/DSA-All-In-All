#include <bits/stdc++.h>
using namespace std;
#define int long long int
int32_t main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t-->0){
        int n;
        cin>>n;
        vector<int> v1,v2;
        set<int> s1;
        int sum_a=0,sum_b=0;
        for(int i=0;i<n;i++){
            int t;
            cin>>t;
            v1.push_back(t);
            sum_a+=t;
        }
        for(int i=0;i<n-1;i++){
            int t;
            cin>>t;
            v2.push_back(t);
            s1.insert(t);
            sum_b+=t;
        }
        
        int res=INT_MAX;
        for(int i=0;i<n;i++){
            int  subsum=sum_b-sum_a+v1[i];
            if(subsum%(n-1)==0){
                int x=subsum/(n-1);
                int mis= v1[i]+x;
                if(s1.find(x)==s1.end()){
                    res=min(res,abs(x));
                }
            }
        }
        cout<<res<<endl;
    }
	return 0;
}