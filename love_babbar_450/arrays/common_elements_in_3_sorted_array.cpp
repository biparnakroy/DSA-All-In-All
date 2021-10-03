// https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n1,n2,n3;
    cin >> n1>>n2>>n3;
    int a[n1],b[n2],c[n3];
    for(int i=0;i<n1;i++) cin >> a[i];
    for(int i=0;i<n2;i++) cin >> b[i];
    for(int i=0;i<n3;i++) cin >> c[i];
    sort(a,a+n1);
    sort(b,b+n2);
    sort(c,c+n3);
    int i=0,j=0,k=0;
    while(i<n1 && j<n2 && k<n3){
        if(a[i]==b[j] && b[j]==c[k]){
            cout<<a[i]<<endl;
            i++;
            j++;
            k++;
        }
        else if(a[i]<b[j]) i++; // move towards the bigger element
        else if(b[j]<c[k]) j++;
        else k++;
    }
    return 0;
}