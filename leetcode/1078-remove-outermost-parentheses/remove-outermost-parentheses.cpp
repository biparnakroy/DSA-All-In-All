class Solution {
public:
    string removeOuterParentheses(string s) {
        string temp="";
        string res="";
        int op_cnt=0;
        int cl_cnt=0;
        for(auto x:s){
            temp+=x;
            if(x=='(') op_cnt++;
            if(x==')') cl_cnt++;
            if(op_cnt==cl_cnt){
                temp=temp.substr(1,temp.size()-2);
                res+=temp;
                temp="";
            }
        }
        return res;
    }
};