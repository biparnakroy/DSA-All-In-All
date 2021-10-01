// Reverse an array

#include <bits/stdc++.h>
using namespace std;

void rev(int a[],int n){

    int left=0;
    int right=n-1;

    while(left<=right){
        swap(a[left++],a[right--]);
    }
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];

    rev(a,n);

    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}