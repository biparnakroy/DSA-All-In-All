// https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays5135/1

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    int arr1[n], arr2[m];
    for(int i = 0; i < n; i++){
        cin >> arr1[i];
    }
    for(int i = 0; i < m; i++){
        cin >> arr2[i];
    }
    int i=n-1,j=0;
    while(i>=0 && j<m)
    {
        if(arr1[i]>arr2[j])
        {
            swap(arr1[i],arr2[j]);
            i--;j++;
        }
        else break;
    }
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);
    for(int i=0;i<n;i++) cout<<arr1[i]<<" ";
    for(int i=0;i<m;i++) cout<<arr2[i]<<" ";
    cout<<endl;
    return 0;
}
