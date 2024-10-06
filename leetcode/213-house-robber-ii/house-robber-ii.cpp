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
        vector<int> temp1, temp2;
        for(int i =0;i<nums.size();i++){
            if(i==0){
                temp2.push_back(nums[i]);
            }
            else if(i==nums.size()-1){
                temp1.push_back(nums[i]);
            }
            else{
                temp1.push_back(nums[i]);
                temp2.push_back(nums[i]);
            }
        }
        int res1 = 0;
        memset(dp, -1, sizeof(dp));
        res1 = help(temp1, temp1.size()-1);

        int res2 = 0;
        memset(dp, -1, sizeof(dp));
        res2 = help(temp2, temp2.size()-1);
        return max(res1,res2);
    }
};