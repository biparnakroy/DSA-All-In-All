/*
https://practice.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x5651/1
Technique : Sliding window (variable size) [ kind of like aquire release strategy of sumeet mallick sir]    
    --> aquire till the current sum is just greater than x
    --> start releasing till the current sum remains greater than x 
Solution : https://www.youtube.com/watch?v=21tQXPbGg7k / https://www.youtube.com/watch?v=nYvx3kRl9eU
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    cin>>n>>x;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int curr_sum=0, min_length=n+1;
    int i=0,j=0;
    while(j<n){
        while(curr_sum<=x)
            curr_sum+=a[j++];
        while(curr_sum > x && i<j){
            min_length=min(min_length,j-i);
            curr_sum-=a[i++];
        }
    }
    cout<<min_length<<endl;
    return 0;
}