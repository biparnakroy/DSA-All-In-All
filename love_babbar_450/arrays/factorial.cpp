/*
https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers/0
--> implementation of how we multiply manually 
*/
#include <bits/stdc++.h>
using namespace std;

void multiply(vector<int> &v, int multiply_sum){
    int carry = 0;
    for (int i = 0; i < v.size(); i++)
    {
        int prod = v[i] * multiply_sum + carry;
        v[i] = prod % 10;
        carry = prod / 10;
    }
        
    while (carry > 0)
    {
        int curr_carry = carry%10;
        v.push_back(curr_carry);
        carry /= 10;
    }   
}

void factorial(vector<int> &res,int n){
    for(int i = 2; i <= n; i++){
        multiply(res, i);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> res(0);
    res.push_back(1);
    factorial(res,n);
    reverse(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
    }
    cout << endl;
    return 0;
}