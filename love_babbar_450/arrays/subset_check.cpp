//https://practice.geeksforgeeks.org/problems/array-subset-of-another-array2317/1
// Technique : Hashing

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n1,n2;
    cin>>n1>>n2;
    int a[n1];
    for(int i=0;i<n1;i++) cin>>a[i];
    int b[n2];
    for(int i=0;i<n2;i++) cin>>b[i];
    unordered_map<int,int> m;
    for(int i=0;i<n2;i++){
        m[b[i]]=1;
    }
    for(int i=0;i<n1;i++){
        if(m.find(a[i])!=m.end()){
            m[a[i]]=0;
        }
    }
    bool flag = true;
    for(auto x:m){
        if(x.second==1)
            flag=false;
    }
    // for(auto x:m) cout<<" ("<<x.first<<","<<x.second<<") ";
    if(flag==true) cout<<"yes"<<endl;
    else cout<<"no"<<endl;

    return 0;
}