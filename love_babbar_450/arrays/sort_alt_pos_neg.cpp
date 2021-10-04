// https://www.geeksforgeeks.org/rearrange-array-alternating-positive-negative-items-o1-extra-space/
/*
  Two variants :
    1) order matters : 
    2) order doesn't matter : : https://www.youtube.com/watch?v=zUPMACE0uBs&list=PLPyD8bF-abzszl5o0RUBkx7JW07wbHqgg&index=13

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;
// here order is not maintained 
void pos_neg_alt(int a[],int n){
    // separate positive and negative numbers
    int i=0,j=n-1;
    while(i<j){
        while(a[i]<0 && i<j) i++;
        while(a[j]>=0 && i<j) j--;
        if(i<j){
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }
    // i is the index of the last negative number

    // if only negetive or only positive numbers
    if(i==0 || i==n-1) return;

    // alternate positive and negative numbers
    int k=0;
    while(k<n && i<n){
        swap(a[k],a[i]);
        k+=2;
        i++;
    }
}


int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    pos_neg_alt(arr,n);
    for(int i=0;i<n;i++)cout<<arr[i]<<" ";
    cout<<endl;
    return 0;   
}