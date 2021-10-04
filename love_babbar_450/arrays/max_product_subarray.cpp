/*https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/1


    Slight modification of kadanes algo
    -->keep track of max_subarray_prod_so_far and also min_subarray_prod_so_far
    --> if the current element is negetive swap (max_so_far, min_so_far) basic rule of inequality
    --> res = max(res, max_so_far)
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int max_so_far=a[0], min_so_far=a[0];
    int res=1;
    for(int i=1;i<n;i++){
        if(a[i]<0)
            swap(min_so_far,max_so_far);
        max_so_far=max(a[i],max_so_far*a[i]);
        min_so_far=min(a[i],min_so_far*a[i]);
        res=max(res,max_so_far);
    }
    cout<<res<<endl;
    return 0;
}