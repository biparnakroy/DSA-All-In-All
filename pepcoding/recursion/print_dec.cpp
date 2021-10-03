#include <bits/stdc++.h>
using namespace std;

void printDecreasing(int n){
    // write your code here
    if(n==0)
        return;
    cout<<n--<<endl;
    printDecreasing(n);
    
}

int main(){
    int n;
    cin >> n;
    printDecreasing(n);
}
