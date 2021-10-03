#include <bits/stdc++.h>
using namespace std;
void solve(int a[],int n, unordered_map<int,int>m,int k){
    if(m[0]%2!=0){
        cout<<"false"<<endl;
        return;
    }

    
    
    for(int i=0;i<n;i++){
        if(a[i]%k!=0){
            if(m[a[i]%k]!=m[k-a[i]%k]){
                cout<<"false"<<endl;
                return;
            }
        }
    }
    
    cout<<"true"<<endl;
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int k;
    cin>>k;
    
    unordered_map<int,int> m;
    
    for(int i=0;i<n;i++){
        m[a[i]%k]++;
        //cout<<a[i]%k<<" "<<m[a[i]%k]<<endl;
    }
    
    // for(auto x:m){
    //     cout<<x.first<<" "<<x.second<<endl;
    // }
    solve(a,n,m,k);
    
   
    return 0;
    
}