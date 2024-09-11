class Solution {
public:
    int help(vector<int>& prices, int idx, int buy, vector<vector<int>>& dp) {
        if (idx >= prices.size())
            return 0;
        if (dp[idx][buy] != -1)
            return dp[idx][buy];
        int profit = 0;

        if (buy) {
            profit = max(-prices[idx] + help(prices, idx + 1, 0, dp),
                         0 + help(prices, idx + 1, 1,dp));

        } else {
            profit = max(prices[idx] + help(prices, idx + 1, 1,dp),
                         0 + help(prices, idx + 1, 0,dp));
        }
        return dp[idx][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        int res = help(prices, 0, 1, dp);
        return res;
    }
};