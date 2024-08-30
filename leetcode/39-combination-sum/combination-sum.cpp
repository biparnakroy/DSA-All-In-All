class Solution {
public:
    void help(vector<int>&candidates,int target,vector<int>&list, vector<vector<int>>&res, int idx){
        if(target == 0){
            res.push_back(list);
            return;
        }
        if(target<0 || idx >=candidates.size()) return;
        list.push_back(candidates[idx]);
        help(candidates,target-candidates[idx],list,res,idx);
        list.pop_back();
        help(candidates,target,list,res,idx+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int>list;
        help(candidates, target,list,res, 0);
        return res;
    }
};