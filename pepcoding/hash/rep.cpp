#include <bits/stdc++.h>
using namespace std;

int solution(string &s)
{
    int n=s.length();
    
    unordered_map<char,int> m;
    
    for(int i=0;i<n;i++){
        m[s[i]]++;
    }
    
    for(int i=0;i<n;i++){
        if(m[s[i]]==1)
            return i;
    }
    
    return -1;
}

int main()
{
    string s;
    cin >> s;
    solution(s);
    return 0;
}