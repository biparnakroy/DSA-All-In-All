// https://www.geeksforgeeks.org/move-negative-numbers-beginning-positive-end-constant-extra-space/
// TWO POINT : SEPARATE POSITIVE NEGETIVE ELEMENTS IN AN ARRAY INPLACE

#include <bits/stdc++.h>
using namespace std;

void sort_neg_pos(int a[],int n){
    int low=0;
    int high=n-1;
    while(low<=high){
        if(a[low]<0 && a[high]<0)
            low++;
        else if(a[low]>0 && a[high]<0){
            swap(a[low++],a[high--]);
        }
        else if(a[low]>0 && a[high]>0)
            high--;
        else{
            low++;
            high--;
        }
    }
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    sort_neg_pos(a,n);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}