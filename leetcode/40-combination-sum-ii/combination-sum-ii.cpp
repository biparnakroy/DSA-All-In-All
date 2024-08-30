class Solution {
public:
    void help(vector<int>&candidates, int target, vector<int>&list,vector<vector<int>>&res,int idx){
        if(target==0){
            res.push_back(list);
            return;
        }
        if(target<0 || idx >= candidates.size()) return;

        list.push_back(candidates[idx]);
        help(candidates, target-candidates[idx],list,res,idx+1);
        list.pop_back();
        //elemination of duplicates
        while(idx < candidates.size()-1 && candidates[idx]==candidates[idx+1]) idx++;
        help(candidates, target,list,res,idx+1);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>list;
        sort(candidates.begin(),candidates.end());
        help(candidates,target,list,res,0);
        return res;
    }
};