#include<bits/stdc++.h>
using namespace std;
int main(){
    string s,p;
    cin>>s>>p;
    string big_s=s+s;
    // int n=s.size(),m=p.size();
    // for(int i=0;i<n-m+1;i++){
    //     if(p.compare(s.substr(i,m))==0){
    //         cout<<i<<" ";
    //     }
    // }
    for(int i=0;i<s.length();i++){
        cout<<big_s.substr(i,s.length())<<endl;
    }
    return 0;
}