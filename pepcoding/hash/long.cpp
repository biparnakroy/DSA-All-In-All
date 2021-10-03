// Longest Subarray With Equal Number Of Zeroes And Ones

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(a[i] == 0) a[i] = -1;
    }
    unordered_map<int,int>m;
    m[0] = -1;
    int max_len = 0;
    int sum=0;
    for(int i = 0; i < n; i++)
    {
        sum += a[i];
        if(m.find(sum) != m.end()){
            max_len = max(max_len, i - m[sum]);
        }
        else m[sum] = i;
    }
    cout << max_len << endl;
    return 0;
}
