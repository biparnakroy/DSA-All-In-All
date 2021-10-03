#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int lis[n];
    memset(lis,0,sizeof(lis));
    
    lis[0]=1;
    
    for(int i=1;i<n;i++){
        int max_lis=0;
        for(int j=0;j<i;j++){
            if(a[j]<=a[i]){
                max_lis=max(max_lis,lis[j]);
            }
            lis[i]=1+max_lis;
        }
    }
    
    int lds[n];
    memset(lds,0,sizeof(lds));
    lds[n-1]=1;
    
    for(int i=n-2;i>=0;i--){
        int max_lds=0;
        for(int j=n-1;j>i;j--){
            if(a[j]<=a[i]){
                max_lds=max(max_lds,lds[j]);
            }
            lds[i]=1+max_lds;
        }
    }
    
    int res[n];
    
    for(int i=0;i<n;i++){
        res[i]=lis[i]+lds[i]-1;
    }
    int ans=INT_MIN;
    
    for(auto x:res){
        ans=max(ans,x);
    }
    
    cout<<ans<<endl;
    
    return 0;
}