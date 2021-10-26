//https://www.geeksforgeeks.org/median-of-two-sorted-arrays/
// solution : https://www.youtube.com/watch?v=FyJmnhqATko
// Approach 1 : Basically merge the two arrays 
// Approach 2 : Divide and conquer log n

#include <bits/stdc++.h>
using namespace std;

//dive and conquer
void median(int a[],int n){
    
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int b[n];
    for(int i=0;i<n;i++) cin>>b[i];

    int m1= -1, m2 =-1;
    int i=0,j=0;
    int count = 0;
    
    while(count <=n){
        if(i==n){
            m1=m2;
            m2=b[0];
            break;
        }
        else if(j==n){
            m1=m2;
            m2=a[0];
            break;
        }
        if(a[i]<=b[i]){
            m1=m2;
            m2=a[i];
            i++;
            count++;
        }
        else{
            m1=m2;
            m2=b[j];
            j++;
            count++;
        }
    }
    int median = (m1+m2)/2;
    cout<<m1<<" "<<m2<<endl;
    cout<<median<<endl;
    return 0;
}
