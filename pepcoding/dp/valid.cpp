#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n=s.length();
    stack<char> st;
    for(int i=0;i<n;i++){
        if(s[i]=='('|| s[i]=='['|| s[i]=='{'){
            st.push(s[i]);
            cout<<st.top()<<endl;
        }

        else if(( s[i]==')' || s[i]==']'||s[i]=='}' ) && st.empty()==true){
            st.push(s[i]);
        }
        else if(!(st.top()== '(' && s[i]==')' ) ||(st.top()== '[' && s[i]==']')|| (st.top()=='{' && s[i]=='}')){
            st.push(s[i]);
        }
        else{
            if((st.top()== '(' && s[i]==')' ) ||(st.top()== '[' && s[i]==']')|| (st.top()=='{' && s[i]=='}')){
                st.pop();
            }
        }
    }
    if(st.empty()==true){
        cout<<"true"<<endl;
        }
    else
        cout<<"false"<<endl;
    return 0;
}
