//https://www.geeksforgeeks.org/find-minimum-number-of-merge-operations-to-make-an-array-palindrome/
// Basically merge the two arrays 

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int b[n];
    for(int i=0;i<n;i++) cin>>b[i];

    int i=n-1,j=0;
    while(i>=0 && j<n){
        if(a[i]>b[j]){
            swap(a[i],b[j]);
            i--;j++;
        }
        else break;
    }
    sort(a,a+n);
    sort(b,b+n);
    // for(int i=0;i<n;i++) cout<<a[i]<<" ";
    // cout<<endl;
    // for(int i=0;i<n;i++) cout<<b[i]<<" ";

    int median=(a[n-1]+b[0])/2;
    cout<<median<<endl;
    return 0;
}
