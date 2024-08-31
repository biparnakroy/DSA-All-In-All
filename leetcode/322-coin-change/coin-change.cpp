class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // DP array to store the minimum coins for each amount up to the target
        // amount
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0; // Base case: 0 coins needed to make amount 0

        // Fill the dp array
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (i - coin >= 0 && dp[i - coin] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        // If dp[amount] is still INT_MAX, it means amount cannot be formed with
        // given coins
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};