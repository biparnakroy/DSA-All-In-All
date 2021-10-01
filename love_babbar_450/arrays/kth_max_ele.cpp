//https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    
    int k;
    cin>>k;
    int copy=k;

    priority_queue<int> q;

    for(int i=0;i<n;i++){
        q.push(a[i]);
    }

    
    while(k-->1){
        q.pop();
    }

    cout<<"kth max: "<<q.top()<<endl;

    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=0;i<n;i++){
        pq.push(a[i]);
    }

    while(copy-->1){
        pq.pop();
    }

    cout<<"kth min: "<<pq.top()<<endl;

    return 0;
}
