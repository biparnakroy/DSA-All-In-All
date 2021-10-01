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
    int i = 0, j = 0, k = 0;
    while(i < n && j < m){
        if(arr1[i] < arr2[j]){
            arr1[k++] = arr1[i++];
        }
        else{
            arr1[k++] = arr2[j++];
        }
    }
    while(i < n){
        arr1[k++] = arr1[i++];
    }
    while(j < m){
        arr1[k++] = arr2[j++];
    }
    for(int i = 0; i < n; i++){
        cout << arr1[i] << " ";
    }
    for(int i = 0; i < m; i++){
        cout << arr2[i] << " ";
    }
    cout<<endl;
    return 0;
}
