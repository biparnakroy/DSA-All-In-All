/*
https://practice.geeksforgeeks.org/problems/three-way-partitioning/1
Algo : same as 012 partitioning
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int a,b;
    cin>>a>>b;
    int low=0;
    int mid=0;
    int high=n-1;
    while(mid<=high){
            if (arr[mid]<a) swap(arr[low++],arr[mid++]); 
            else if(arr[mid]>=a && arr[mid]<=b) mid++;
            else swap(arr[mid],arr[high--]);
    }
    
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;

    return 0;
}