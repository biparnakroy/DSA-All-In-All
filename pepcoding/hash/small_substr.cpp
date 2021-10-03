#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    string pat;
    cin >> pat;
    int m = pat.size();

    unordered_map<char, int> mp;
    int i=-1, j=-1;
    int k=0;
    while(true){
        bool f1 = false, f2 = false;
        while(i<n-1){
            f1 = true;
            i++;
            if(s[i]==pat[k] && mp.find(s[i])==mp.end()){
                mp[s[i]]++;
                k++;
            }
            else if(s[i]==pat[k] && mp.find(s[i])!=mp.end()){
                mp[s[i]]++;
                break;
            }
        }
        while(j<i){
            f2 = true;
            j++;
            if(s[j]==pat[k] && mp.find(s[j])!=mp.end()){
                if(mp[s[j]]==1){
                    mp.erase(s[j]);
                }
                mp[s[j]]--;
            }
            if(mp.size()==m){
                break;
            }

        }
        if(f1 && f2){
            break;
        }
    }

    return 0;
}