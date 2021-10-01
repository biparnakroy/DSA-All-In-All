// https://practice.geeksforgeeks.org/problems/union-of-two-arrays3538/1
// UNION AND INTERSECTRION OF TWO SORTED ARRAYS
/* Approaches 

    -> hashing
    -> two pointer

*/
#include <bits/stdc++.h>
using namespace std;

void print_union(int a[],int b[],int n, int m){
    int i=0;
    int j=0;
    while(i<n && j<m){
        if(a[i]<b[j])
            cout<<a[i++]<<" ";
        else if(a[i]>b[j])
            cout<<b[j++]<<" ";
        else{
            cout<<b[j++]<<" ";
            i++;
        }
    }
    //print remaining
    while(i<n)
    cout<<a[i++]<<" ";
    while(j<m)
    cout<<b[j++]<<" ";

    cout<<endl;
}

void print_intersection(int a[],int b[],int n,int m){
    int i=0;
    int j=0;
    while(i<n && j<m){
        if(a[i]<b[j])
           i++;
        else if(a[i]>b[j])
           j++;
        else{
            cout<<b[j++]<<" ";
            i++;
        }
    }
    cout<<endl;
}

int main(){
    int n,m;
    cin>>n>>m;
    int a[n];
    int b[m];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    print_union(a,b,n,m);
    print_intersection(a,b,n,m);
    return 0;
}




                                      