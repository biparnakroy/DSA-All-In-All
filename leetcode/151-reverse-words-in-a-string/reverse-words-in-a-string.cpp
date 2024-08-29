class Solution {
public:
    string reverseWords(string s) {
        string res="";
        string word = "";
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                word+=s[i];
            }
            else{
                res = " "+word+res;
                word="";
            }
        }
        res = word+res;
        res.erase(0, res.find_first_not_of(" "));
        res.erase(res.find_last_not_of(" ") + 1);

        //internal space
        string g="";
        int cnt=0;
        for(auto x:res){
            if(x!=' '){
                g+=x;
                cnt=0;
            }else{
                cnt++;
                if(cnt==1)
                    g+=" ";
            }
        }

        return g;
    }
};