/* https://practice.geeksforgeeks.org/problems/subarray-with-0-sum/0
 solution : https://www.youtube.com/watch?v=_yGf2rxwZlA&t=756s (this one check)

    variants
    --> Max length subarray with sum 0
    --> count subarray with sum 0
    --> find subarray with sum 0
    --> find all subarray with sum 0
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    unordered_map<int,int> m;
    m[0]=-1;
    int sum=0;
    int i=-1;
    while(i<n){
        i++;
        sum+=a[i];
        if(m.find(sum)==m.end()) m[sum]=i;
        else{
            cout<<i-m[sum]<<" "<<m[sum]+1<<endl;
            return 0;
        }
    }


    
    return 0;
}