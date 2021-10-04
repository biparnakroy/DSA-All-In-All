//https://practice.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1
// Solution : https://www.youtube.com/watch?v=onLoX6Nhvmg
// Time : 0(n2)
// Note: there is a better way of doing this question using hashing

#include <bits/stdc++.h>
using namespace std;
int two_sum(int a[],int low,int high, int k){
    int count=0;
    while(low<high){
        if(a[low]+a[high]<k)
            low++;
        else if(a[low]+a[high]==k){
            return 1;

        }
        else{
            high--;
        }

    }
    return 0;
}
int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    int count=0;
    for(int i=0;i<n;i++){
        int rest=k-a[i];
        count += two_sum(a,i+1,n-1,rest);
    }
    cout<<count<<endl;
    return 0;
}