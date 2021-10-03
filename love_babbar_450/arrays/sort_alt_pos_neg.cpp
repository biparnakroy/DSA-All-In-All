// https://www.geeksforgeeks.org/rearrange-array-alternating-positive-negative-items-o1-extra-space/
/*
    Algo :
        -> sort
        -> swap alternate pos and neg
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr,arr+n);
    int i=1,j=n-1;
    while(i<j){
        swap(arr[i],arr[j]);
        i+=2;
        j-=2;
    }
    for(int i=0;i<n;i++)cout<<arr[i]<<" ";
    cout<<endl;
    return 0;   
}