class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, r = 0;
        int len = 0, maxlen=0;
        int n = s.size();
        int hash[256];
        memset(hash, -1, sizeof(hash));
        while(r<n){
            if(hash[s[r]]!=-1){
                if(hash[s[r]]>=l){
                    l=hash[s[r]]+1;
                }
            }
            len = r-l+1;
            maxlen= max(maxlen,len);
            hash[s[r]]=r;
            r++;
        }
        return maxlen;
    }
};