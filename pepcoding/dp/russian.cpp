#include <bits/stdc++.h>
using namespace std;

struct env{
    int l;
    int w;
};

env make_env(int l, int w){
    env e;
    e.l=l;
    e.w=w;
    return e;
}

bool comp(env &a, env &b){
    return a.l<b.l;
}

int main(){
    int n;
    cin>>n;
    vector<env> en;
    for(int i=0;i<n;i++){
        int l,w;
        cin>>l>>w;
        en.push_back(make_env(l,w));
    }
    cout<<endl;
    sort(en.begin(),en.end(),comp);
    // for(auto e:en){
    //     cout<<e.l<<" "<<e.w<<endl;
    // }

    int dp[n];
    memset(dp,0,sizeof(dp));
    
    dp[0]=1;
    // cout<<dp[0]<<endl;  
    
    int ma=INT_MIN;
    for(int i=1;i<n;i++){
        ma=0;
        for(int j=0;j<i;j++){
            if(en[i].w>=en[j].w){
                ma=max(ma,dp[j]);
            }
        }
        dp[i]=1+ma;
    }

    // for(int i=0;i<n;i++){
    //     cout<<dp[i]<<endl;
    // }
    
    cout<<dp[max_element(dp,dp+n)-dp]<<endl;
    
    return 0;
}