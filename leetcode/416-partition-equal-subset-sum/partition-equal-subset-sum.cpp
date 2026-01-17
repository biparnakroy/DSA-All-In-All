class Solution {
private:
    bool f(vector<int>&nums,int i, int t, vector<vector<int>>&dp){
        if(i<0) return false;
        if(t==0) return true;
        if(dp[i][t]!=-1) return (bool) dp[i][t];
        //not pick
        bool np=f(nums,i-1,t,dp);
        // pick
        bool p = false;
        if(nums[i]<=t) p = f(nums,i-1,t-nums[i],dp);
        return dp[i][t]=(int) np || p;
    }
public:
    bool canPartition(vector<int>& nums) {
        int s = 0 ;
        int n = nums.size();
        for(auto x:nums) s+=x;
        vector<vector<int>> dp(n, vector<int>((int)s/2+1, -1));
        if (s % 2 != 0) return false;
        return f(nums,n-1,(int)s/2,dp);

    }
};