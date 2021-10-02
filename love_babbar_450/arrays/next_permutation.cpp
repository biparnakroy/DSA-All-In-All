/* https://leetcode.com/problems/next-permutation/

solution: https://www.youtube.com/watch?v=LuLCLgMElus&t=24s
 Algorithm: 

1. traverse from right to left and check if a[i]<a[i+1] and let i be index1.
    -> if not found, reverse the array and return.
2. now again traverse from right to left and check if a[index1]<a[i] and let i be index2,
3. if found, swap a[index1] and a[index2]
3. reverse(index1+1,n)
*/
#include <bits/stdc++.h>
using namespace std;

void next_perm(int a[],int n){
    int index1 = -1;
    for(int i=n-2;i>=0;i--){
       if(a[i]<a[i+1]){
           index1 = i;
           break;
       }
   }
    if(index1==-1){
         reverse(a,a+n);
         return;
    }
    int index2 = -1;
    for(int i=n-1;i>=0;i--){
        if(a[index1]<a[i]){
            index2 = i;
            break;
        }
    }
    swap(a[index1],a[index2]);
    reverse(a+index1+1,a+n);
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    next_perm(a,n);
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout<<endl;
    return 0;
}