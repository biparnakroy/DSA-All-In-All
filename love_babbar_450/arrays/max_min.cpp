//https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/

#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int max_ele=INT_MIN;
    int min_ele=INT_MAX;

    for(int i=0;i<n;i++){
        max_ele=max(max_ele,a[i]);
        min_ele=min(min_ele,a[i]);
    }

    cout<<"max: "<<max_ele<<" min: "<<min_ele<<endl;
    return 0;
}