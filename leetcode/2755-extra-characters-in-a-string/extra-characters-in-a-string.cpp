class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        
        // Create a set for quick lookup of words in the dictionary
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        
        // DP array where dp[i] represents the minimum extra characters in s[0:i]
        vector<int> dp(n + 1, 0);
        
        // Iterate through each character of the string s
        for (int i = 1; i <= n; ++i) {
            // Initialize dp[i] as the worst case (i.e., all characters in s[0:i] are extra)
            dp[i] = dp[i - 1] + 1;
            
            // Try every possible start index j of the substring s[j:i]
            for (int j = 0; j < i; ++j) {
                string sub = s.substr(j, i - j);
                
                // If the substring s[j:i] exists in the dictionary, update dp[i]
                if (dict.find(sub) != dict.end()) {
                    dp[i] = min(dp[i], dp[j]);
                }
            }
        }
        
        // Return the minimum number of extra characters in the entire string s
        return dp[n];
    }
};