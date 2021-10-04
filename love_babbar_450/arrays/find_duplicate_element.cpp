// https://leetcode.com/problems/find-the-duplicate-number/
// Find the Duplicate Number
// numbers in the array are from 1 to N
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++){
        if(arr[abs(arr[i])-1]<0){
            cout << abs(arr[i]) << endl;
            break;
        }
        arr[abs(arr[i])-1] = - arr[abs(arr[i])-1];
    }
    return 0;
}