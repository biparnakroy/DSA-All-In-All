class Solution {
public:
    const int MOD = 1e9 + 7;

    int profitableSchemes(int G, int P, vector<int>& group,
                          vector<int>& profit) {
        int N = group.size();

        // dp[g][p] represents the number of ways to achieve at least `p` profit
        // with `g` members.
        vector<vector<int>> dp(G + 1, vector<int>(P + 1, 0));

        // There's always 1 way to achieve 0 profit with 0 people (by doing
        // nothing).
        dp[0][0] = 1;

        for (int i = 0; i < N; i++) {
            int members = group[i];
            int crimeProfit = profit[i];

            // We iterate from larger to smaller group size to avoid overwriting
            // results.
            for (int g = G; g >= members; g--) {
                for (int p = P; p >= 0; p--) {
                    // Calculate the new profit after committing the current
                    // crime
                    int newProfit = min(
                        P, p + crimeProfit); // Ensure profit doesn't exceed P

                    dp[g][newProfit] =
                        (dp[g][newProfit] + dp[g - members][p]) % MOD;
                }
            }
        }

        // Sum all schemes that achieve at least `P` profit with any number of
        // members.
        int result = 0;
        for (int g = 0; g <= G; g++) {
            result = (result + dp[g][P]) % MOD;
        }

        return result;
    }
};
