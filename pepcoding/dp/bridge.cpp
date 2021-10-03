#include <bits/stdc++.h>
using namespace std;

struct bridge{
    int n;
    int s;
};

bridge make_bridge(int n,int s){
    bridge b;
    b.n=n;
    b.s=s;
    return b;
}

bool comp(bridge &a, bridge &b){
    if(a.n==b.n)
        return a.s<b.s;
    return a.n<b.n;
}

int main(){
    int n;
    cin>>n;
    vector<bridge> bri;
    for(int i=0;i<n;i++){
        int nor, sou;
        cin>>nor>>sou;
        bri.push_back(make_bridge(nor,sou));
        
    }
    
    sort(bri.begin(),bri.end(),comp);

    for(auto x:bri){
        cout<<x.n<<" "<<x.s<<endl;
    }

    int dp[n];
    memset(dp,0,sizeof(dp));
    
    dp[0]=1;
    
    for(int i=1;i<n;i++){
        int max_ss=0;
        for(int j=0;j<i;j++){
            if(bri[j].s<=bri[i].s)
                max_ss=max(max_ss,dp[j]);
        }
        
        dp[i]=1+max_ss;
    }
    
    int res=INT_MIN;
    for(int i=0;i<n;i++){
        res=max(res,dp[i]);
    }
    cout<<res<<endl;
    
    return 0;
}


// 10
// 10 20
// 2 7
// 8 15
// 17 3
// 21 40
// 50 4
// 41 57
// 60 80
// 80 90
// 1 30