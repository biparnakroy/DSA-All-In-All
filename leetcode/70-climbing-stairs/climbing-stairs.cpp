class Solution {
public:
    int f(int n, vector<int>& dp) {
        if (n == 0) {
            return 1;
        }
        if (n == -1) {
            return 0;
        }

        if (dp[n] != -1)
            return dp[n];

        int t1 = f(n - 1, dp);
        int t2 = f(n - 2, dp);

        return dp[n] = t1 + t2;
    }
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return f(n, dp);
    }
};