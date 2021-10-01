//https://practice.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1
//ROTATE AN ARRAY BY D


#include <bits/stdc++.h>
using namespace std;

void reverse(int arr[], int start, int end){
    while(start < end){
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int d;
    cin >> d;
    reverse(arr, 0, d-1);
    reverse(arr, d, n-1);
    reverse(arr, 0, n-1);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout<<endl;
    return 0;
}