/*
https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together4847/1

Technique : sliding window (fixed size)
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int k;
    cin>>k;
    int good=0;
    for(int i=0;i<n;i++) if(a[i]<=k) good++;
    int bad =0;
    for(int i=0;i<good;i++){
        if(a[i]>k)
            bad++;
    }
    int ans = bad;
    // initital window from 0 to good-1 where ans = bad
    int i=0,j=good;
    while(j<n){
        if(a[i]>k)
            bad--;
        if(a[j]>k)
            bad++;
        ans=min(ans,bad);
        i++;
        j++;
    }
    cout<<ans<<endl;
    return 0;
}