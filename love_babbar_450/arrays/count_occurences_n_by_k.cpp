/*
    https://practice.geeksforgeeks.org/problems/count-element-occurences/1
    Time : O(n)
    Space: O(n)
    Technique : Hashing
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    cin>>k;
    unordered_map<int,int> m;

    for(int i=0;i<n;i++) m[a[i]]++;
    int count =0;
    for(auto x:m){
       if(x.second>(n/k)){
           count++;
       }
    }
    cout<<count<<endl;
    return 0;
}