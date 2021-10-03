#include <bits/stdc++.h>
using namespace std;

int main(){
    
    string s1,s2;
    cin>>s1>>s2;
    
    int n=s1.length();
    int m=s2.length();
    
    unordered_map<char,int> m1;
    unordered_map<char,int> m2;
    
    int mct=0;
    int dmct=s2.length();
    
    for(int i=0;i<m;i++){
        m2[s2[i]]++;
    }

    int i=-1;
    int j=-1;

    string ans="";

    while(true){
        bool f1=false, f2=false;
        while(i<n-1 && mct<dmct){
            i++;
            m1[s1[i]]++;
            if(m1[s1[i]]<=m2[s1[i]])
                mct++;
            f1=true;
        }
        
        while(j<i && mct==dmct){
            
            string pans=s1.substr(j+1,i+1-j-1);
            // cout<<j+1<<" "<<i+1<<" "<<pans<<endl;
            //cout<<pans<<endl;
            if(ans.length()==0 || pans.length()<ans.length())
                ans=pans;
            j++;
            if(m1[s1[j]]==1)
                m1.erase(s1[j]);
            else
                m1[s1[j]]--;
        
            if(m1[s1[j]]<m2[s1[j]])
                mct--;

            f2=true;
        }
        if(f1==false && f2==false)
            break;
    }
    // cout<<"=============================="<<endl;
    cout<<ans<<endl;
    
    return 0;
}