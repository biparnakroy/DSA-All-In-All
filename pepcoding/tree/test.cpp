#include <bits/stdc++.h>
using namespace std;

int no_FirstVowels(string s){
    int v=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
            v++;
    }
    return v;
}

int main(){
     int t=0;
     cin>>t;
     while(t-->0){
         int n;
         cin>>n;
         string s;
         cin>>s;
         int vowels=0;
         for(int i=0;i<s.length();i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
                vowels++;
         }
        
         string big_s= s;
         reverse(s.begin(),s.end());
         big_s=big_s+s.substr(1);
         int c=0;

         for(int i=0;i<big_s.length();i++){
             int v1=no_FirstVowels(big_s.substr(i,i+s.length()));
             int v2=vowels-v1;
             if(v1>v2)
                 c++;
         }
         cout<<c<<"\n";
     }
}
