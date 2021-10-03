// https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1


#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int k;
    cin >> k;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int count =0;
    map<int,int> m;
    for(int i=0;i<n;i++) m[a[i]]++;
    for(int i=0;i<n;i++){
        // adding m[k-a[i]] to count if m[k-a[i]] is present in the map and m[k-a[i]] is not equal to a[i]
        if(m[k-a[i]]) count+=m[k-a[i]];
        // duplicate elements are counted twice
        if(k-a[i]==a[i]) count--;
    }
    count = count/2;
    cout << count<<endl;
    return 0;
}