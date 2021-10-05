/*
https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1
Technique : Kind of DP 
Solution : https://www.youtube.com/watch?v=_qeh8VQCm0A or https://www.youtube.com/watch?v=m18Hntz4go8

*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int left[n];
    left[0]=a[0];
    for(int i=1;i<n;i++){
        left[i]=max(a[i],left[i-1]);
    }
    int right[n];
    right[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--){
       right[i]=max(a[i],right[i+1]);
    }
    int water=0;
    for(int i=0;i<n;i++){
        water += min(left[i],right[i]) - a[i];
    }
    cout<<water<<endl;
    return 0;
}

