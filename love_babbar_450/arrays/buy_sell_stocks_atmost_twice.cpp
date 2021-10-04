/*
    https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/buy-sell-stocks-tta-official/ojquestion
    solution : https://www.youtube.com/watch?v=wuzTpONbd-0&list=TLGGyjcZwMrklxEwNDEwMjAyMQ

    Technique : DP
    Note : There are many variants of this buy and sell stock problem, please see pepcoding list

    Shortforms:
    - mpst : max_profit_if_sold_today
    - msf : min so far
    - dpl : dp maximum profit if sold upto today
    - mpbt : maximum profit if bought today
    - maxat : max after today
    - dpr : max profit on the right side wala transaction

    -There is also a OP Peak Valley method to do this question [could not figure out the logic]
    link to the soln:  https://www.geeksforgeeks.org/maximum-profit-by-buying-and-selling-a-share-at-most-twice/

    int maxtwobuysell(int arr[],int size) {
        int first_buy = INT_MIN;
        int first_sell = 0;
        int second_buy = INT_MIN;
        int second_sell = 0;
        
        for(int i=0;i<size;i++) {
            
            first_buy = max(first_buy,-arr[i]);
            first_sell = max(first_sell,first_buy+arr[i]);
            second_buy = max(second_buy,first_sell-arr[i]);
            second_sell = max(second_sell,second_buy+arr[i]);
        
        }
     return second_sell;
    }

*/

#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int mpst =0;
    int msf=a[0];
    int dpl[n];
    dpl[0]=0;
    for(int i=1;i<n;i++){
        if(msf>a[i])
            msf=a[i];
        mpst=a[i]-msf;
        dpl[i]=max(mpst,dpl[i-1]);
    }
    int mpbt =0;
    int maxat = a[n-1];
    int dpr[n];
    dpr[n-1]=0;
    for(int i=n-2;i>=0;i--){
        if(a[i]>maxat)
            maxat = a[i];
        mpbt = maxat-a[i];
        dpr[i]=max(mpbt,dpr[i+1]);
    }
    int net_profit = 0;
    for(int i=0;i<n;i++){
        if(dpl[i]+dpr[i]>net_profit)
            net_profit=dpl[i]+dpr[i];
    }
    cout<<net_profit<<endl;

    return 0;
}


