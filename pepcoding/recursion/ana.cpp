#include <bits/stdc++.h>
using namespace std;

string remdup(string s){
    string ans;
    for(int i=0;i<s.size();i++){
        if(ans.size()==0 || ans.back()!=s[i])
            ans.push_back(s[i]);
    }
    return ans;
}

int main()
{
    vector<string> s;
    s = {"may", "student", "students", "dog",
         "studentssess", "god", "cat", "act",
         "tab", "bat", "flow", "wolf", "lambs",
         "amy", "yam", "balms", "looped",
         "poodle"};

    unordered_map<string, vector<string>> m;

    for(auto x:s){
        string t = x;
        sort(t.begin(), t.end());
        t = remdup(t);
        m[t].push_back(x);
    }

    for(auto x:m){
        for(auto y:x.second){
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}