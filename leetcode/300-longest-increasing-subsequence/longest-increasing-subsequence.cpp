class Solution {
private:
    int f(int i, vector<int>arr,int prev,vector<vector<int>> &dp){
        //f(i,prev) = length of LIS ending at i with previous element arr[prev]
        //base case
        if(i==arr.size()) return 0;

        if(dp[i][prev+1]!=-1) return dp[i][prev+1];

        //not pick
        int np = 0  + f(i+1,arr, prev, dp);
        //pick
        int p = 0;
        if(prev == - 1 || arr[prev]<arr[i]){
            p = 1 + f(i+1,arr, i,dp);
        }

        return dp[i][prev+1] = max(p, np);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // dp[i] = LIS ending at i
        //dp[0] = 1;
        vector<int>dp(n,1);
        int maxi = 1;
        for(int i =1;i<n;i++){
            for(int j = 0;j<i;j++){
                if(nums[j]<nums[i]){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
            maxi = max(maxi,dp[i]);
        }
        return maxi;
    }
};