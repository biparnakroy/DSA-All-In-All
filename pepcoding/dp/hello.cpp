#include <bits/stdc++.h>
using namespace std;

int main(){
    int a=0;
    int b=1;
    int c=a+b;
    int n;
    cin>>n;

    while(c<=n){
        cout<<c<<endl;
        a=b;
        b=c;
        c=a+b;
    }

    return 0;
}