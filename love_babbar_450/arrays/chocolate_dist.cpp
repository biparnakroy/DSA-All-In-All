/*
https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1
Solution : https://www.youtube.com/watch?v=T_2CATt_XyQ / https://www.youtube.com/watch?v=50nn3bA1BT4
Technique : Sliding window (fixed size)
Algo : sort then sliding window of size m : check the difference of first and last element of each window and return minimum val of difference
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int m;
    cin>>m;
    sort(a,a+n);
    int gap = a[m-1]-a[0];
    for(int i=1;i+m-1<n;i++){
        gap=min(gap,a[m-1+i]-a[i]);
    }
    cout<<gap<<endl;
    return 0;
}