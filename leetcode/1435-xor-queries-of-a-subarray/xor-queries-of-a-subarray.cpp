class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>pre(arr.size(),0);
        vector<int>res;
        pre[0]=arr[0];
        for(int i=1;i<arr.size();i++){
            pre[i] = pre[i-1]^arr[i];
        }
        for(auto &x:queries){
            if(x[0]==0){
                res.push_back(pre[x[1]]);
            }else{
                res.push_back(pre[x[1]]^pre[x[0]-1]);
            }
        }
        return res;
    }
};