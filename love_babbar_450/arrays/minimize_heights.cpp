//https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1
// Minimize the heights of the buildings in a skyline.
// Soluiton:  https://www.youtube.com/watch?v=o9WG7t6EKZo


#include <bits/stdc++.h>
using namespace std;

int main(){
    int k;
    cin >> k;
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
   
    sort(arr, arr+n);
    int max_ele, min_ele;
    int res = arr[n-1]-arr[0];
    for(int i = 1; i <=n-1; i++){
        // arr[i-1]=x; probable boro element
        // arr[i]=y; probable choto element
        // res = y-x
        // choto ke barao boro ke komao
        if(arr[i]>=k){
            max_ele =max(arr[i-1]+k, arr[n-1]-k);
            min_ele = min(arr[0]+k,arr[i]-k);
            res = min(res, max_ele-min_ele);
        }
    }
    cout << res << endl;
    return 0;
}