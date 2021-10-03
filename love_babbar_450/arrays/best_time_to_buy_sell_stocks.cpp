// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Buys and sell stocks with infinite transactions : peak valley method (buy for peak, sell for valley)
// solution : https://www.youtube.com/watch?v=HWJ9kIPpzXs&t=779s

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int profit = 0;
    for(int i =1;i<n;i++){
        if(a[i]>a[i-1]){
            profit += a[i]-a[i-1];
        }
    }
    cout << profit<<endl;
    return 0;
}