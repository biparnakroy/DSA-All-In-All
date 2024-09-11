class Solution {
public:
    int help(vector<int>& prices, int idx, int buy, int k,
             vector<vector<vector<int>>>& dp) {
        if (idx >= prices.size())
            return 0;
        if (k == 0)
            return 0;
        if (dp[idx][buy][k] != -1)
            return dp[idx][buy][k];

        int profit = 0;
        if (buy) {
            profit = max(-prices[idx] + help(prices, idx + 1, 0, k, dp),
                         0 + help(prices, idx + 1, 1, k, dp));
        } else {
            profit = max(+prices[idx] + help(prices, idx + 1, 1, k - 1, dp),
                         0 + help(prices, idx + 1, 0, k, dp));
        }
        return dp[idx][buy][k] = profit;
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(
            prices.size(), vector<vector<int>>(2, vector<int>(3, -1)));
        return help(prices, 0, 1, 2, dp);
    }
};