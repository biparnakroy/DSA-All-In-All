// https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1
// Dutch three flag algo
// 0 0 0 1 1 1 ? ? ? ? 2 2 2 2 
// 0   l     m         h   

#include <bits/stdc++.h>
using namespace std;

void sort012(int a[],int n){
    int low=0;
    int mid=0;
    int high=n-1;
    while(mid<=high){
        switch(a[mid]){
            case 0: swap(a[low++],a[mid++]); 
            break;
            case 1: mid++;
            break;
            case 2: swap(a[mid],a[high--]);
            break;
        }
    }
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];

    sort012(a,n);

    for(int i=0;i<n;i++) cout<<a[i]<<" ";

    cout<<endl;

    return  0;
}
