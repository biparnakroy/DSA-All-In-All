/*
https://www.geeksforgeeks.org/find-minimum-number-of-merge-operations-to-make-an-array-palindrome/
Technique : Sliding Window
Solution : https://www.youtube.com/watch?v=ls3EKAm8Vok
*/

#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int min_ops=0;
    int i=0,j=n-1;
    while(i<=j){
        // if first and last are equal then no merge
        if(a[i]==a[j]){
            i++; j--;
        }
        // if first char in large then to equalise last two chars needs to be merged and vice versa
        else if(a[i]>a[j]){
            a[j-1]+=a[j];
            j--; min_ops++;
        }
        else{
            a[i+1]+=a[i];
            i++; min_ops++;
        }
    }

    cout<<min_ops<<endl;
    return 0;
}