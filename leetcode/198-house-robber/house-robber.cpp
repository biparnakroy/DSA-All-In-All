class Solution {
private:
    int dp[101];
    int help(vector<int>& nums, int idx){
        if(idx == 0) return nums[0];
        if(idx < 0) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int pick = nums[idx]  + help(nums,idx-2);
        int not_pick = 0  + help(nums, idx-1);
        return dp[idx]=max(pick, not_pick);
    }
public:
    int rob(vector<int>& nums) {
        int res = 0;
        memset(dp, -1, sizeof(dp));
        res = help(nums, nums.size()-1);
        return res;
    }
};